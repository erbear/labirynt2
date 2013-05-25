#include "StdAfx.h"
#include "Obiekt.h"


Obiekt::Obiekt()
{
}
Obiekt::Obiekt(int x1,int y1,int x2,int y2)
{
	ustalWierzcholki(x1,y1,x2,y2);
}


Obiekt::~Obiekt()
{
}

void Obiekt::Rysuj(CDC *dc)
{
	POINT tab[4] = {P1, P2, P3, P4};
	dc->Polygon(tab, IloscWierzcholkow);
}
void Obiekt::ustalWierzcholki(int x1,int y1,int x2,int y2)
{
	int odstep = x2-x1;
	P1.x = x1;
	P1.y = y1;
	P2.x = x1+odstep;
	P2.y = y1;
	P3.x = x1 + odstep;
	P3.y = y1 + odstep;
	P4.x = x1;
	P4.y = y1+odstep;
}