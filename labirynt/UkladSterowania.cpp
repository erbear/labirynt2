#include "StdAfx.h"
#include "UkladSterowania.h"
#include <vector>

using namespace std;
UkladSterowania::UkladSterowania(CDC *DC)
{
	poziom = 10;//ustalenie pierwszego poziomu
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
			//sprawdza czy kolejne pole ma w sobie jakis krysztal i pobiera go
			int punkty = pobierzKrysztal(pozycja+1);
			if (punkty)
			{
				bohater->dodajPkt(punkty);
				mapa->obszar[pozycja+1].Wyczysc(dc);
			}
			mapa->obszar[pozycja+1].Postaw(dc,bohater);//rysuje obiekt na obszarze
			mapa->obszar[pozycja].Wyczysc(dc);//czyszci poprzedni obszar
			bohater->dodajRuch();//dodaje jedynke do zmiennej ruchy w obiekcie
			pozycja += 1; //ustawia nowa pozycje
			czyMeta();//sprawdza czy obiekt stanal na mecie, jesli tak to zaczyna nowa plansze
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
			//sprawdza czy kolejne pole ma w sobie jakis krysztal i pobiera go
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
			czyMeta();//sprawdza czy obiekt stanal na mecie, jesli tak to zaczyna nowa plansze
		}
	}
}

void UkladSterowania::wGore()
{
	int poziom = mapa->pobierzPoziom();
	if (pozycja+1 > poziom)
	{
			//sprawdza czy kolejne pole ma w sobie jakis krysztal i pobiera go
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
			czyMeta();//sprawdza czy obiekt stanal na mecie, jesli tak to zaczyna nowa plansze
		}
	}
}

void UkladSterowania::wDol()
{
	int poziom = mapa->pobierzPoziom();
	if (pozycja+poziom+1 <= (poziom*poziom))
	{
			//sprawdza czy kolejne pole ma w sobie jakis krysztal i pobiera go
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
			czyMeta();//sprawdza czy obiekt stanal na mecie, jesli tak to zaczyna nowa plansze

		}
	}
}
int UkladSterowania::pobierzKrysztal(int pozycja)
{
	//sprawdza krysztal znajduje sie na danej pozycji i zwraca jego punkty
	int ilosc = mapa->obszar[pozycja].ilePkt();
	//jezeli sa jakies to usuwa krysztal i zwraca jego punkty
	if (ilosc != 0)
	{
		mapa->obszar[pozycja].zwolnij();
	}
	return ilosc;
}
void UkladSterowania::stworzPlansze()
{
	//przekazuje wskaznik na plansze do generatora
	generator.nowaPlansza(mapa);
	//wykonuje operacje na planszy, powstaje na niej labirynt
	generator.Generuj();
	//drukuje plansze w oknie
	mapa->Buduj(dc);
	//rozmieszcza na niej krysztaly
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
	//zwieksza poziom planszy
	poziom+=1;
	//zwieksza poziom gry
	lvl++;
	//jezeli poziom planszy nie dzieli sie bez reszty przez jej wielkosc 
	//to zwiekszam go az tak sie stanie
	int wielkosc = mapa->pobierzWielkosc();
	while (wielkosc % poziom !=0)
	{
		poziom++;
	}
	//kasuje stara plansze i tworze nowa
	delete mapa;
	mapa = new Plansza(poziom);
	stworzPlansze();
	//stawiam pionka na pozycji startu
	Start();
	
}
void UkladSterowania::rozmiescKrysztaly(int ilosc)
{
	//tworze krysztal
	Krysztal krysztal;
	//pobieram ilosc kwadratow w planszu i usuwam z nich start i mete
	int wielkosc = mapa->pobierzPoziom();
	wielkosc= wielkosc *wielkosc - 2;
	//tworze tablice ktorej elementy maja wartosc 1 jezeli na danym miejscu(elemencie)znajduje sie krysztal
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