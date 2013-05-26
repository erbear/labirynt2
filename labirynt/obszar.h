#pragma once
#include "Obiekt.h"
#include "Krysztal.h"
class Obszar
{
	int *sciana;//wskaznik na tabice 2 elementow w ktorej znaduja sie sciany, lewa i gorna
	int *wspolrzedna;//wskaznik na 8 elementow, sa to wspolrzedne 4 punktow obszaru
	int kolor[3];//tabica 3 zmiennych ktore odpowiadaja za kolor obszaru
	int zajety;//czy jakis obiekt jest na tym obszarze
	Krysztal *krysztal;
public:
	Obszar();
	~Obszar();

	void ustawSciane(int);//ustawia w zmiennej sciana 1, w argumencie znajduje sie sciana lewa(0) lub gorna(1)
	void usunSciane(int);//usuwa sciane czyli ustawia w zmiennej sciana 0, w argumencie znajduje sie sciana lewa(0) lub gorna(1)
	int czySciana(int);//sprawdza czy jest ustawiona sciana
	
	void zajmij(Krysztal &);//zatwierdza krysztal na obszarze
	void zwolnij();//zwalnia krysztal z obszaru
	int czyZajety();//sprawdza czy krysztal jest na obszarze

	int ilePkt();//sprawdza jaka wartosc maja obiekty stojace na obszarze

	void ustawWspolrzedne(int, int, int);//ustawia wspolrzedne obszaru, pierwsze dwa argumenty to wspolrzedne lewego gornego punktu. trzeci argument to dlugosc boku
	int pobierzWspolrzedna(int);//pobiera dana wspolrzedna

	void Maluj(CDC*);//umieszcza obszar w odpowiednim miejscu na oknie
	void Postaw(CDC*,Obiekt*);//stawia obiekt na obszarze
	void Wyczysc(CDC*,int = 1);//czysci obszar, drugi argument odpowiada za sciemnianie koloru

	void ustawKolor(int,int,int);//ustawia kolor obszaru
};