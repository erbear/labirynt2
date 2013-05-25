#include "StdAfx.h"
#include "UkladSterowania.h"

UkladSterowania::UkladSterowania()
{

}
UkladSterowania::UkladSterowania(Plansza *wsk,CDC *DC)
{
	mapa = wsk;
	dc=DC;
	start = 0;
	int n = mapa->pobierzPoziom();
	meta = n*n;
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
	int x1,y1,x2,y2;
	// wspolrzedne lewego gornego punktu obszaru
	x1 = mapa->obszar[start].pobierzWspolrzedna(0);
	y1 = mapa->obszar[start].pobierzWspolrzedna(1);
	//wspolrzedne prawego dolnego punktu obszaru
	x2 = mapa->obszar[start].pobierzWspolrzedna(4);
	y2 = mapa->obszar[start].pobierzWspolrzedna(5);

	obiekt->ustalWierzcholki(x1,y1,x2,y2);
	obiekt->Rysuj(dc);

	pozycja = start;
}
void UkladSterowania::wPrawo()
{
	//pobiera liczbe obszarow w wierszu
	int poziom = mapa->pobierzPoziom();
	//sprawsza czy istnieje obszar po prawej stronie na ktory mozna sie ruszyc
	if ((pozycja+1) % poziom !=0)
	{
		//sprawdza czy na obszarze po prawej stronie jest sciana
		if (mapa->obszar[pozycja+1].czySciana(0)!=1)
		{

			mapa->obszar[pozycja+1].Postaw(dc,obiekt);//rysuje obiekt na obszarze
			mapa->obszar[pozycja].Wyczysc(dc);//czyszci poprzedni obszar
			pozycja += 1; //ustawia nowa pozycje
		}
	}
}
void UkladSterowania::wLewo()
{
	//sprawsza czy istnieje obszar po lewej stronie na ktory mozna sie ruszyc
	if ((pozycja+1) % mapa->pobierzPoziom() !=1)
	{
		//sprawsza czy istnieje obszar po lewej stronie na ktory mozna sie ruszyc
		if (mapa->obszar[pozycja].czySciana(0)!=1)
		{
			mapa->obszar[pozycja-1].Postaw(dc,obiekt);//rysuje obiekt na obszarze
			mapa->obszar[pozycja].Wyczysc(dc);//czyszci poprzedni obszar
			pozycja -= 1;//ustawia nowa pozycje
		}
	}
}

void UkladSterowania::wGore()
{
	int poziom = mapa->pobierzPoziom();
	if (pozycja+1 > poziom)
	{
		if (mapa->obszar[pozycja].czySciana(1)!=1)
		{
			mapa->obszar[pozycja-poziom].Postaw(dc,obiekt);//rysuje obiekt na obszarze
			mapa->obszar[pozycja].Wyczysc(dc);//czyszci poprzedni obszar
			pozycja -= poziom;//ustawia nowa pozycje
		}
	}
}

void UkladSterowania::wDol()
{
	int poziom = mapa->pobierzPoziom();
	if (pozycja+poziom+1 <= (poziom*poziom))
	{
		if (mapa->obszar[pozycja+poziom].czySciana(1)!=1)
		{
			mapa->obszar[pozycja+poziom].Postaw(dc,obiekt);//rysuje obiekt na obszarze
			mapa->obszar[pozycja].Wyczysc(dc);//czyszci poprzedni obszar
			pozycja += poziom;//ustawia nowa pozycje
		}
	}
}
void UkladSterowania::ustawStart(int i)
{
	start = i;
}
void UkladSterowania::ustawMete(int i)
{
	meta = i;
}
