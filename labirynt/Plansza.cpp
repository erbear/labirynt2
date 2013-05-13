#include "StdAfx.h"
#include "Plansza.h"


Plansza::Plansza()
{
	//ustalam domyslny poziom
	poziom = 4;
	//ustalam domyslna wielkosc w pikselach
	wielkosc = 400;
	//domyslne wartosc wspolrzenych planszy
	x1=y1=0;
	x2=y2=wielkosc+2;
	//obliczam ilosc kwadratow
	kwadraty = poziom * poziom;
	//lokowanie tablic dwuwymiarowych
	sciana = new int*[kwadraty];
	wspolrzedna = new int*[kwadraty];
	for (int i = 0; i < kwadraty; i++)
	{
		sciana[i] = new int[2];
		wspolrzedna[i] = new int[8];
	}
	dodajKrawedzie();
	obliczWspolrzedne();
}

//destruktor
Plansza::~Plansza()
{
	//zwalnianie zaalokowanej pamieci
	for (int i = 0; i < kwadraty; i++)
	{
		delete [] sciana[i];
		delete [] wspolrzedna[i];
	}

	delete [] sciana;
	delete [] wspolrzedna;
}
//przypisuje domyslne wartosci do zmiennej odpowiadajacej za sciany
void Plansza::dodajKrawedzie()
{
	int a,b;
	for(int i =0; i < kwadraty;i++)
	{
		a=i/poziom;
		b=i%poziom;
		if (b!=0)
		sciana[i][0]=1;
		if (a!=0)
		sciana[i][1]=1;

	}
}
//przypisuje odpowiednie wartosc do zmiennej odpowiadajacej za wspolrzedne kazdego z kwadratow
void Plansza::obliczWspolrzedne()
{
	int bok = wielkosc/poziom;//bok kwadratu
	int x,y;//zmienne wierzcholka
	for(int i =0; i < kwadraty;i++)
	{
		x=(i%poziom);//reszta z dzielenia numeru kwadratu przez ilosc kwadratow w wierszu
		x=x*bok+1;//reszta pomno¿ona przez wielkosc boku. +1 ze wzgledu na sciane zbudowana na poczatku
		y=(i/poziom);//czesc calkowita z dzielenia numeru kwadratu przez ilosc kwadratow w kolumnie
		y=y*bok+1;//reszta pomno¿ona przez wielkosc boku. +1 ze wzgledu na sciane zbudowana na poczatku
		
		//lewy gorny wierzcholek
		wspolrzedna[i][0]=x;
		wspolrzedna[i][1]=y;

		x+=bok;//przesuniecie x w prawo o bok kwadratu

		//prawy gorny wierzcholek
		wspolrzedna[i][2]=x;
		wspolrzedna[i][3]=y;

		y+=bok;//przesuniecie y w dol o bok kwadratu

		//prawy dolny wierzcholek
		wspolrzedna[i][4]=x;
		wspolrzedna[i][5]=y;

		x-=bok;// przesuniecie x w lewo o bok kwadratu

		//lewy dolny wierzcholek
		wspolrzedna[i][6]=x;
		wspolrzedna[i][7]=y;
	}
}
void Plansza::Buduj(CDC* dc)
{
	POINT p1,p2;
	dc->Rectangle(x1,y1,x2,y2);
	CBrush brushRed(RGB(255, 255, 153));
	CBrush* pOldBrush = dc->SelectObject(&brushRed);
	CRgn *rgn;
	rgn = new CRgn[kwadraty];
	for(int i=0;i<kwadraty;i++)
	{
		rgn[i].CreateRectRgn(wspolrzedna[i][0],wspolrzedna[i][1],wspolrzedna[i][4],wspolrzedna[i][5]);
		dc->PaintRgn(&rgn[i]);
		if (sciana[i][0] == 1)
		{
			p1.x=wspolrzedna[i][0];
			p1.y=wspolrzedna[i][1];
			p2.x=wspolrzedna[i][6];
			p2.y=wspolrzedna[i][7];
			POINT tab[2] = {p1,p2};
			dc->Polyline(tab,2);
		} 
		if (sciana[i][1] == 1){
			
			p1.x=wspolrzedna[i][0];
			p1.y=wspolrzedna[i][1];
			p2.x=wspolrzedna[i][2];
			p2.y=wspolrzedna[i][3];
			POINT tab[2] = {p1,p2};
			dc->Polyline(tab,2);
		}

	}
	delete [] rgn;
	rgn = 0;
}