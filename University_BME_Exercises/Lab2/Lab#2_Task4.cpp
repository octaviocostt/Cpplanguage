#include <stdio.h>
#include <stdlib.h>

void invert(char* str)
{
	if (*str)
	{
		invert(str + 1);
		printf("%c", *str);
	}
}

int main()
{
	char word[99];
	
	printf("\nWrite a word: ");
	gets_s(word);

	printf("\nThe word is: ");
	
	invert(word);

	return 0;
}