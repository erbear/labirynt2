#pragma once
#include "obiekt.h"
class Bohater :
	public Obiekt
{
	int punkty;
	int ruchy;
public:
	Bohater();
	~Bohater(void);
	void ustalWierzcholki(int,int,int,int);
	void dodajPkt(int);
	int ilePkt();
	void dodajRuch();
	int ileRuchow();
};

