// Задача №11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdlib.h"
#include "iostream"
#include "time.h"

using namespace std;

void sort(int a[], int begin, int end)
{
	int k = 0;
	
	if (a[begin] >= a[begin + 1])
		k = a[begin];
	else 
		k = a[begin + 1];
	
	int i = begin;
	int j = end;
	int swap = 0;
	
	while (i <= j)
	{
		while (k > a[i])
			i++;
		while (k < a[j])
			j--;

		if (i <= j)
		{
			swap = a[j];
			a[j] = a[i];
			a[i] = swap;
			i++;
			j--;
		}
		
	}

	if (j > begin)
		sort(a, begin, j);
	if (i < end)
		sort(a, i, end);
	}

int main()
{
	cout << "The QuickSort programm" << endl;
	srand(time(NULL));
	cout << "Enter the size of your array:" << endl;
	int n;
	cin >> n;
	int *a = new int [n];
	for (int i = 0; i < n; i++) 
	{
		a[i]=rand () % 100;
		cout << a[i] << " ";
	}

	cout << endl;
	
	sort(a, 0, n - 1);
	
	cout << endl;
	
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	
	cin >> n;
	return 0;
}

