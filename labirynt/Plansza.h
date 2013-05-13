#pragma once
class Plansza
{
	int x1,y1;//punkt poczatka lewej gornej krawedzi planszy
	int x2,y2;//punkt poczatka prawej dolnej krawedzi planszy
	int wielkosc;//wielkosc w pikselach
	int poziom;// ilosc kwadratow w wierszu
	int kwadraty; // ilosc wszystkich kwadratow
	int **sciana;// trzyma dane o tym czy istnieje krawedz na danym boku kwadratu
	int	**wspolrzedna;// trzyma wspolrzedne wierzcholkow kwadratu
public:
	Plansza();//konstruktor bezargumentowy
	~Plansza();//destruktor
	void Buduj(CDC*);
private:
	void dodajKrawedzie();
	void obliczWspolrzedne();
};

