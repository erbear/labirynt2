#include "StdAfx.h"
#include "Obiekt.h"


Obiekt::Obiekt(int x1,int y1,int x2,int y2)
{
	setWierzcholki(x1,y1,x2,y2);
}


Obiekt::~Obiekt()
{
}
void Obiekt::setWierzcholki(int x1,int y1, int x2, int y2)
{
	int odstep = (x2 - x1)/10;
	P1.x = x1 +(x2 - x1)/2;
	P1.y = y1 + odstep+1;
	P2.x = x1 + odstep+1;
	P2.y = y2 - odstep-1;
	P3.x = x2 - odstep-1;
	P3.y = y2 - odstep-1;
}
void Obiekt::Rysuj(CDC *dc)
{
	POINT tab[3] = {P1, P2, P3};
	dc->Polygon(tab, 3);
}