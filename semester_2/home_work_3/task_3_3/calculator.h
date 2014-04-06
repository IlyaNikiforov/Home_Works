#pragma once
#include "QString"

enum States
{
	none,
	firstNumberEnter,
	firstNumberPoint,
	firstNumberFraction,
	operationAdd,
	secondNumberEnter,
	secondNumberPoint,
	secondNumberFraction,
	answer
};

class Calculator
{
	public:
		Calculator() : state(none) {}
		///Adding new information to calculator after every clicking
		void addNumber(int number);
		void addPoint();
		void addOperation(QString newOperation);
		double calculateAnswer();
		void answerToFirstNumber();
		void clearAll();
		bool isCorrectOperation();
		int state;

	private:
		double firstNumber;
		double secondNumber;
		double factor;
		QString oper;

};
