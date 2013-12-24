// Задача №4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"


using namespace std;

bool coprimeCheck(int i, int j)
{
		for (int k = 2; k <= j; k++) 
		{
			if (j % k == 0) 
			{
				if (i % k == 0)
				{
					return 0;
				}
			}
		}
	
	return 1;
}

void quickSort(int index[], float a[], int begin, int end)
{
	float k = 0;
	
	if (a[begin] >= a[begin + 1])
		k = a[begin];
	else 
		k = a[begin + 1];
	
	int i = begin;
	int j = end;
	
	while (i <= j)
	{
		while (k > a[i])
			i++;
		while (k < a[j])
			j--;

		if (i <= j)
		{
			swap(a[i], a[j]);
			swap(index[i], index[j]);
			i++;
			j--;
		}
		
	}

	if (j > begin)
		quickSort(index, a, begin, j);
	if (i < end)
		quickSort(index, a, i, end);
	}

void swap(float i, float j) 
{
	float a = 0;
	a = i;
	i = j;
	j = a;
}




int main()
{
	cout << "Programm of fractions sorting." << endl;
	cout << "Enter n:" << endl;
	int n = 0;
	cin >> n;
	const int p = n * (n - 1) / 2;
	
	int *fraction1 = new int [p];
	int *fraction2 = new int [p];
	float *a = new float [p];
	int *index = new int [p]; 

	for (int i = 0; i < p; i++)
		index[i] = i;
	
	int k = 0;
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (coprimeCheck(i, j))
			{
				fraction1[k] = j;
				fraction2[k] = i;
				a[k] = float(j) / float(i);
				k++;
			}
		}
	}

	quickSort(index, a, 0, k - 1);

	for (int l = 0; l < k; l++)
		cout << fraction1[index[l]] << "/" << fraction2[index[l]] << "  ";

	cin >> n;

	return 0;
}

