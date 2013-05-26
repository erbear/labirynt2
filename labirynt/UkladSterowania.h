#pragma once
#include <fstream>
#include <sstream>
#include "Plansza.h"
#include "Obiekt.h"
#include "LabiryntGen.h"
#include "Plansza.h"
#include "Krysztal.h"
#include "Bohater.h"
using namespace std;
class UkladSterowania
{
	Plansza *mapa;//wskaznik na plansze
	Bohater *bohater;//wskaznik na obiekt bohatera
	CDC *dc;
	int pozycja;//zmienna z aktualna pozycja bohatera na planszy
	LabiryntGen generator;//nowy generator labiryntu
	int poziom;//poziom planszy
	int lvl;//poziom aktualnej gry
	string pierwsze, drugie, trzecie;
	int lvl1,lvl2,lvl3;
	int uruchom;//odpowiada za to czy mozna juz skrecac
public:
	UkladSterowania(CDC*);
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
	
	void czyMeta();//sprawdza czy obiekt stoi na mecie, jesli tak to zaczyna kolejny poziom
	void nastepnyPoziom();//zaczyna kolejny poziom
	void rozmiescKrysztaly(int);//rozmieszcza krysztaly na danej planszy
	int pobierzKrysztal(int);//sprawdza czy na polu jest krysztal


	int ktoryLvl();//zwraca aktualny poziom gry
	
	//lista rankingowa
	void zapiszWyniki(string);
	void wczytajWyniki();
	int ktoreMiejsce();
	int czyRekord();
	string m_pierwsze();
	string m_drugie();
	string m_trzecie();

	int m_lvl1();
	int m_lvl2();
	int m_lvl3();
};