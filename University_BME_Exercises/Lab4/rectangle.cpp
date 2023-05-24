#include "rectangle.h"
#include <iostream>

using namespace std;

void rectangle::setlength(float len)
{
	length = len;
}

void rectangle::setwidth(float wid)
{
	width = wid;
}

float rectangle::perimeter(float side)
{
	if (side == 1)
	{
		return (2 * length + 2 * width);
	}
	else if (side == 2)
	{
		return (2 * length + 2 * width);
	}
	else
		return 0;
}

float rectangle::area(float side)
{
	if (side == 1)
	{
		return (length*length);
	}
	else if (side == 2)
	{
		return length * width;
	}
	else 
		return 0;
	
}

void rectangle::print(float side)
{
	if (side == 1)
	{
		cout << "Length...: " << length<< endl;
		cout << "Width....: " << width << endl;
		cout << "Perimeter: " << perimeter(side) << endl;
		cout << "Area.....: " << area(side) << endl;
	}
	else if (side == 2)
	{
		cout << "Length...: " << length << endl;
		cout << "Width....: " << width << endl;
		cout << "Perimeter: " << perimeter(side) << endl;
		cout << "Area.....: " << area(side) << endl;
	}
	else if (side == 0)
	{
		cout << "Length...: " << length << endl;
		cout << "Width....: " << width << endl;
		cout << "Perimeter: " << perimeter(side) << endl;
		cout << "Area.....: " << area(side) << endl;
	}
}
