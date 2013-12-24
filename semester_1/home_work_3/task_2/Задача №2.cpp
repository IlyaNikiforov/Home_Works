// Задача №2.cpp : Defines the entry point for the console application.
//
#include "iostream"

using namespace std;


int main()
{
	cout << "Matrix changing" << endl;
	cout << "Enter the size of matrix" << endl;
	int n = 0;
	cin >> n;
	int **a = new int *[n];
	
	for (int i = 0; i < n; i++)
		a[i] = new int [n];

	int *b = new int [n * n];
	int k = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = k;
			cout << a[i][j] << " ";
			k++;
		}
		cout << endl;
	}
	
	cout << endl;
	int i = 0;
	int j = 0;
	int l = 0;
	
	for (int k = 0; k <= n / 2; k++)
	{
		i = k;
		j = k;
		
		b[l] = a[i][j];
		cout << b[l] << " ";
		l++;
		if (l >= n * n)
			break;
		
		while (j < n - k - 1)
		{
			j++;
			b[l] = a[i][j];
			cout << b[l] << " ";
			l++;
			if (l >= n * n)
				break;
		}
		
		i++;
		
		b[l] = a[i][j];
		cout << b[l] << " ";
		l++;
		if (l >= n * n)
			break;
		
		while (i < n - k - 1)
		{
			i++;
			b[l] = a[i][j];
			cout << b[l] << " ";
			l++;
			if (l >= n * n)
				break;
		}
		
		j--;

		b[l] = a[i][j];
		cout << b[l] << " ";
		l++;
		if (l >= n * n)
			break;

		while (j >= k + 1)
		{
			j--;
			b[l] = a[i][j];
			cout << b[l] << " ";
			l++;
			if (l >= n * n)
				break;
		}
		
		i--;

		b[l] = a[i][j];
		cout << b[l] << " ";
		l++;
		if (l >= n * n)
				break;

		while (i > k + 1)
		{
			i--;
			b[l] = a[i][j];
			cout << b[l] << " ";
			l++;
			if (l >= n * n)
				break;
		}
		
		
	}

	cout << endl;
	delete[] a;
	delete[] b;
	cin >> n;
	return 0;
}

