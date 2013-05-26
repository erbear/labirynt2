#pragma once
#include "obszar.h"
class Plansza
{
	int x1,y1;//punkt poczatka lewej gornej krawedzi planszy
	int x2,y2;//punkt poczatka prawej dolnej krawedzi planszy
	int wielkosc;//wielkosc w pikselach, liczba calkowita, nie moze byc liczba pierwsza
	int poziom;// ilosc kwadratow w wierszu
	int kwadraty; // ilosc wszystkich kwadratow
	int start;
	int meta;
	Obszar *obszar;
public:
	Plansza();//konstruktor bezargumentowy
	Plansza(int);//konstruktor z liczba poziomow w argumentach
	~Plansza();//destruktor
	void Buduj(CDC*);//tworzy plansze
	void ustalPrzejscie(int,int);//kasuje sciane pomiedzy dwoma obszarami

	//funkcje pobierajace i ustawiajace zmienne
	int pobierzPoziom();
	int pobierzWielkosc();
	void ustawStart(int);
	void ustawMete(int);
	int pobierzStart();
	int pobierzMete();

private:
	void dodajKrawedzie();//dodaje wszytkie krawedzie do wszystkich obszarow
	void obliczWspolrzedne();//dodaje wspolrzedne do wszystkich obszarow
	
	friend class UkladSterowania;
};

