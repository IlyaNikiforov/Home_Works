// Задача №1.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include "time.h"
#include "sort.h"

using namespace std;


int main()
{
	cout << "The problem of finding maximal element" << endl;
	cout << "Enter the size of your array:" << endl;
	int n = 0;
	cin >> n;
	int *a = new int [n];
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 50;
		cout << a[i] << " ";
	}

	cout << endl;
	quickSort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;

	for (int i = n - 1; i >= 0; i--)
	{
		if (i == 0)
			cout << "There are no equal elements in your array" << endl;
	
		else if (a[i] == a[i - 1])
		{
			cout << a[i];
			break;
		}
	}

	cin >> n;
	delete[] a;
	return 0;
}
