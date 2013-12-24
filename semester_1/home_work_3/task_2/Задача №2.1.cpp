// Задача №2.1.cpp : Defines the entry point for the console application.
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
	int p = n * n;
	int i = n / 2;
	int j = n / 2;
	int l = 0;

	for (int k = 0; k <= n; k++)
	{
		if (k % 2)
		{
			for (int m = 0; m < k; m++, i++)
			{
				l++;
				if (l > p)
					break;
				cout << a[i][j] << " ";
			}
			for (int m = 0; m < k; m++, j++)
			{
				l++;
				if (l > p)
					break;
				cout << a[i][j] << " ";
				}
		}

		else 
		{
			for (int m = 0; m < k; m++, i--)
			{
				l++;
				if (l > p)
					break;
				cout << a[i][j] << " ";
			}
		
			for (int m = 0; m < k; m++, j--)
			{
				l++;
				if (l > p)
					break;
				cout << a[i][j] << " ";
			}
		}

	}

	for (int i = 0; i < n; i++)
		delete[] a[i];

	delete[] a;
	
	cin >> l;
	return 0;
}

