#pragma once
class Obiekt
{
protected:
	POINT P1,P2,P3,P4; // wierzcholki figury, zakladam ze wiekszosc z nich bedzie miala 4 punkty
	int IloscWierzcholkow; // ilosc wierzcholkow tej figury
public:
	Obiekt();
	virtual ~Obiekt();
	virtual void Rysuj(CDC*);//rysuje obiekt
	virtual void ustalWierzcholki(int,int,int,int)=0;//przypisuje wierzcholki obiektu 
};
