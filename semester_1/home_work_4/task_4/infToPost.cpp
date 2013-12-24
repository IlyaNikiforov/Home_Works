// Задача №2.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include "CharStack.h"
#include "stdio.h"
#include "string.h"

using namespace std;

bool numberCheck(char a)
{
	return (a >= '0') && (a <= '9');
}

bool functionCheck(char a)
{
	return (a == '/') || (a == '*') || (a == '-') || (a == '+');
}

bool priorityCheck(char a, Stack *stack)
{
	int p1 = 0;
	int p2 = 0;
	
	if ((a == '-') || (a == '+'))
		p1 = 1;
	else
		p1 = 2;
	
	if ((stack->first->next->value == '+') || (stack->first->next->value == '-') || (stack->first->next->value == '('))
		p2 = 1;
	else 
		p2 = 2;

	return (p2 > p1);
}

void infToPost(char str[], char ans[])
{
	int j = 0;
	Stack *stack = new Stack;
	createCharStack(stack);

	const int n = strlen(str);
	
	for (int i = 0; i < n; i++)
	{
		if (numberCheck(str[i]))
		{
			ans[j] = str[i];
			j++;
		}
		
		else if (functionCheck(str[i]))
		{
			if ((stack->first->next != nullptr) && (priorityCheck(str[i], stack)))
				{
					ans[j] = stack->first->next->value;
					j++;
					removeCharElement(stack);
				}

			addCharElement (stack, str[i]);
		}

		else if (str[i] == '(')
			addCharElement (stack, str[i]);

		else if (str[i] == ')')
		{
			while (stack->first->next->value != '(')
			{
				ans[j] =  stack->first->next->value;
				j++;
				removeCharElement(stack);
			}
			
			removeCharElement(stack);
		}
	}

	while (stack->first->next != nullptr)
	{
		ans[j] =  stack->first->next->value;
		j++;
		removeCharElement(stack);
	}

	deleteCharStack(stack);
}

