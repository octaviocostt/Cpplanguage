#include "circle.h"
#include <iostream>

using namespace std;

int main()
{
	float radius;
	circle r;

	cout << "Write the radius of the circle:" << endl;
	cin >> radius;

	if(radius < 0)
	{
		cout << "Invalid option --> The radius can not be negative" << endl;
		return 0;
	}
	else {
		r.setradius(radius);
		r.circumference();
		r.area();
		r.diameter();
		r.print();
	}
	return 0;
}
