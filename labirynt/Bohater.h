#pragma once
#include "obiekt.h"
class Bohater :
	public Obiekt
{
	int punkty;
public:
	Bohater();
	~Bohater(void);
	void ustalWierzcholki(int,int,int,int);
	void dodajPkt(int);
	int ilePkt();
};

