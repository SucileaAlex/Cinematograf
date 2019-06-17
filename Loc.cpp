#include "Loc.h"



Loc::Loc()
{

}


Loc::~Loc()
{
}


std::ostream & operator<<(std::ostream & out, Loc & extragere)
{
	Loc locuri;
	if (locuri.loc == 3) {
		out << extragere.loc << " ";
	}
	else {
		out << extragere.loc << " ";
	}
	return out;
}

std::istream & operator>>(std::istream & in, Loc & import)
{
	Loc locuri;
	if (locuri.loc == 3)
	{
		in >> import.loc;
	}
	else
	{
		in >> import.loc;
	}
	return in;
}

int Loc::GetLoc()
{
	return loc;
}

void Loc::SetLoc(int set)
{
	loc = set;
}