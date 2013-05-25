#pragma once
#include "Plansza.h"
#include "Obiekt.h"
class UkladSterowania
{
	Plansza *mapa;
	Obiekt *obiekt;
	CDC *dc;
	int pozycja;
	int start, meta;
public:
	UkladSterowania();
	UkladSterowania(Plansza*,CDC*);
	~UkladSterowania();
	void dodajBohatera(Obiekt*);
	void naStart();//ustawia bohatera na pierwszym polu(START)
	void ustawStart(int);//odpowiada za pole startu 1 - poziom*poziom
	void ustawMete(int);//odpowiada za pole mety 1 - poziom *poziom
	
	//sterowanie obiektem w 4 strony
	void wLewo();
	void wPrawo();
	void wGore();
	void wDol();

};