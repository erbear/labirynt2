<<<<<<< HEAD
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

	void  SetSciana(int);
	int GetSciana(int);
	
	void DeleteSciana(int);

	void SetWspolrzedne(int, int, int);
	int GetWspolrzedna(int);

	void Maluj(CDC*);
	void Postaw(CDC*,Obiekt*);
	void Wyczysc(CDC*);
};

=======
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

	void  SetSciana(int);
	int GetSciana(int);
	
	void DeleteSciana(int);

	void SetWspolrzedne(int, int, int);
	int GetWspolrzedna(int);

	void Maluj(CDC*);
	void Postaw(CDC*,Obiekt*);
	void Wyczysc(CDC*);
};

>>>>>>> de391c487e26461975fa516e93e0e643d38c2c9e
