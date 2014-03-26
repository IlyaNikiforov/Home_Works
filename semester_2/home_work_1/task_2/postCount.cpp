#include "iostream"
#include "stack.h"
#include "pointerstack.h"
#include "string.h"

using namespace std;

bool isNumber(char a)
{
	return (a >= '0') && (a <= '9');
}

void doOperation (PointerStack <int> *stack, char a)
{
    int b = stack->returnFirst();
    stack->deleteValue();
    int c = stack->returnFirst();
    stack->deleteValue();

	if (a == '+')
        stack->addValue(b + c);
	
	else if (a == '-')
        stack->addValue(c - b);

	else if (a == '*')
        stack->addValue(b * c);

	else if (a == '/')
        stack->addValue(c / b);
	
}

int postCount(char str[])
{
	const int n = strlen(str);
    PointerStack <int> *stack = new PointerStack <int>;

	for (int i = 0; i < n; i++)
	{
		if (isNumber(str[i]))
            stack->addValue(str[i] - '0');
		else if (str[i] != ' ')
			 doOperation (stack, str[i]);
	}
    int tmp = stack->returnFirst();
    delete stack;
	return tmp;
}

