// Задача №1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;


int main()
{
	int x = 0;
	cout << "Enter x:" << endl;
	cin >> x;
	int x2 = 0;
	x2 = x * x;
	cout << "x+x^2+x^3+x^4=" << (x2 + x) * (x2 + 1) << endl;
	cin >> x;

	return 0;
}

