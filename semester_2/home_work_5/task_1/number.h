#pragma once
#include "iostream"

using namespace std;

class Number : public Node
{
	public:
		Number(int number) : value(number) {}

		double calculateSubTree()
		{
			return value;
		}

		void printSubTree()
		{
			cout << value;
		}

		int value;
};


