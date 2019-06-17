#include "SalaCinema.h"
#include <iostream>
#include <fstream>
#include <stdlib.h> 
using namespace std;

SalaCinema::SalaCinema()
{
	for (int i = 0; i < nrRanduri; i++)
	{
		Rand RandulA;
		  Randuri.push_back(RandulA);
	}
}

SalaCinema::~SalaCinema()
{
}

void SalaCinema::Meniu()
{
	salvSala.ImportaLocuri(Randuri);
	Bilet.Import();

	int cazuri = -1;
	while (cazuri != 0)
	{
			cout << "--------------------------MENIU-----------------------" << endl;
			cout << "1.Vinde bilete                    \n";
			cout << "2.Returneaza bilete               \n";
			cout << "3.Afiseaza situatie locuri libere \n";
			cout << "4.Modifica preturile              \n";
			cout << "0.Iesire                          \n";
			cout << endl;
			cout << "Introduceti optiunea dorita: ";
			cin >> cazuri;
			
			ValidImp.ValidPret(cazuri);
			
			int revenire = 1;
			switch (cazuri)
			{
			case 1:
				VindeBilete(); break;
			
			case 2: ReturneazaBilete(); break;
			
			case 3:
				system("CLS");
				Afiseaza();
				
				while (revenire)
				{
					cout << "0).Revenire la meniul anterior." << endl;
					cout << "Introduceti: ";
					cin >> revenire;
					
					ValidImp.Validare(revenire);
				}
				if (revenire == 0)
					break;

			case 4: Bilet.ModifPret(); break;

			case 0:
				Iesire();
				break;
			}
			system("CLS");
	}
}


void SalaCinema::Afiseaza()
{
	ifstream CitesteSala;
	CitesteSala.open("SalaMea.txt");
	
	for (unsigned int i = 0; i < Randuri.size(); i++)
	{
		CitesteSala >> Randuri[i];
		cout << Randuri[i];
	}
	
	CitesteSala.close();
	
	int verifica = 0;
	for (unsigned int i = 0; i < Randuri.size(); i++)
	{
		Randuri[i].VerificaLocLiber(verifica);
	}
	
	cout << endl;
	cout << "Mai avem "<< verifica << " locuri libere";
	cout << endl;
	cout << endl;
}





void SalaCinema::VindeBilete()
{
	system("CLS");
	
	cout << "1). Cumparati bilete." << endl;
	cout << "0). Revenire la meniul anterior." << endl << endl;
	cout << "Introduceti optiunea dorita: ";
	
	int index;
	cin >> index;
	ValidImp.Validare(index);

	switch (index)
	{
	case 1:
		system("CLS"); 
		CumparatiBilete();
		break;
	
	case 0:
		break;
	}
}

void SalaCinema::ReturneazaBilete()
{
	system("CLS");
	int bucla = 1;
	while (bucla)
	{
		int optiuneM;
		int randRet, biletR, locuriR;
		
		cout << "1).Introduceti randul. " << endl;
		cout << "0).Revenire la meniul anterior. " << endl << endl;
		cout << "Introduceti optiunea dorita: ";
		cin >> optiuneM;
		int test = 1;

		ValidImp.Validare(optiuneM);

		if (optiuneM == 1)
		{
			system("CLS");
			cout << "Introduceti randul: ";
			cin >> randRet;
			ValidImp.ValidareRL(randRet);
		}
		else
			break;
		
		system("CLS");
		
			cout << "Introduceti numarul de bilete pe care doriti sa le returnati:  ";
			cin >> biletR;
			
			ValidImp.ValidareRL(biletR);

		system("CLS");

			cout << "Introduceti numarul primului loc:  ";
			cin >> locuriR;
		
			ValidImp.ValidareRL(locuriR);

		int baniRetur = 0;

		system("CLS");

		Randuri[randRet].ReturBilete(biletR, locuriR, baniRetur);

		cout << endl;
		
		cout << "0). Revenire la meniul anterior." << endl;
		cout << "1). Continuati." << endl;
		cout << "Introduceti: ";
		cin >> bucla;
		
		ValidImp.Validare(bucla);

		system("CLS");
		salvSala.SalveazaLocuri(Randuri);
	}
}


void SalaCinema::CumparatiBilete()
{
	int ver = 1;
	while (ver != 0)
	{
		int verifica = 0;
		for (unsigned int i = 0; i < Randuri.size(); i++)
		{
			Randuri[i].VerificaLocLiber(verifica);
		}
		if (verifica == 0)
		{
			cout << "Ne pare rau, nu mai avem locuri disponibile";
			cout << endl;
			ver = 0;
		}
		cout << endl;
		Afiseaza();

		int belet;
		cout << "Introduceti nr. de bilete dorite: ";
		cin >> belet;

		ValidImp.ValidBilet(belet);

		if (belet > verifica)
		{
			char verif;
			cout << "Mai avem doar " << verifica << " locuri libere ramase";
			cout << "Continuanti? (d/n)";
			cin >> verif;
			if (verif == 'd')
				continue;
			else
				break;
		}

		system("CLS");

		int selectR;
		cout << "Introduceti randul dorit: ";
		cin >> selectR;

		ValidImp.ValidareRL(selectR);

		system("CLS");

		int locas;
		cout << "Introduceti locul dorit: ";
		cin >> locas;

		ValidImp.ValidareRL(locas);

		Randuri[selectR].LocuriOcupate(belet, locas);

		system("CLS");

		cout << "Precizati categoria biletelor: " << endl;
		cout << "1). Pret intreg: " << Bilet.GetPI() << " Lei" << endl;
		cout << "2). Pret Intreg cu ochelari: " << Bilet.GetPIO() << " Lei" << endl;
		cout << "3). Pret redus: " << Bilet.GetPR() << " Lei" << endl;
		cout << "4). Pret redus cu ochelari: " << Bilet.GetPRO() << " Lei" << endl;
		cout << "0). Revenire la meniul anterior." << endl;
		
		int cazPret;
		int calcPret = 0;
		
		cout << endl;
		cout << "Introduceti optiunea dorita: ";
		cin >> cazPret;
		
		ValidImp.ValidPret(cazPret);

		int rev;
		switch (cazPret)
		{
		case 1:
			system("CLS");

			calcPret = belet * Bilet.GetPI();
			cout << "Total de plata: " << calcPret << endl;
			cout << "0).Revenire la meniul anterior." << endl;

			cout << "Introduceti: ";
			cin >> rev;

			ValidImp.Validare(rev);

			if (rev == 0)
				break;
		case 2:
			system("CLS");
			
			calcPret = belet * Bilet.GetPIO();

			cout << "Total de plata: " << calcPret << endl;
			cout << "0).Revenire la meniul anterior." << endl;

			cout << "Introduceti: ";
			cin >> rev;

			ValidImp.Validare(rev);

			if (rev == 0)
				break;
		case 3:
			system("CLS");
			
			calcPret = belet * Bilet.GetPR();

			cout << "Total de plata: " << calcPret << endl;
			cout << "0).Revenire la meniul anterior." << endl;

			cout << "Introduceti: ";
			cin >> rev;

			ValidImp.Validare(rev);

			if (rev == 0)
				break;
		case 4:
			system("CLS");
			
			calcPret = belet * Bilet.GetPRO();

			cout << "Total de plata: " << calcPret << endl;
			cout << "0).Revenire la meniul anterior." << endl;

			cout << "Introduceti: ";
			cin >> rev;

			ValidImp.Validare(rev);

			if (rev == 0)
				break;
		
		case 0:
			break;
		}
		
		Randuri[selectR].SelectLocuri(belet, locas, cazPret);
		
		salvSala.SalveazaLocuri(Randuri);
		
		ver = 0;
	}
}

void SalaCinema::Iesire()
{
	system("CLS");
	
	ofstream outFisOb("FisierCuValori.txt");
	Bilet.Export(outFisOb);
}



