#include <iostream>
#include "rectangle.h"

using namespace std;

int main()
{
	rectangle sides;
	float side;
	float length, width;
	cout << "*The sides of the rectangle can be 0, 1 or 2(lenght and width)*" << endl;
	cout << "Write the number of sides of the rectangle: " << endl;
	cin >> side;

		if (side == 0)
		{
			sides.setlength(side);
			sides.setwidth(side);
			sides.area(side);
			sides.perimeter(side);
			sides.print(side);
		}
		else if (side == 1)
		{
			cout << "Write the value of the side: " << endl;
			cin >> length;
			if (length < 0)
			{
				cout << "Invalid option --> The sides can not be negative" << endl;
				return 0;
			}
			else
			{
				sides.setlength(length);
				sides.setwidth(length);
				sides.area(side);
				sides.perimeter(side);
				sides.print(side);
			}
		}
		else if (side == 2)
		{
			cout << "Write the value of the length: " << endl;
			cin >> length;
			cout << "Write the value of the width: " << endl;
			cin >> width;
			if (length < 0 || width < 0)
			{
				cout << "Invalid option --> The sides can not be negative" << endl;
				return 0;
			}
			else {
				sides.setlength(length);
				sides.setwidth(width);
				sides.area(side);
				sides.perimeter(side);
				sides.print(side);
			}
		}
	return 0;
}