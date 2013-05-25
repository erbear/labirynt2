#pragma once
#include "obiekt.h"
class Krysztal :
	public Obiekt
{
public:
	Krysztal();
	Krysztal(int,int,int,int);
	~Krysztal(void);
	void ustalWierzcholki(int,int,int,int);
};

