#pragma once
#include "Obiekt.h"
class Obszar
{
	int *sciana;//wskaznik na tabice 2 elementow w ktorej znaduja sie sciany, lewa i gorna
	int *wspolrzedna;//wskaznik na 8 elementow, sa to wspolrzedne 4 punktow obszaru
	int kolor[3];//tabica 3 zmiennych ktore odpowiadaja za kolor obszaru
public:
	Obszar();
	~Obszar();

	void ustawSciane(int);
	int czySciana(int);
	
	void usunSciane(int);

	void ustawWspolrzedne(int, int, int);
	int pobierzWspolrzedna(int);

	void Maluj(CDC*);
	void Postaw(CDC*,Obiekt*);
	void Wyczysc(CDC*);
};