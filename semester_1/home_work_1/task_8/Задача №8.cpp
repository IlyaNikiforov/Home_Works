// Задача №8.cpp : Defines the entry point for the console application.
//

#include "iostream"

using namespace std;

int factorial1(int n, int i, int fact)
{
	if (i > n)
		return fact;
	
	else
	{
		fact *= i;
		i++;
	
		return factorial1(n, i, fact);
	}
}

int factorial2(int n)
{	
	int fact = 1;
	
	for (int i = 1; i <= n; i++) 
		fact *= i;
	
	return fact;
}

int main()
{
	cout << "Enter n:" << endl;
	int n = 0;
	cin >> n;
	cout << "Choose the way of counting factorial:" << endl << "1:recursion" << endl << "2:iteration" << endl;
	int c = 0;
	cin >> c;
	
	if (c == 1) 
		cout << factorial1(n, 1, 1) << endl;

	else if (c == 2) 
		cout << factorial2(n) << endl;

	cin >> n;
	return 0;
}

