#include "String.h"
#include <iostream>
#include <assert.h>

using namespace std;

namespace TheUltimateString
{
		String::String()
		{
			pData=NULL;
			elementsNum=0;
		}

		String::String(const String& string)
		{
			pData=NULL;
			copy(*this,string);
		}

		String::String(const char* str)
		{
			elementsNum = strlen(str);

			pData = new char[elementsNum + 1];

			for (int i = 0; i <= elementsNum; i++)
				pData[i] = str[i];
		}

		
		String::String(const char c, unsigned int times)
		{
			elementsNum=times;

			if(elementsNum==0)
			{
				pData=NULL;
				return;
			}

			pData=new char[elementsNum+1];
			for(unsigned int i=0;i<elementsNum;i++)
			{
				pData[i]=c;
			}
			pData[elementsNum]='\0';
		}


		void String::print(ostream& os)
		{
			for(unsigned int i=0;i<elementsNum;i++)
			{
				os<<pData[i];
			}
		}

		char& String::operator[](unsigned int pos)
		{
			static char ch = 0;
			if ((pos < 0) || (pos >= elementsNum)) return ch;
			else return pData[pos];
		}
		const char& String::operator[](unsigned int pos) const
		{
			if ((pos < 0) || (pos >= elementsNum)) return char(0);
			else return pData[pos];// TODO: inserir instrução return aqui
		}
		String String::operator+(const String& theOther) const
		{
			return concatenate(*this, theOther);
		}
		const String& String::operator+=(const String& theOther)
		{
			return *this = concatenate(*this, theOther);
				// TODO: inserir instrução return aqui
		}
		const String& String::operator=(const String& theOther)
		{
			copy(*this, theOther);
			return *this;                       // TODO: inserir instrução return aqui
		}
		bool String::operator==(const String& theOther) const
		{
			if (this->elementsNum != theOther.elementsNum)

				return false;

			for (unsigned int i = 0; i < this->elementsNum; i++)

			{
				if (this->pData[i] != theOther.pData[i])
					return false;

			}
			return true;
		}

		String::operator const char* () const
		{
			return pData;
		}

		String String::concatenate(const String & string1, const String & string2)
		{
			String s;
			s.elementsNum=string1.elementsNum+string2.elementsNum;

			if(s.elementsNum==0)
			{
				s.pData=NULL;
				return s;
			}

			s.pData=new char[s.elementsNum+1];

			for(unsigned int i=0;i<string1.elementsNum;i++)
			{
				s.pData[i]=string1.pData[i];
			}
			for(unsigned int j=string1.elementsNum;j<s.elementsNum;j++)
			{
				s.pData[j]=string2.pData[j-string1.elementsNum];
			}

			s.pData[s.elementsNum]='\0';
			return s;
		}

		bool String::compare(const String & string1, const String & string2)
		{
			if(string1.elementsNum!=string2.elementsNum)return false;

			for(unsigned int i=0;i<string1.elementsNum;i++)
			{
				if(string1.pData[i]!=string2.pData[i]) return false;
			}
			return true;
		}

		void String::copy(String &string1, const String &string2)
		{
			delete string1.pData;	
			string1.elementsNum=string2.elementsNum;
			if(string1.elementsNum==0)
			{
				string1.pData=NULL;
				return;
			}
			string1.pData=new char[string1.elementsNum+1];
			for(unsigned int i=0;i<string1.elementsNum;i++)
			{
				string1.pData[i]=string2.pData[i];
			}
			string1.pData[string1.elementsNum]='\0';
		}

}