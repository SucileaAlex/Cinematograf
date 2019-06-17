#include "GestionarLocuri.h"
#include <iostream>
#include <fstream>
using namespace std;


GestionarLocuri::GestionarLocuri()
{
}


GestionarLocuri::~GestionarLocuri()
{
}

//Salveaza locurile in fisier.
void GestionarLocuri::SalveazaLocuri(std::vector<Rand> SalaFisier)
{
	
	ofstream extract("SalaMea.txt");
	for (unsigned int i = 0; i < SalaFisier.size(); i++)
	{
		extract << SalaFisier[i];
	}
}

//Importa locurile din fisier.
void GestionarLocuri::ImportaLocuri(std::vector<Rand> SalaFisier)
{
	ifstream import("SalaMea.txt");
	for (int i = 0; i < SalaFisier.size(); i++)
	{
		import >> SalaFisier[i];
	}
}