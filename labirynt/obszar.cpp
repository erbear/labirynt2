#include "StdAfx.h"
#include "obszar.h"


Obszar::Obszar()
{
	sciana = new int[2]; // tworzenie tablicy sciana
	wspolrzedna = new int [8]; //tworzenie tablicy wspolrzednych
	//ustalanie domyslnego koloru
	kolor[0] = 255;
	kolor[1] = 255;
	kolor[2] = 153;
	zajety = 0;
}


Obszar::~Obszar()
{
	delete []sciana;
	delete []wspolrzedna;
}
void Obszar::ustawSciane(int ktora)
{
	sciana[ktora]=1;
}
int Obszar::czySciana(int ktora)
{
	return sciana[ktora];
}
void Obszar::usunSciane(int ktora)
{
	sciana[ktora]=0;
}
void Obszar::ustawWspolrzedne(int x, int y, int bok)
{
	//lewy gorny wierzcholek
	wspolrzedna[0] = x;
	wspolrzedna[1] = y;

	x+=bok;//przesuniecie x w prawo o bok kwadratu
	
	//prawy gorny wierzcholek
	wspolrzedna[2] = x;
	wspolrzedna[3] = y;
	
	y+=bok;//przesuniecie y w dol o bok kwadratu

	//prawy dolny wierzcholek
	wspolrzedna[4] = x;
	wspolrzedna[5] = y;
	
	x-=bok;// przesuniecie x w lewo o bok kwadratu

	//lewy dolny wierzcholek
	wspolrzedna[6] = x;
	wspolrzedna[7] = y;
}

int Obszar::pobierzWspolrzedna(int ktora)
{
	return wspolrzedna[ktora];
}
void Obszar::Maluj(CDC *dc)
{
	POINT p1,p2;//punkty lewego gornego i prawego dolnego punktu obszaru
	//utworzenie danego regionu
	CRgn Rgn; 
	Rgn.CreateRectRgn(wspolrzedna[0],wspolrzedna[1],wspolrzedna[4],wspolrzedna[5]);
	
	//ustalenie koloru
	CBrush brush(RGB(kolor[0], kolor[1], kolor[2]));

	//namalowanie obszaru
	dc->FillRgn(&Rgn, &brush);

	//stworzenie scian
	if (sciana[0] == 1)
		{
			p1.x=wspolrzedna[0];
			p1.y=wspolrzedna[1];
			p2.x=wspolrzedna[6];
			p2.y=wspolrzedna[7];
			POINT tab[2] = {p1,p2};
			dc->Polyline(tab,2);
		} 
		if (sciana[1] == 1){
			
			p1.x=wspolrzedna[0];
			p1.y=wspolrzedna[1];
			p2.x=wspolrzedna[2];
			p2.y=wspolrzedna[3];
			POINT tab[2] = {p1,p2};
			dc->Polyline(tab,2);
		}
}
void Obszar::Wyczysc(CDC *dc, int czySciemnic)
{
	int RoznicaKoloru = 20; //szybkosc sciemniania koloru przechodzonej drogi
	CRgn rgn;
	rgn.CreateRectRgn(wspolrzedna[0]+1,wspolrzedna[1]+1,wspolrzedna[4],wspolrzedna[5]);
	
	CBrush brush(RGB((kolor[1]<=RoznicaKoloru && kolor[0]>RoznicaKoloru && czySciemnic == 1) ? kolor[0]-=RoznicaKoloru  : kolor[0], (kolor[2]<=RoznicaKoloru && kolor[1]>RoznicaKoloru && czySciemnic == 1)? kolor[1]-=RoznicaKoloru : kolor[1], (kolor[2]>RoznicaKoloru && czySciemnic == 1) ? kolor[2]-=RoznicaKoloru:kolor[2]));

	dc->FillRgn(&rgn, &brush);
}
void Obszar::Postaw(CDC *dc, Obiekt *obiekt)
{
	//sprawdzam czy cos stoi na tym polu, jezeli tak to zostanie skasowane
	if (czyZajety() != 1){
		Wyczysc(dc,0);
	}
	obiekt->ustalWierzcholki(wspolrzedna[0],wspolrzedna[1],wspolrzedna[4],wspolrzedna[5]);
	obiekt->Rysuj(dc);
}
void Obszar::ustawKolor(int R,int G,int B)
{
	kolor[0] = R;
	kolor[1] = G;
	kolor[2] = B;
}
void Obszar::zajmij(Krysztal &kry)
{
	//stawia krysztal na danym obszarze
	zajety = 1;
	krysztal = new Krysztal(kry);
}
void Obszar::zwolnij()
{
	delete krysztal;
	zajety = 0;
}
int Obszar::czyZajety()
{
	return zajety;
}
int Obszar::ilePkt()
{
	if (czyZajety() == 1)
	{
		return krysztal->pobierzPunkty();
	}
	else return 0;
}