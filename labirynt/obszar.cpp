#include "StdAfx.h"
#include "obszar.h"


Obszar::Obszar(void)
{
	sciana = new int[2];
	wspolrzedna = new int [8];
}


Obszar::~Obszar(void)
{
	delete []sciana;
	delete []wspolrzedna;
}
void Obszar::SetSciana(int ktora)
{
	sciana[ktora]=1;
}
int Obszar::GetSciana(int ktora)
{
	return sciana[ktora];
}
void Obszar::DeleteSciana(int ktora)
{
	sciana[ktora]=0;
}
void Obszar::SetWspolrzedne(int x, int y, int bok)
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

int Obszar::GetWspolrzedna(int ktora)
{
	return wspolrzedna[ktora];
}
void Obszar::Maluj(CDC *dc)
{
	POINT p1,p2;
	rgn.CreateRectRgn(wspolrzedna[0],wspolrzedna[1],wspolrzedna[4],wspolrzedna[5]);
	
	CBrush brush(RGB(255, 255, 153));

	dc->FillRgn(&rgn, &brush);
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