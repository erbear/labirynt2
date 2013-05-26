#include "StdAfx.h"
#include "Plansza.h"
#include "obszar.h"

Plansza::Plansza()
{
	//ustalam domyslny poziom
	poziom = 10;
	//ustalam domyslna wielkosc w pikselach
	wielkosc = 600;
	//domyslne wartosc wspolrzenych planszy
	x1=y1=0;
	x2=y2=wielkosc+2;
	//obliczam ilosc kwadratow
	kwadraty = poziom * poziom;
	//tworze tablice obszarow
	obszar = new Obszar[kwadraty];
	//dodaje krawedzie do kazdego obszaru
	dodajKrawedzie();
	obliczWspolrzedne();
	//ustawiam start
	start = 0;
	//ustawiam mete
	meta = poziom * poziom -1;

}
Plansza::Plansza(int i)
{
	//ustalam domyslny poziom
	poziom = i;
	//ustalam domyslna wielkosc w pikselach
	wielkosc = 600;
	//obliczam ilosc kwadratow
	kwadraty = poziom * poziom;
	//domyslne wartosc wspolrzenych planszy
	x1=y1=0;
	x2=y2=wielkosc+2;
	//tworzy obszary
	obszar = new Obszar[kwadraty];
	dodajKrawedzie();
	obliczWspolrzedne();
	start = 0;
	meta = poziom * poziom -1;
}
//destruktor
Plansza::~Plansza()
{
	delete []obszar;
}

//przypisuje domyslne wartosci do zmiennej odpowiadajacej za sciany
void Plansza::dodajKrawedzie()
{
	int a,b;
	for(int i =0; i < kwadraty;i++)
	{
		a=i/poziom;
		b=i%poziom;
		if (b!=0)
		obszar[i].ustawSciane(0);
		if (a!=0)
		obszar[i].ustawSciane(1);

	}
}
//przypisuje odpowiednie wartosc do zmiennej odpowiadajacej za wspolrzedne kazdego z kwadratow
void Plansza::obliczWspolrzedne()
{
	int bok = wielkosc/poziom;//bok kwadratu
	int x,y;//zmienne wierzcholka
	for(int i =0; i < kwadraty;i++)
	{
		x=(i%poziom);//reszta z dzielenia numeru kwadratu przez ilosc kwadratow w wierszu
		x=x*bok+1;//reszta pomno¿ona przez wielkosc boku. +1 ze wzgledu na sciane zbudowana na poczatku
		y=(i/poziom);//czesc calkowita z dzielenia numeru kwadratu przez ilosc kwadratow w kolumnie
		y=y*bok+1;//reszta pomno¿ona przez wielkosc boku. +1 ze wzgledu na sciane zbudowana na poczatku
		
		//lewy gorny wierzcholek
		obszar[i].ustawWspolrzedne(x, y, bok);
		
	}
}
void Plansza::Buduj(CDC* dc)
{
	POINT p1,p2;
	dc->Rectangle(x1,y1,x2,y2);//buduje kwadrat otaczajacy obszar labiryntu
	obszar[meta].ustawKolor(255,20,20);//ustawia kolor mety
	for(int i=0;i<kwadraty;i++)
	{
		obszar[i].Maluj(dc);
	}
}

void  Plansza::ustalPrzejscie(int obszar1,int obszar2)
{
	if (obszar1<obszar2)
	{
		if (obszar1+1==obszar2)
			obszar[obszar2-1].usunSciane(0);
		else if (obszar1+poziom==obszar2)
			obszar[obszar2-1].usunSciane(1);
	} else 
	if (obszar1>obszar2)
	{
		if (obszar1==obszar2+1)
			obszar[obszar1-1].usunSciane(0);
		else if (obszar1==obszar2+poziom)
			obszar[obszar1-1].usunSciane(1);
	}

}
int Plansza::pobierzPoziom()
{
	return poziom;
}
void Plansza::ustawStart(int i)
{
	start = i;
}
void Plansza::ustawMete(int i)
{
	meta = i;
}
int Plansza::pobierzStart()
{
	return start;
}
int Plansza::pobierzMete()
{
	return meta;
}
int Plansza::pobierzWielkosc()
{
	return wielkosc;
}