// Задача №3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "stack.h"
#include "stdio.h"

using namespace std;

bool numberCheck(char a)
{
	if ((int(a) >= int('0')) && (int(a) <= int('9')))
		return 1;
	else 
		return 0;
}

void doOperation (Stack *stack, char a)
{
	int b = stack->first->next->value;
	removeElement(stack);
	int c = stack->first->next->value;
	removeElement(stack);

	if (a == '+')
		addElement(stack, b + c);
	
	else if (a == '-')
		addElement(stack, b - c);

	else if (a == '*')
		addElement(stack, b * c);

	else if (a == '/')
		addElement(stack, b / c);
	
}

int main()
{
	cout << "Reverse Polish notation" << endl;
	cout << "Enter your expression:" << endl;
	char str[1000];
	fgets (str, 1000, stdin);
	cout << endl;
	const int n = strlen(str) - 1;

	Stack *stack = new Stack;
	createStack(stack);

	for (int i = 0; i < n; i++)
	{
		if (numberCheck(str[i]))
			addElement(stack, str[i] - '0');
		else if (str[i] != ' ')
			 doOperation (stack, str[i]);
	}

	cout << stack->first->next->value << endl;

	deleteStack(stack);
	int k = 0;
	cin >> k;
	return 0;
}

