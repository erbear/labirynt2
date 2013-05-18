#include "StdAfx.h"
#include "LabiryntGen.h"


LabiryntGen::LabiryntGen(void)
{
}
LabiryntGen::LabiryntGen(Plansza *plansza)
{
	v = plansza->GetPoziom();
	n=v*v;
	odwiedzony = new int[n+1];
	for (int i = 0; i<n+1;i++)
	odwiedzony[i] = 0;
	graniczacy = new int[n+1];
	for (int i = 0; i<n+1;i++)
	graniczacy[i] = 0;
}



LabiryntGen::~LabiryntGen(void)
{
	delete[] odwiedzony;
	odwiedzony = 0;
	delete[] graniczacy;
	graniczacy = 0;
}

void LabiryntGen::Generuj(Plansza *plansza)
{
	int z,x,y;
	for (int i =0;i<n;i++)
	{
		if (i ==0)
		{
			z = rand() % n;
			odwiedzony[z]=1;
			graniczacy[z]=1;
		}
		else 
		{
			y = rand() % graniczace.size();
			z=graniczace[y];
			odwiedzony[graniczace[y]] = 1;
			graniczace.erase(graniczace.begin() + (y));
		}
		vector <int> dopolaczenia;
		if (z > 1 ){
			if ((z%v)!=1)
			{
				if (graniczacy[z-1]==0)
				{
				
					graniczace.push_back(z-1);
					graniczacy[z-1] = 1;
				}else if (odwiedzony[z-1]==1)
						dopolaczenia.push_back(z-1);
			}
			if (z>v) {
				if (graniczacy[z-v]==0)
				{
					graniczace.push_back(z-v);
					graniczacy[z-v] = 1;
				}
				else if (odwiedzony[z-v]==1)
					dopolaczenia.push_back(z-v);
			}
		}
		if (z+1 <= n){
			if (z%v!=0)
			{
				if (graniczacy[z+1]==0)
				{
					graniczace.push_back(z+1);
					graniczacy[z+1] = 1;
				} else if (odwiedzony[z+1]==1)
						dopolaczenia.push_back(z+1);
			}
			if (z+v <= n){
				if (graniczacy[z+v]==0)
				{
					graniczace.push_back(z+v);
					graniczacy[z+v] = 1;
				} else if (odwiedzony[z+v]==1)
						dopolaczenia.push_back(z+v);
			}
		}
		if (dopolaczenia.size()!=0)
		{
		x = rand() % dopolaczenia.size();
		plansza->SetDroga(dopolaczenia[x], z);
		}
		


	}
}