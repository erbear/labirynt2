#include "StdAfx.h"
#include "UkladSterowania.h"
#include <vector>

using namespace std;
UkladSterowania::UkladSterowania(CDC *DC)
{
	poziom = 10;
	mapa = new Plansza(poziom);
	dc=DC;
	lvl = 1;
}


UkladSterowania::~UkladSterowania()
{

}
void UkladSterowania::dodajBohatera(Bohater *wsk)
{
	bohater = wsk;
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

	bohater->ustalWierzcholki(x1,y1,x2,y2);
	bohater->Rysuj(dc);

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
			int punkty = pobierzKrysztal(pozycja+1);
			if (punkty)
			{
				bohater->dodajPkt(punkty);
				mapa->obszar[pozycja+1].Wyczysc(dc);
			}
			mapa->obszar[pozycja+1].Postaw(dc,bohater);//rysuje obiekt na obszarze
			mapa->obszar[pozycja].Wyczysc(dc);//czyszci poprzedni obszar
			bohater->dodajRuch();
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
			int punkty = pobierzKrysztal(pozycja-1);
			if (punkty)
			{
				bohater->dodajPkt(punkty);
				mapa->obszar[pozycja-1].Wyczysc(dc);
			}
			mapa->obszar[pozycja-1].Postaw(dc,bohater);//rysuje obiekt na obszarze
			mapa->obszar[pozycja].Wyczysc(dc);//czyszci poprzedni obszar
			bohater->dodajRuch();
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
			int punkty = pobierzKrysztal(pozycja-poziom);
			if (punkty)
			{
				bohater->dodajPkt(punkty);
				mapa->obszar[pozycja-poziom].Wyczysc(dc);
			}
			mapa->obszar[pozycja-poziom].Postaw(dc,bohater);//rysuje obiekt na obszarze
			mapa->obszar[pozycja].Wyczysc(dc);//czyszci poprzedni obszar
			bohater->dodajRuch();
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
			int punkty = pobierzKrysztal(pozycja+poziom);
			if (punkty)
			{
				bohater->dodajPkt(punkty);
				mapa->obszar[pozycja+poziom].Wyczysc(dc);
			}
			mapa->obszar[pozycja+poziom].Postaw(dc,bohater);//rysuje obiekt na obszarze
			mapa->obszar[pozycja].Wyczysc(dc);//czyszci poprzedni obszar
			bohater->dodajRuch();
			pozycja += poziom;//ustawia nowa pozycje
			czyMeta();

		}
	}
}
int UkladSterowania::pobierzKrysztal(int pozycja)
{
	int ilosc = mapa->obszar[pozycja].ilePkt();
	if (ilosc != 0)
	{
		mapa->obszar[pozycja].zwolnij();
	}
	return ilosc;
}
void UkladSterowania::stworzPlansze()
{
	generator.nowaPlansza(mapa);
	generator.Generuj();
	mapa->Buduj(dc);
	rozmiescKrysztaly(10);
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
	lvl++;
	mapa = new Plansza(poziom);
	stworzPlansze();
	Start();
	
}
void UkladSterowania::rozmiescKrysztaly(int ilosc)
{
	Krysztal krysztal;
	int wielkosc = mapa->pobierzPoziom();
	wielkosc= wielkosc *wielkosc - 2;
	int *wsk;
	wsk = new int[wielkosc];

	for (int i = 0; i<ilosc;i++)
	{
		int wylosowana = rand() % wielkosc;
		if (wsk[wylosowana] != 1)
		{
			wsk[wylosowana] = 1;
			mapa->obszar[wylosowana+2].zajmij(krysztal);
			mapa->obszar[wylosowana+2].Postaw(dc,&krysztal);
		}	

	}
	delete wsk;
	wsk=0;
}
int UkladSterowania::ktoryLvl()
{
	return lvl;
}