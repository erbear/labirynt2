#pragma once
#include "Plansza.h"
#include "Obiekt.h"
#include "LabiryntGen.h"
#include "Plansza.h"
#include "Krysztal.h"
#include "Bohater.h"
class UkladSterowania
{
	Plansza *mapa;
	Bohater *bohater;
	CDC *dc;
	int pozycja;
	LabiryntGen generator;
	int poziom;//poziom planszy
	int lvl;
public:
	UkladSterowania(CDC*);
	UkladSterowania(Plansza*,CDC*);
	~UkladSterowania();
	
	//zarzadzanie obiektem
	void dodajBohatera(Bohater*);

	//sterowanie obiektem w 4 strony
	void wLewo();
	void wPrawo();
	void wGore();
	void wDol();

	//zarzadzanie plansza
	void stworzPlansze();
	void Start();//ustawia bohatera na polu ustalonym zmienna start
	void ustawStart(int);//odpowiada za pole startu 1 - poziom*poziom
	void ustawMete(int);//odpowiada za pole mety 1 - poziom *poziom
	void czyMeta();
	void nastepnyPoziom();
	void rozmiescKrysztaly(int);
	int pobierzKrysztal(int);

	int ktoryLvl();
};