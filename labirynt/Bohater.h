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
	void dodajPkt(int);//dodaje punkty bohaterowi
	int ilePkt();//sprawdza ile pkt ma obiekt
	void dodajRuch();
	int ileRuchow();//sprawdza ile ruchow wykonal bohater
};

