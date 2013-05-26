#pragma once
#include "obiekt.h"
class Krysztal :
	public Obiekt
{
	int punkty;
public:
	Krysztal();
	Krysztal(Krysztal&);
	~Krysztal(void);
	void ustalWierzcholki(int,int,int,int);
	int pobierzPunkty();
};

