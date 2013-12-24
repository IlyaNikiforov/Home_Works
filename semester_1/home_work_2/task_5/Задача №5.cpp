// Задача №5.cpp : Defines the entry point for the console application.
//
#include "iostream"
#include "time.h"
#include "stdlib.h"

using namespace std;

int max(int a[], int i, int j)
{
	if (a[i] >= a[j])
		return i;
	else
		return j;
}

void swap(int &a, int &b)
{
	int p = 0;
	p = a;
	a = b;
	b = p;
}

void heaping(int a[], int begin, int end)
{
	int p = 0;
	
	if (2 * begin + 2 <= end)
		p = max(a, 2 * begin + 1, 2 * begin + 2);
	else 
		p = 2 * begin + 1;
	
	while ((a[begin] < a[p]) && (begin * 2 + 1 <= end))
	{
		swap(a[begin], a[p]);
		begin = p;
			
		if (2 * begin + 2 <= end)
			p = max(a, 2 * begin + 1, 2 * begin + 2);
		else if (2 * begin + 1 <= end)
			p = 2 * begin + 1;
	}
}

void heapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heaping(a, i, n - 1);

	for (int i = n - 1; i >= 1; i--)
	{
		swap(a[0], a[i]);
		heaping(a, 0, i - 1);
	}
}

int main()
{
	cout << "HeapSort" << endl;
	srand(time(NULL));
	cout << "Enter n:" << endl;
	int n = 0;
	cin >> n;
	int *a = new int [n];

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	
	cout << endl;

	heapSort(a, n);
	

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	
	cin >> n;
	delete[] a;
	return 0;
}

