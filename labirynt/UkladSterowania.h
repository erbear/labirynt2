<<<<<<< HEAD
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

=======
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

>>>>>>> de391c487e26461975fa516e93e0e643d38c2c9e
