#pragma once
#include <iostream>  //Libraries Used
#include <string.h>

using namespace std;

class Instruments  //Defining the mother class
{
protected: //Defining the member as protected
	string gen_type;
	string type;
	string description;      //Members variables
	double price;
public: //Defining function members as public
	Instruments(string gt, string t, string d, double p) : gen_type(gt), type(t), description(d), price(p) {} //Constructor that initializes the class

	virtual void insert_data() {} //Function that insert data into instruments file
	virtual void insert_acce(){} //Function that insert data into accessory file
	 virtual void search(){} //Function that search the data into instruments file
	 virtual void search_acce() {} //Function that search th data into accessory file
	 virtual void sale() {} //Function that register the sale into instruments file
	 virtual void sale_acce() {} //Function that register the sale into accessory file
	 virtual void overview(){} //Function that presents the number of sales into instruments file
	 virtual void overview_acce() {} //Function that presents the number of sales into accessory file
	 virtual bool file_empty(std::ifstream& pFile) { return true;} //Function that returns if the file is empty

};

