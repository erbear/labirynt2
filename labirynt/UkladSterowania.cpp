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
	lvl1=0;
	lvl2=0;
	lvl3=0;
	pierwsze = "";
	drugie = "";
	trzecie = "";
	pozycja = -1;
	uruchom = 0;
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
	uruchom = 1;
}
void UkladSterowania::wPrawo()
{
	if (pozycja>=0)
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
}
void UkladSterowania::wLewo()
{
	if (pozycja>=0)
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
}

void UkladSterowania::wGore()
{
	
	if (pozycja>=0)
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
}

void UkladSterowania::wDol()
{
	if (pozycja>=0)
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
void UkladSterowania::zapiszWyniki(string kto)
{
	int miejsce = ktoreMiejsce();
	fstream plik2;
	plik2.open("tabela.txt",std::ios::out | std::ios::trunc);
	if (miejsce == 1)
	{
		plik2<<lvl<<"."<<kto<<"."<<endl;
	}else
	{
		plik2<<lvl1<<"."<<pierwsze<<"."<<endl;
	}
	if (miejsce == 2)
	{
		plik2<<lvl<<"."<<kto<<"."<<endl;
	}else
	{
		plik2<<lvl2<<"."<<drugie<<"."<<endl;
	}
	if (miejsce == 3)
	{
		plik2<<lvl<<"."<<kto<<"."<<endl;
	}else
	{
		plik2<<lvl3<<"."<<trzecie<<"."<<endl;
	}
	plik2.close();
}
void UkladSterowania::wczytajWyniki()
{
	ifstream plik;
	plik.open("tabela.txt", std::ios::in | std::ios::out);
	int j=0;
	if (plik.good()){
		string wiersz;
		for( bool bWczytano = getline( plik, wiersz ); bWczytano; bWczytano = getline( plik, wiersz ) )
		{
			string lvl="",nazwa="";
			int i=0;
			while (wiersz[i]!='.')
			{
				lvl+=wiersz[i];
				i++;
			}
			i++;
			while (wiersz[i]!='.')
			{
				nazwa+=wiersz[i];
				i++;
			}
			if (j==0)
			{
				pierwsze = nazwa;
				lvl1 = atof(lvl.c_str());
			}
			if (j==1)
			{
				drugie = nazwa;
				lvl2 = atof(lvl.c_str());
			}
			if (j==2)
			{
				trzecie = nazwa;
				lvl3 = atof(lvl.c_str());
			}
			j++;
		}
	}
}
int UkladSterowania::ktoreMiejsce()
{
	if (lvl>lvl1) return 1;
	else if (lvl>lvl2) return 2;
	else if (lvl>lvl3) return 3;
	else return 0;
}
int UkladSterowania::czyRekord()
{
	if (ktoreMiejsce()) return 1;
	else return 0;

}
string UkladSterowania::m_pierwsze()
{
	return pierwsze;

}
string UkladSterowania::m_drugie()
{
	return drugie;

}
string UkladSterowania::m_trzecie()
{
	return trzecie;

}
int UkladSterowania::m_lvl1()
{
	return lvl1;

}
int UkladSterowania::m_lvl2()
{
	return lvl2;

}
int UkladSterowania::m_lvl3()
{
	return lvl3;

}