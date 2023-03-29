#pragma once
#include "Instruments.h"
#include "Accessory.h"
#include <iostream>      //Libraries used
#include <string.h>
#include <fstream>
//#include <Windows.h>
#include <string>


using namespace std;

class Strings : public Instruments //Defining the class Strings derived from the Instruments class
{
protected:
	int stock_count; //Auxiliary variable used to count the number of sales
public:
	Strings(string gt, string t, string d, double p) : Instruments(gt, t, d, p) {} //Constructor that initializes the class derived from Instruments class
	 
	void insert_data();
	void insert_acce();
	void search();
	void search_acce();    //Functions derived from the Instruments class
	void sale();           //that have the same application
	void sale_acce();
	void overview();
	void overview_acce();
	bool file_empty(ifstream& pFile);
};


