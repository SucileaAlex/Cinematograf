#pragma once
#include <iostream>
#include <fstream>
#include "Validator.h"
class Bilete
{
public:
	Bilete();
	~Bilete();
	
	//Getter-i
	int GetPI();
	int GetPIO();
	int GetPR();
	int GetPRO();
	
	//Setter-i
	void SetPI(int);
	void SetPIO(int);
	void SetPR(int);
	void SetPRO(int);
	
	//Metode
	void Export(std::ostream&);
	void Import();
	void ModifPret();
	
private:

	    std::ifstream InFile;
		int pretI  = 30;
		int pretIO = 32;
		int pretR  = 20;
		int pretRO = 22;
		Validator ValidPret;
};

