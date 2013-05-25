#include "StdAfx.h"
#include "Krysztal.h"

Krysztal::Krysztal():Obiekt()
{
	IloscWierzcholkow=4;
}


Krysztal::~Krysztal(void)
{
}
void Krysztal::ustalWierzcholki(int x1,int y1,int x2,int y2)
{
	int odstep1 = (x2-x1) /2;
	int odstep3 = (x2-x1)/4;
	P1.x = x1 + odstep1;
	P1.y = y1 +1;
	P2.x = x2 - odstep3;
	P2.y = y1 + odstep1;
	P3.x = x2 - odstep1;
	P3.y = y2 -1;
	P4.x = x1 + odstep3;
	P4.y = y1 + odstep1;
}