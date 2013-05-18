#pragma once
class Obszar
{
	int *sciana;
	int *wspolrzedna;
	CRgn rgn;
public:
	Obszar(void);
	~Obszar(void);

	void  SetSciana(int);
	int GetSciana(int);
	
	void DeleteSciana(int);

	void SetWspolrzedne(int, int, int);
	int GetWspolrzedna(int);

	void Maluj(CDC*);
};

