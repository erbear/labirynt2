#include "StdAfx.h"
#include "Plansza.h"
#include "obszar.h"

Plansza::Plansza()
{
	//ustalam domyslny poziom
	poziom = 40;
	//ustalam domyslna wielkosc w pikselach
	wielkosc = 400;
	//domyslne wartosc wspolrzenych planszy
	x1=y1=0;
	x2=y2=wielkosc+2;
	//obliczam ilosc kwadratow
	kwadraty = poziom * poziom;
	//
	obszar = new Obszar[kwadraty];
	for (int i = 0; i < kwadraty; i++)
	
	dodajKrawedzie();
	obliczWspolrzedne();
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
		obszar[i].SetSciana(0);
		if (a!=0)
		obszar[i].SetSciana(1);

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
		obszar[i].SetWspolrzedne(x, y, bok);
		
	}
}
void Plansza::Buduj(CDC* dc)
{
	POINT p1,p2;
	dc->Rectangle(x1,y1,x2,y2);//buduje kwadrat otaczajacy obszar labiryntu
	
	for(int i=0;i<kwadraty;i++)
	{
		obszar[i].Maluj(dc);
	}
}

void  Plansza::SetDroga(int obszar1,int obszar2)
{
	if (obszar1<obszar2)
	{
		if (obszar1+1==obszar2)
			obszar[obszar2-1].DeleteSciana(0);
		else if (obszar1+poziom==obszar2)
			obszar[obszar2-1].DeleteSciana(1);
	} else 
	if (obszar1>obszar2)
	{
		if (obszar1==obszar2+1)
			obszar[obszar1-1].DeleteSciana(0);
		else if (obszar1==obszar2+poziom)
			obszar[obszar1-1].DeleteSciana(1);
	}

}
int Plansza::GetPoziom()
{
	return poziom;
}