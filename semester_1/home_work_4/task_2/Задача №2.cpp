// Задача №2.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include "stack.h"
#include "stdio.h"

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

int main()
{
	cout << "Shunting-yard algorithm" << endl;
	cout << "Enter your expression" << endl;
	char str[1000];
	fgets(str, 1000, stdin);
	cout << endl;
	
	Stack *stack = new Stack;
	createStack(stack);

	const int n = strlen(str);
	
	for (int i = 0; i < n; i++)
	{
		if (numberCheck(str[i]))
			cout << str[i];
		
		else if (functionCheck(str[i]))
		{
			if ((stack->first->next != nullptr) && (priorityCheck(str[i], stack)))
				{
					cout << stack->first->next->value;
					removeElement(stack);
				}

			addElement (stack, str[i]);
		}

		else if (str[i] == '(')
			addElement (stack, str[i]);

		else if (str[i] == ')')
		{
			while (stack->first->next->value != '(')
			{
				cout << stack->first->next->value;
				removeElement(stack);
			}
			
			removeElement(stack);
		}
	}

	while (stack->first->next != nullptr)
	{
		cout << stack->first->next->value;
		removeElement(stack);
	}

	deleteStack(stack);
	int k = 0;
	cin >> k;
	return 0;
}

