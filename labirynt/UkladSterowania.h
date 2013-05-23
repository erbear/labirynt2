#pragma once
#include "Plansza.h"
#include "Obiekt.h"
class UkladSterowania
{
	Plansza *mapa;
	Obiekt *obiekt;
	CDC *dc;
	int pozycja;
public:
	UkladSterowania(Plansza*,CDC*);
	~UkladSterowania();
	void dodajBohatera(Obiekt*);
	void naStart();
	void wLewo();
	void wPrawo();
	void wGore();
	void wDol();

};

