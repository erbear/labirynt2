#pragma once
class Obiekt
{
protected:
	POINT P1,P2,P3,P4;
	int IloscWierzcholkow;
public:
	Obiekt();
	Obiekt(int,int,int,int);
	virtual ~Obiekt();
	virtual void Rysuj(CDC*);
	virtual void ustalWierzcholki(int,int,int,int);
};

