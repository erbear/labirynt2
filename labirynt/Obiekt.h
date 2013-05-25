#pragma once
class Obiekt
{
	POINT p1,p2;
	POINT P1,P2,P3;
public:
	Obiekt(int,int,int,int);
	~Obiekt();
	void setWierzcholki(int,int,int,int);
	void Rysuj(CDC*);
};
