#include "StdAfx.h"
#include "Obiekt.h"


Obiekt::Obiekt()
{
}


Obiekt::~Obiekt()
{
}

void Obiekt::Rysuj(CDC *dc)
{
	POINT tab[4] = {P1, P2, P3, P4};
	dc->Polygon(tab, IloscWierzcholkow);
}