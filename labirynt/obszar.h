#pragma once
#include "Obiekt.h"
class Obszar
{
	int *sciana;
	int *wspolrzedna;
	int kolor[3];
	CRgn *rgn;
public:
	Obszar(void);
	~Obszar(void);

	void ustawSciane(int);
	int czySciana(int);
	
	void usunSciane(int);

	void ustawWspolrzedne(int, int, int);
	int pobierzWspolrzedna(int);

	void Maluj(CDC*);
	void Postaw(CDC*,Obiekt*);
	void Wyczysc(CDC*);
};

