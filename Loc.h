#pragma once
#include <iostream>
#include <vector>
class Loc
{
public:
	Loc();
	~Loc();
	
	//Getter
	int GetLoc();
	
	//Setter
	void SetLoc(int);

	//Operatori Supraincarcati
	friend std::ostream& operator<<(std::ostream& out, Loc& extragere);
	friend std::istream& operator>>(std::istream& in, Loc& import);
	
private:
	int loc = 0;
};

