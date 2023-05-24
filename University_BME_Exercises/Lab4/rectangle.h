#pragma once
class rectangle
{
private:
	float length;
	float width;
public:
	void setlength(float);
	void setwidth(float);
	float perimeter(float side);
	float area(float side);
	void print(float side);
};

