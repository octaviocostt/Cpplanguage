#pragma once
#include "Equipment.h"


class Printer : public Equipment
{
public:
	Printer (int d, int p, int s) : Equipment(d,p,s) {}

	void print();

};

