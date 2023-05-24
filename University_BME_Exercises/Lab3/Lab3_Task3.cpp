#include <stdlib.h> /* memory management */
#include <limits.h> /* INT_MAX */
#include <iostream>

using namespace std;

struct stack
{
	int elements;
	char* pData;
};

void stack_init(struct stack* s)
{
	s->elements = 0;
	s->pData = NULL;
}

void stack_cleanUp(struct stack* s)
{
	s->elements = 0;
	free(s->pData);
	s->pData == NULL;
}

int stack_push(struct stack* s, char newElement)
{
	int i;
	stack* ptrTemp = (stack*)malloc(sizeof(stack));;
	if (ptrTemp == NULL)
	{
		cout<<"Error alocation!\n";
		return 0;
	}
	else
	{
		if (s->elements == INT_MAX)
		{
			cout<<"Stack overflow";
			return -1;
		}
		else
		{
			for (i = 0; i < INT_MAX; i++)
			{

				ptrTemp->elements = newElement;
				ptrTemp->pData = s->pData;
				s->pData = ptrTemp->pData;

			}
		}
	}
	free(ptrTemp);
	return 0;
}

int stack_pop(struct stack* s)
{
	char* ptrTemp, value;
	int i;
	ptrTemp = s->pData;
	if (ptrTemp == NULL)
	{
		cout<<"Stack empty";
		return 0;
	}
	else 
	{
		s->pData = ptrTemp;
		ptrTemp = NULL;
		value = s->elements;
		free(ptrTemp);						
	}
	return value;
}

int stack_isEmpty(struct stack* s)
{
	if (s->pData == NULL)
		return 1;
	else
		return 0;
}

int main(void)
{
	struct stack s;
	char i;

	cout<<"Initializing stack...\n";
	stack_init(&s);

	for (i = 'A';i <= 'Z';i++)
	{
		cout<<"push: \t"<< i<<"%c";
		stack_push(&s, i);
	}

	while (!stack_isEmpty(&s))
	{
		cout << "pop: \t" << (char)stack_pop(&s) << " % c";
	}

	cout<< "pop: \t"<< stack_pop(&s)<< "%d\n";

	cout<<"Cleaning up stack...\n";
	stack_cleanUp(&s);
	return 0;
}
