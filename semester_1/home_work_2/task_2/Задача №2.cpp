// Задача №2.cpp : Defines the entry point for the console application.
//

#include "iostream"

using namespace std;

int indpow (int a, int n)
{
	int x = 1;
 
	while ( n > 0 )
	{
		if (n & 1) 
			x *= a;
  
		n >>= 1;
		a *= a;
	}
	return x;
}
	
int main()
{
	cout << "The programm of number exponentiation" << endl;
	cout << "Enter number:" << endl;
	int a = 0;
	cin >> a;
	cout << "Enter exponent:" << endl;
	int n = 0;
	cin >> n;
	cout << a << "^" << n << "=" << indpow(a, n) << endl;
	cin >> n;
	return 0;
}

