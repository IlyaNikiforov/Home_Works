// Задача №3.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include "intStack.h"
#include "stdio.h"
#include "string.h"

using namespace std;

bool isNumber(char a)
{
	return (a >= '0') && (a <= '9');
}

void doOperation (Stack *stack, char a)
{
	int b = stack->first->next->value;
	removeIntElement(stack);
	int c = stack->first->next->value;
	removeIntElement(stack);

	if (a == '+')
		addIntElement(stack, b + c);
	
	else if (a == '-')
		addIntElement(stack, b - c);

	else if (a == '*')
		addIntElement(stack, b * c);

	else if (a == '/')
		addIntElement(stack, b / c);
	
}

int postCount(char str[])
{
	const int n = strlen(str);
	Stack *stack = new Stack;
	createIntStack(stack);

	for (int i = 0; i < n; i++)
	{
		if (isNumber(str[i]))
			addIntElement(stack, str[i] - '0');
		else if (str[i] != ' ')
			 doOperation (stack, str[i]);
	}
	int tmp = stack->first->next->value;
	deleteIntStack(stack);
	return tmp;
}

