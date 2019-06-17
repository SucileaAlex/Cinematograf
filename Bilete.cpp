#include "Bilete.h"
#include <iostream>

using namespace std;


Bilete::Bilete()
{
}

Bilete::~Bilete()
{
}

int Bilete::GetPI()
{
	return pretI;
}

int Bilete::GetPIO()
{
	return pretIO;
}

int Bilete::GetPR()
{
	return pretR;
}

int Bilete::GetPRO()
{
	return pretRO;
}

void Bilete::SetPI(int set)
{
	pretI = set;
}

void Bilete::SetPIO(int set)
{
	pretIO = set;
}

void Bilete::SetPR(int set)
{
	pretR = set;
}

void Bilete::SetPRO(int set)
{
	pretRO = set;
}

void Bilete::Export(std::ostream & exportus)
{
	exportus << pretI << std::endl;
	exportus << pretIO << std::endl;
	exportus <<  pretR << std::endl;
	exportus << pretRO << std::endl;
}


void Bilete::Import()
{
	InFile.open("FisierCuValori.txt");
	InFile >> pretI;
	InFile >> pretIO;
	InFile >> pretR;
	InFile >> pretRO;
}

void Bilete::ModifPret()
{
	system("CLS");
	//De VALIDAT imputul!
	int a = 1;
	while (a)
	{
		system("CLS");
		cout << "1) Modificati pretul intreg" << endl;
		cout << "2) Modificati pretul cu ochelari 3D" << endl;
		cout << "3) Modificati pretul redus" << endl;
		cout << "4) Modificati pretul redus cu ochelari 3D" << endl;
		cout << "0) Revenire la meniul anterior" << endl;
		cout << endl;
		cout << "Introduceti optiunea dorita: ";
		cin >> a;

		ValidPret.ValidPret(a);

		int schimb = 0;
		switch (a)
		{
		case 1:
			system("CLS");
			cout << "1). Introduceti noua valoare pentru: " << GetPI() << endl;
			cout << "0). Revenire la meniul anterior" << endl << endl;
			int rev;
			cout << "Introduceti optiunea dorita: ";
			cin >> rev;
			
			ValidPret.Validare(rev);

			if (rev == 1)
			{
				cout << "Introduceti noua valoare: ";
				cin >> schimb;

				ValidPret.ValidScPret(schimb);
					SetPI(schimb);
			}
			else
				break;

			break;

		case 2:
			system("CLS");
			cout << "1). Introduceti noua valoare pentru: " << GetPIO() << endl;
			cout << "0). Revenire la meniul anterior" << endl << endl;
			cout << "Introduceti optiunea dorita: ";
			cin >> rev;

			ValidPret.Validare(rev);

			if (rev == 1)
			{
				cout << "Introduceti noua valoare: ";
				cin >> schimb;
				
				ValidPret.ValidScPret(schimb);
					SetPIO(schimb);
			}
			else
				break;
			
			break;
		case 3:
			system("CLS");
			cout << "1). Introduceti noua valoare pentru: " << GetPR() << endl;
			cout << "0). Revenire la meniul anterior" << endl << endl;
			cout << "Introduceti optiunea dorita: ";
			cin >> rev;

			ValidPret.Validare(rev);

			if (rev == 1)
			{
				cout << "Introduceti noua valoare: ";
				cin >> schimb;
				
				ValidPret.ValidScPret(schimb);
					SetPR(schimb);
			}
			else
				break;

			break;

		case 4:
			system("CLS");
			cout << "1). Introduceti noua valoare pentru: " << GetPRO() << endl;
			cout << "0). Revenire la meniul anterior" << endl << endl;;
			cout << "Introduceti optiunea dorita: ";
			cin >> rev;

			ValidPret.Validare(rev);

			if (rev == 1)
			{
				cout << "Introduceti noua valoare: ";
				cin >> schimb;
				ValidPret.ValidScPret(schimb);
					SetPRO(schimb);
			}
			else
				break;
			
			break;

		case 0: break;
		}
	}
}