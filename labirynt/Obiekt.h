#pragma once
class Obiekt
{
protected:
	POINT P1,P2,P3,P4; // wierzcholki figury, zakladam ze wiekszosc z nich bedzie miala 4 punkty
	int IloscWierzcholkow; // ilosc wierzcholkow tej figury
public:
	Obiekt();
	Obiekt(int,int,int,int); //w argumentach konstruktora sa wspolrzedne 2 wierzcholkow
	virtual ~Obiekt();
	virtual void Rysuj(CDC*);//rysuje obiekt
	virtual void ustalWierzcholki(int,int,int,int);//przypisuje wierzcholki obiektu 
};
