#pragma once
#include "Instruments.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;


class Percussion : public Instruments     //Defining the class Percussion derived from the Instruments class
{
protected:
	int stock_count;
public:
	Percussion(string gt, string t, string d, double p) : Instruments(gt, t, d, p) {}
	void insert_data();
	void insert_acce();
	void search();
	void search_acce();                //Functions works in the same way but for PERCUSSION type
	void sale();
	void sale_acce();
	void overview();
	void overview_acce();
	bool file_empty(ifstream& pFile);
};


