#include "StdAfx.h"
#include "UkladSterowania.h"

UkladSterowania::UkladSterowania(CDC *DC)
{
	poziom = 10;
	mapa = new Plansza(poziom);
	dc=DC;
}


UkladSterowania::~UkladSterowania()
{

}
void UkladSterowania::dodajBohatera(Obiekt *wsk)
{
	obiekt = wsk;
}
void UkladSterowania::Start()
{
	int start=mapa->pobierzStart();
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
			czyMeta();
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
			czyMeta();
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
			czyMeta();
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
			czyMeta();
		}
	}
}
void UkladSterowania::stworzPlansze()
{
	generator.nowaPlansza(mapa);
	generator.Generuj();
	mapa->Buduj(dc);
}
void UkladSterowania::czyMeta()
{
	if (pozycja==mapa->pobierzMete())
	{
		nastepnyPoziom();
	}
}
void UkladSterowania::nastepnyPoziom()
{
	poziom+=1;
	int wielkosc = mapa->pobierzWielkosc();
	while (wielkosc % poziom !=0)
	{
		poziom++;
	}
	delete mapa;
	mapa = new Plansza(poziom);
	stworzPlansze();
	Start();
	
}