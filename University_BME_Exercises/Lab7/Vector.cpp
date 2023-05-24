#include "Vector.h"

using namespace std;

Vector::Vector(const Vector& theOther)
{
	elementNum = theOther.elementNum; //Copying constructor
	pData = theOther.pData;
}

void Vector::clear()
{
	delete[]pData; //Clearing all the data of the pointer
}

void Vector::erase(unsigned int position)
{
	for (int i = position; i < 10; ++i) {
		pData[i] = pData[i + 1];           // Changing the given position with the next one
	}
	pData -= 1;//Defining that the pointer has one less element
}

int& Vector::at(unsigned int position)
{
	int op;
	int newelement;
	cout << "Do you want to change the element(1 - Yes or any to No): "; 
	cin >> op;
	if (op == 1)
	{
		cout << "Write the new element: ";
		cin >> newelement;
		pData[position] = newelement;   //Adding the new element to the given position
		return pData[position];
	}
	else
	{
		return pData[position]; //Returning the element at the given position
	}
	
}

const int& Vector::at(unsigned int position) const
{
	return pData[position];// //Returning the element at the given position
}

bool Vector::insert(unsigned int position, int element)
{
	pData[position] = element; //Inserting the element at the given position
	return true;
}

const Vector& Vector::operator=(const Vector& theOther)
{
	elementNum = theOther.elementNum;
	pData = theOther.pData;            //Copying as the copy constructor
	return *this;
}

int& Vector::operator[](unsigned int position)
{
	if (position > 10) {
		cout << "Index out of bounds" << endl; 
		return pData[0];					//If the position doesn't exist then return the first element
	}
	else
	return pData[position];             //Return the element at the given position
}

const int& Vector::operator[](unsigned int position) const
{
	if (position > 10) {
		cout << "Index out of bounds" << endl;
		return pData[0];
	}
	else
		return pData[position];
}

std::ostream& operator<<(std::ostream& os, const Vector& v) 
{
	cout << endl;
	for (int i = 0; i < 10;i++)
	{
		if (v.pData[i] < 0) // If the element is minor then 0 then it is memory garbage
		{
			v.pData[i] = 0; //Return 0 at the position with the memory garbage
			os << v.pData[i] << " ";
		}
		else
		{
			os << v.pData[i] << " "; //Print the elements of the vector
		}
	}
	return os;
}
