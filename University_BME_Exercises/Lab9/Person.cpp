#include "Person.h"
#include <iostream>
#include <fstream>
using namespace std;

void Person::SetHeight(double h)
{
    height = h;
}

double Person::GetHeight()
{
    return height;
}

void Person::SetWeight(double w)
{
    weight = w;
}

double Person::GetWeight()
{
    return weight;
}

bool Person::operator==(const IComparable& theOther)
{
    Person& ptr = (Person&)theOther;
    if (ptr.age == age && ptr.height == height && ptr.weight == weight)
    {
        cout << "Both are equal." << endl;
        return true;
    }
    else
    {
        cout << "Both are not equal." << endl;
        return false;
    }
}

bool Person::operator>(const IComparable& theOther)
{
    Person& ptr = (Person&)theOther;
    if (ptr.age > age)
    {
        cout << "First one is greater than the other." << endl;
        cout << " " << endl;
        return true;
    }
    else
    {
        cout << "Second one is greater than the other." << endl;
        return false;
    }
    
}

// Implementation of ISerializable::Save
  void Person::Save(std::ostream& os)
  {
    os << (int)age << ';' << height << ';' << weight << endl;
  }

  // Implementation of ISerializable::Load 
  void Person::Load(std::istream& is)
  {
    double height; double weight; int age; char c;
    is >> age;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> height;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> weight;
    if(is)
    {
      this->age = age;
      this->height = height;
      this->weight = weight;

      cout << "Age: " << age << endl;
      cout << "Height: " << height << endl;
      cout << "Weight: " << weight << endl;
      cout << " " << endl;
    }
    else
    {
      cerr << "Error in input format." << endl;
    }


	// Write implementation for other member functions

  }
