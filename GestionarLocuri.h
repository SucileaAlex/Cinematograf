#pragma once
#include"Rand.h"
#include"Loc.h"
class GestionarLocuri
{
public:
	GestionarLocuri();
	~GestionarLocuri();
	void SalveazaLocuri(std::vector<Rand>);
	void ImportaLocuri(std::vector<Rand>);
private:
	//SalaCinema randuri;
	Rand locuri;
};

