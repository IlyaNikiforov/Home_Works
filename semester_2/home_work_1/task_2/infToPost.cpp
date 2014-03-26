#include "iostream"
#include "stack.h"
#include "arraystack.h"
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

bool priorityCheck(char a, ArrayStack <char> stack)
{
	int p1 = 0;
	int p2 = 0;
	
	if ((a == '-') || (a == '+'))
		p1 = 2;
	else if (a == '(')
		p1 = 0;
	else if (a == ')')
		p1 = 1;
	else
		p1 = 3;
	
	if ((stack.returnFirst() == '+') || (stack.returnFirst() == '-'))
		p2 = 2;
	else if ((stack.returnFirst() == '('))
		p2 = 0;
	else if ((stack.returnFirst() == ')'))
		p2 = 1;
	else 
		p2 = 3;

	return (p2 >= p1);
}

void infToPost(char str[], char ans[])
{
	int j = 0;
	ArrayStack <char> stack;

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
			if ((stack.returnSize() > 0) && (priorityCheck(str[i], stack)))
				{
					ans[j] = stack.returnFirst();
					j++;
					stack.deleteValue();
				}

			stack.addValue(str[i]);
		}

		else if (str[i] == '(')
			stack.addValue(str[i]);

		else if (str[i] == ')')
		{
			while (stack.returnFirst() != '(')
			{
				ans[j] =  stack.returnFirst();
				j++;
				stack.deleteValue();
			}
			
			stack.deleteValue();
		}
	}

	while (stack.returnSize() > 0)
	{
		ans[j] =  stack.returnFirst();
		j++;
		stack.deleteValue();
	}
}

