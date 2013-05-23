#include "StdAfx.h"
#include "UkladSterowania.h"

UkladSterowania::UkladSterowania(Plansza *wsk,CDC *DC)
{
	mapa = wsk;
	dc=DC;
}


UkladSterowania::~UkladSterowania()
{

}
void UkladSterowania::dodajBohatera(Obiekt *wsk)
{
	obiekt = wsk;
}
void UkladSterowania::naStart()
{
	int n = mapa->GetPoziom();
	int start = 1;
	int meta = n*n;
	int x1,y1,x2,y2;
	x1 = mapa->obszar[0].GetWspolrzedna(0);
	y1 = mapa->obszar[0].GetWspolrzedna(1);
	x2 = mapa->obszar[0].GetWspolrzedna(4);
	y2 = mapa->obszar[0].GetWspolrzedna(5);
	obiekt->setWierzcholki(x1,y1,x2,y2);
	obiekt->Rysuj(dc);
	pozycja = 0;
}
void UkladSterowania::wPrawo()
{
	int poziom = mapa->GetPoziom();
	if ((pozycja+1) % poziom !=0)
	{
		if (mapa->obszar[pozycja+1].GetSciana(0)!=1)
		{
			mapa->obszar[pozycja+1].Postaw(dc,obiekt);
			mapa->obszar[pozycja].Wyczysc(dc);
			pozycja += 1;
		}
	}
}
void UkladSterowania::wLewo()
{
	if ((pozycja+1) % mapa->GetPoziom() !=1)
	{
		if (mapa->obszar[pozycja].GetSciana(0)!=1)
		{
			mapa->obszar[pozycja-1].Postaw(dc,obiekt);
			mapa->obszar[pozycja].Wyczysc(dc);
			pozycja -= 1;
		}
	}
}

void UkladSterowania::wGore()
{
	int poziom = mapa->GetPoziom();
	if (pozycja+1 > poziom)
	{
		if (mapa->obszar[pozycja].GetSciana(1)!=1)
		{
			mapa->obszar[pozycja-poziom].Postaw(dc,obiekt);
			mapa->obszar[pozycja].Wyczysc(dc);
			pozycja -= poziom;
		}
	}
}

void UkladSterowania::wDol()
{
	int poziom = mapa->GetPoziom();
	if (pozycja+poziom+1 <= (poziom*poziom))
	{
		if (mapa->obszar[pozycja+poziom].GetSciana(1)!=1)
		{
			mapa->obszar[pozycja+poziom].Postaw(dc,obiekt);
			mapa->obszar[pozycja].Wyczysc(dc);
			pozycja += poziom;
		}
	}
}

