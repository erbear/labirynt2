#pragma once
#include "obiekt.h"
class Bohater :
	public Obiekt
{
public:
	Bohater();
	Bohater(int,int,int,int);
	~Bohater(void);
	void ustalWierzcholki(int,int,int,int);
};

