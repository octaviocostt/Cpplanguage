#include "circle.h"
#include<iostream>

using namespace std;

void circle::setradius(float r)
{
	radius = r;
}

float circle::circumference()
{
	float pi = 3.14;
	return (radius*pi*2);
}

float circle::area()
{
	float pi = 3.14;
	return (radius*radius*pi);
}

float circle::diameter()
{
	return (radius*2);
}

void circle::print()
{
	cout << "Radius.......:" << radius << endl;
	cout << "Circumference:" << circumference ()<< endl;
	cout << "Area.........:" << area ()<< endl;
	cout << "Diameter.....:" << diameter() << endl;
}
