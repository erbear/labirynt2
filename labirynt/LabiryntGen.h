#pragma once
#include <vector>
#include "obszar.h"
#include "Plansza.h"

using namespace std;

class LabiryntGen
{
	vector <int> graniczace;
	int *odwiedzony;
	int *graniczacy;
	int n,v;//ilosc obszarow w planszy i poziom planszy;
public:
	LabiryntGen(void);
	LabiryntGen(Plansza*);//argumentem jest poziom planszy
	~LabiryntGen(void);

	void Generuj(Plansza*);

};

