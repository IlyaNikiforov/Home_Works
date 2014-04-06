#include "calculator.h"

void Calculator::addNumber(int number)
{
	if (state == none  || state == operationAdd || state == answer)
	{
		if (state == none || state == answer)
		{
			firstNumber = number;
			state = firstNumberEnter;
		}
		else
		{
			secondNumber = number;
			state = secondNumberEnter;
		}
		factor = 10;
	}

	else if (state == firstNumberEnter || state == secondNumberEnter)
	{
		if (state == firstNumberEnter)
			firstNumber = number + firstNumber * factor;
		else
			secondNumber = number + secondNumber * factor;
	}

	else
	{
		if (state == firstNumberFraction || state == firstNumberPoint)
		{
			firstNumber += factor * number;
			state = firstNumberFraction;
		}
		else if (state == secondNumberEnter || state == secondNumberPoint)
		{
			secondNumber += factor * number;
			state = secondNumberFraction;
		}
		factor /= 10;
	}
}


void Calculator::addPoint()
{
	if (state == firstNumberEnter)
		state = firstNumberPoint;
	else
		state = secondNumberPoint;
	factor = 0.1;
}

void Calculator::addOperation(QString newOperation)
{
	if (state == secondNumberFraction || state == secondNumberEnter)
		answerToFirstNumber();
	oper = newOperation;
	state = operationAdd;
}

double Calculator::calculateAnswer()
{
	if (oper == "+")
		return firstNumber + secondNumber;
	else if (oper == "-")
		return firstNumber - secondNumber;
	else if (oper == "*")
		return firstNumber * secondNumber;
	else
		return firstNumber / secondNumber;
}

void Calculator::answerToFirstNumber()
{
	firstNumber = calculateAnswer();
}

void Calculator::clearAll()
{
	firstNumber = 0;
	secondNumber = 0;
	oper = "";
	state = none;
}

bool Calculator::isCorrectOperation()
{
	return (secondNumber == 0 && oper == "/");
}
