#pragma once
#include "Loc.h"
#include <vector>
#include "Bilete.h"
class Rand
{
public:
	Rand();
	~Rand();
	void Afiseaza();
	void SelectLocuri(int, int, int);
	void LocuriOcupate(int, int);
	void ReturBilete(int, int, int);
	void VerificaLocLiber(int&);
	friend std::ostream& operator<<(std::ostream& out, Rand& extragere);
	friend std::istream& operator>>(std::istream& in, Rand& import);

private:

	unsigned short locuriRand = 20;
	std::vector<Loc> locuri;
};

