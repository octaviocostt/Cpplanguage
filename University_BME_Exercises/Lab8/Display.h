#pragma once
#include "Equipment.h"

class Display : public Equipment
{
public:
	Display(int d, int p, int y) : Equipment(d, p, y){}
	void print();
};

