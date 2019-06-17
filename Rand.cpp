#include "Rand.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

Rand::Rand()
{
	for (int i = 0; i < locuriRand; i++)
	{
		Loc loc;
			locuri.push_back(loc);
	}
}

Rand::~Rand()
{
}

std::ostream & operator<<(std::ostream & out, Rand & extragere)
{
	for (unsigned int i = 0; i < extragere.locuri.size(); i++) 
	{
		out << extragere.locuri[i] << " ";
	}
	out << endl;
	return out;
}

std::istream & operator>>(std::istream & in, Rand & import)
{
	for (unsigned int i = 0; i < import.locuri.size(); i++)
	{
		in >> import.locuri[i];
	}
	return in;
}

void Rand::Afiseaza()
{
	for (unsigned int i = 0; i < locuri.size(); i++)
	{
			cout << locuri[i] << " ";
	}
}

void Rand::LocuriOcupate(int belet, int locas)
{
	for (int i = 0; i < belet; i++)
	{
		if (locuri[locas++].GetLoc() != 0 && belet > locas)
		{
			//locuri[locas++].SetLoc(1);
			int calcul = belet - locas;
			cout << "Pentru restul de " << calcul << "selectati alt rand";
			cin >> calcul;
		}
	}
}

void Rand::SelectLocuri(int belet, int locas, int pret)
{
	for (int i = 0; i < belet; i++)
	{
		if (pret == 1)
		{
			locuri[locas++].SetLoc(1);
		}
		else if (pret == 2)
		{
			locuri[locas++].SetLoc(2);
		}
		else if (pret == 3)
		{
			locuri[locas++].SetLoc(3);
		}
		else if (pret == 4)
		{
			locuri[locas++].SetLoc(4);
		}
	}
	cout << endl;
}

void Rand::ReturBilete(int bilet, int loc, int baniR)
{
	int creste = 1;
	Bilete Pret;
	for (int i = 0; i < bilet; i++)
	{
		if (locuri[loc].GetLoc() == 0)
		{
			cout << "Locul introdus este liber.";
			break;
		}
		else
		{
			if (locuri[loc].GetLoc() == 1)
			{
				baniR = creste * Pret.GetPI();
				locuri[loc++].SetLoc(0);
				creste++;
			}
			else if (locuri[loc].GetLoc() == 2)
			{
				baniR = creste * Pret.GetPIO();
				locuri[loc++].SetLoc(0);
				creste++;
			}
			else if (locuri[loc].GetLoc() == 3)
			{
				baniR = creste * Pret.GetPR();
				locuri[loc++].SetLoc(0);
				creste++;
			}
			else if (locuri[loc].GetLoc() == 4)
			{
				baniR = creste * Pret.GetPRO();
				locuri[loc++].SetLoc(0);
				creste++;
			}
		}
	}
	cout << "Suma totala de returnat este: " << baniR;
}


void Rand::VerificaLocLiber(int& verf)
{
	for (int i = 0; i < locuri.size(); i++)
	{
		if (locuri[i].GetLoc() == 0)
		{
			verf++;
		}
	}
}