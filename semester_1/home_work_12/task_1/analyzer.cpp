#include "iostream"
#include "analyzer.h"
#include "double.h"

using namespace std;

bool addition(char *&ch, int &brCounter) 
{
	if (!multiplication(ch, brCounter))
		return false;

	while (*ch == '+' || *ch == '-') 
	{
		ch++;

		if (!multiplication(ch, brCounter))
			return false;
	}

	if (brCounter > 0) 
	{
		if (*ch != ')')
			return false;
	} 

	else if (*ch != 0)
		return false;                

	return true;
}

bool bracket(char *&ch, int &brCounter)
{
	if (*ch == '(') 
	{
		brCounter++;
		ch++;

		if (!addition(ch, brCounter))
			return false;
		if (*ch == 0)
			return false;
		if (*ch == ')')
			brCounter--;
		else
			return false;
		ch++;
		return true;
	} 
	else
		return isDouble(ch);
}

bool multiplication(char *&ch, int &brCounter)
{
	if (!bracket(ch, brCounter))
		return false;

	while (*ch == '*' || *ch == '/') 
	{
		ch++;
		if (!bracket(ch, brCounter))
			return false;
	}
	return true;
}

bool isCorrectExpression(char *ch) 
{
	int brCounter = 0;
	return addition(ch, brCounter);
}