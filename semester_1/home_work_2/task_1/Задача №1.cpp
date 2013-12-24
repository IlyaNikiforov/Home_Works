// Задача №1.cpp : Defines the entry point for the console application.
//

#include "iostream"

using namespace std;

int fibonacci1(int n)
{
	if ((n == 1) || (n == 2))
		return 1;
	else 
		return fibonacci1(n - 1) + fibonacci1(n - 2);
}

int fibonacci2(int n)
{
	int fib1 = 1;
	int fib2 = 1;
	int sum = 0;

	if ((n == 1) || (n == 2))
		return 1;
	
	for (int i = 2; i < n; i++) 
	{
		sum = fib1 + fib2;
		fib1 = fib2;
		fib2 = sum;
	}

	return sum;
}



int main()
{
	cout << "Programm of counting the Fibonacci numbers" << endl;
	cout << "Enter n:" << endl;
	int n = 0;
	cin >> n;
	cout << "Choose the way of counting the Nth number:\n0: recursive\n1: iterative" << endl; 
	bool k;
	cin >> k;
	
	if (!k) 
		cout << "F(" << n << ")=" <<  fibonacci1(n) << endl;

	else 
		cout << "F(" << n << ")=" <<  fibonacci2(n) << endl;
	
	cin >> k;
	return 0;
}

