#include "Printer.h"

void Printer::print()
{
	cout << "Identification number: " << this->ID << endl;
	cout << "Price................: " << this->price << endl;
	cout << "Printing Speed.......: " << this->year << endl;
}
