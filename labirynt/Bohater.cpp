#include "StdAfx.h"
#include "Bohater.h"

Bohater::Bohater():Obiekt()
{
	IloscWierzcholkow = 3;
}



Bohater::~Bohater(void)
{
}
void Bohater::ustalWierzcholki(int x1,int y1,int x2,int y2)
{
	int odstep = (x2 - x1)/10;
	P1.x = x1 +(x2 - x1)/2;
	P1.y = y1 + odstep+1;
	P2.x = x1 + odstep+1;
	P2.y = y2 - odstep-1;
	P3.x = x2 - odstep-1;
	P3.y = y2 - odstep-1;
}