#include <stdio.h>
#include <stdlib.h>


void main()
{
	// 1.
	const int i; // incorrect without assigning value
	// 2.
	const int i = 90; // correct
	i++; //incorrect because the variable "i" is constant, can not increment
	// 3.
	const int i = 90;
	int* p = &i; //incorrect we need define the pointer as a constant too.
	(*p)++;
	// 4.
	const int v[] = { 1,2,3 };
	v[1]++; // the vector is constant can not increment
	// 5.
	const int i = 255; // correct
	int v[i]; //correct
	// 6.
	char s[] = "Hello";
	const char* pc = s;
	pc[0] = 'h'; // incorrect the pointer is constant
	pc++;
	// 7.
	char s[] = "Hello";
	char* const cp = s;
	cp[0] = 'h';
	cp++; // incorrect the pointer is constant can not increment
	// 8.
	char s[] = "Hello";
	const char* const cpc = s; //incorrect
	cpc[0] = 'h'; 
	cpc++;
	//9.
	int j = 0;
	int const &i = j;
	i = 1; //incorrect the address of the variable i is equal to j, therefore are 0  
	const int& i = j;
	i = 1;
}