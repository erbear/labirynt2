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

	void ustawSciane(int);//ustawia w zmiennej sciana 1, w argumencie znajduje sie sciana lewa(0) lub gorna(1)
	void usunSciane(int);//usuwa sciane czyli ustawia w zmiennej sciana 0, w argumencie znajduje sie sciana lewa(0) lub gorna(1)
	int czySciana(int);//sprawdza czy jest ustawiona sciana
	

	void ustawWspolrzedne(int, int, int);//ustawia wspolrzedne obszaru, pierwsze dwa argumenty to wspolrzedne lewego gornego punktu. trzeci argument to dlugosc boku
	int pobierzWspolrzedna(int);//pobiera dana wspolrzedna

	void Maluj(CDC*);//umieszcza obszar w odpowiednim miejscu na oknie
	void Postaw(CDC*,Obiekt*);//stawia obiekt na obszarze
	void Wyczysc(CDC*);//czysci obszar

	void ustawKolor(int,int,int);//ustawia kolor obszaru
};