#include "String.h"

using namespace std;
using namespace HomeMadeString;

HomeMadeString::String::String()
{
}


HomeMadeString::String::String(String& r) 
{
	char* pdata;
	int elementnum = strlen(r.pData + 1);
	//pdata = new char[elementnum];
	//strcpy(pdata, r.pData);
	pdata = r.pData;
}

HomeMadeString::String::String(const char* str) 
{
	string string = str;
}

HomeMadeString::String::String(const char c, int times) 
{
	times = strlen(this->pData);
	string str;
	str = times * c;
}

HomeMadeString::String::~String()
{
	delete[]this->pData;
}

void HomeMadeString::String::getStr(char* pBuff)
{
	pBuff = new char[this->elementNum];
	strcpy(pBuff, this->pData);
}

void HomeMadeString::String::print(std::ostream& os)
{
	for (int i = 0;i < elementNum;i++)
	{
		os << pData[i];
	}
}

char HomeMadeString::String::getChar(int pos)
{
	char str[50];
	for (int i = 0;i != pos; i++)
	{
		if (i = pos)
		{
			cout << str[i] << endl;
		}
	}
	return 0;
}

String HomeMadeString::String::concatenate(String string1, String string2)
{
	char* p1 = string1.pData;
	char* p2 = string2.pData;

	return strcat(p1,p2);
}

bool HomeMadeString::String::compare(const String& string1, String string2)
{
	char* p1 = string1.pData;
	char* p2 = string2.pData;
	strcmp(p1, p2);
	if (true)
		return true;
	else
		return false;
	
}

void HomeMadeString::String::copy(String& string1, String string2)
{
	const char* p1 = string1.pData;
	char* p2 = string2.pData;
	strcpy(p2, p1);
}



