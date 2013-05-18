#pragma once
#include "obszar.h"
class Plansza
{
	int x1,y1;//punkt poczatka lewej gornej krawedzi planszy
	int x2,y2;//punkt poczatka prawej dolnej krawedzi planszy
	int wielkosc;//wielkosc w pikselach
	int poziom;// ilosc kwadratow w wierszu
	int kwadraty; // ilosc wszystkich kwadratow
	Obszar *obszar;
public:
	Plansza();//konstruktor bezargumentowy
	~Plansza();//destruktor
	void Buduj(CDC*);
	void  SetDroga(int,int);
	int GetPoziom();
private:
	void dodajKrawedzie();
	void obliczWspolrzedne();
};

