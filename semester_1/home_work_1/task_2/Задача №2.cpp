// Задача №2.cpp : Defines the entry point for the console application.
//
#include "iostream"

using namespace std;


int main()
{ 
	int a = 0;
	int b = 0;
	cout << "Enter dividend:" << endl;
	cin >> a;
	cout << "Enter divisor:" << endl;
	cin >> b;
	cout << a << "/" << b <<"=";
	int k = 0;
	while (a >= b) 
	{
		a -= b;
		k++;
	}
	cout << k << endl;
	cin >> a;
	return 0;
}

