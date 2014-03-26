#pragma once

class Calculator
{
public:
	static double doOperation(int firstNumber, int secondNumber, char operation)
	{
		if (operation == '-')
			return double(firstNumber) - secondNumber;
		if (operation == '+')
			return double(firstNumber) + secondNumber;
		if (operation == '*')
			return double(firstNumber) * secondNumber;
		if (operation == ':')
			return double(firstNumber) / secondNumber;
	}
};


