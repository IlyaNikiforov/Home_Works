#pragma once

class Calculator
{
public:
	/// function receives two numbers and operation. Then returns answer
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


