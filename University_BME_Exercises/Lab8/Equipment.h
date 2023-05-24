#pragma once

#include <iostream>

using namespace std;

class Equipment
{
protected:
	int ID, price, year;
public:
	Equipment(int d, int p, int y) : ID(d), price(p), year(y) {}

	virtual void print()
	{
		cout << "Identification number: " << ID << endl;
		cout << "Price................: " << price << endl;
		cout << "Year.................: " << year << endl;
	}

};

