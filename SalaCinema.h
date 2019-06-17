#pragma once
#include "Loc.h"
#include "Rand.h"
#include "Bilete.h"
#include <vector>
#include "GestionarLocuri.h"
#include "Validator.h"
class SalaCinema
{
public:
	SalaCinema();
	~SalaCinema();
	void Afiseaza();
	void Meniu();
	void VindeBilete();
	void ReturneazaBilete();
	void Iesire();
	void CumparatiBilete();

private:
	GestionarLocuri salvSala;
	unsigned short nrRanduri = 20;
	std::vector<Rand> Randuri;
	Loc obLoc;
	Bilete Bilet;
	Rand rand;
	Validator ValidImp;
};

