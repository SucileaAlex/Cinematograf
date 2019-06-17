#include "Validator.h"
#include <iostream>

using namespace std;


Validator::Validator()
{
}


Validator::~Validator()
{
}

void Validator::Validare(int & valid)
{
	int test = 1;
	while (test)
	{
		if (cin.fail() || valid != 0 && valid != 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduceti va rog o optiune valida: ";
			cin >> valid;
		}
		else
			break;
	}
}

void Validator::ValidareRL(int & valid)
{
	int test = 1;
	while (test)
	{
		if (cin.fail() || valid > 19 || valid < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduceti va rog un nr valid: ";
			cin >> valid;
		}
		else
			break;
	}
}

void Validator::ValidPret(int & valid)
{
	int test = 1;
	while (test)
	{
		if (cin.fail() || valid > 4 || valid < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduceti va rog un nr valid: ";
			cin >> valid;
		}
		else
			break;
	}
}


void Validator::ValidScPret(int & valid)
{
	int test = 1;
	while (test)
	{
		if (cin.fail() || valid < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduceti va rog un nr valid: ";
			cin >> valid;
		}
		else
			break;
	}
	cout << endl;
}

void Validator::ValidBilet(int &valid)
{
	int test = 1;
	while (test)
	{
		if (cin.fail() || valid < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduceti va rog un nr valid: ";
			cin >> valid;
		}
		else
			break;
	}
	cout << endl;
}