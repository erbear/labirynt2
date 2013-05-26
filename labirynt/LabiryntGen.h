#pragma once
#include <vector>
#include "obszar.h"
#include "Plansza.h"

using namespace std;

class LabiryntGen
{
	Plansza *plansza;
	vector <int> graniczace;
	int *odwiedzony;
	int *graniczacy;
	int n,v;//ilosc obszarow w planszy i poziom planszy;
	int wersja;//wersja labiryntu
public:
	LabiryntGen();
	LabiryntGen(Plansza*);//argumentem jest poziom planszy
	~LabiryntGen();

	void nowaPlansza(Plansza*);//przygotowuje generator do kolejnego generowania
	void Generuj();//generuje labirynt
	void nastepnaWersja();//zmienia wersje labiryntu
};

