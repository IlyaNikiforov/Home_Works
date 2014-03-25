#pragma once

class Calculator
{
public:
    Calculator();
    double doOperation(int firstNumber, int secondNumber, char operation)
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


