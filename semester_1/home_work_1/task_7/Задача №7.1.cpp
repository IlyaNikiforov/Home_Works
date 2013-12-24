// Задача №7.1.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include "math.h"

using namespace std;

int main()
{
	cout << "Enter n:" << endl;
	int n = 0;
	cin >> n;
	int *a = new int [n];

	for (int i = 0; i < n; i++)
	a[i] = i + 1;

	int k = 2;

	for (int i = 1; i < sqrt(float(n)); i++)
	{
		if (a[i] != 0)
		{
		k = a[i];

		for (int j = 2 * i + 1; j <= n; j += k) 
			a[j] = 0;

		}
	}

	for (int i = 1; i < n; i++) 
		if (a[i] != 0)
			cout << a[i] << " ";

	delete[] a;
	cin >> k;
	return 0;
}

