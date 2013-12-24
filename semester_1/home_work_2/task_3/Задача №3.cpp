// Задача №3.cpp : Defines the entry point for the console application.
//
#include "iostream"



using namespace std;

void partition(int n, int k, int a[])
{
	for (int i = a[k - 1]; i < n + 1; i++) 
	{
		a[k] = i;

		if (a[k] == n) 
		{
			for (int j = 1; j < k; j++)
				cout << a[j] << "+";

			cout << a[k] << endl;
		}


		else if (n - a[k] >= 0)
			partition(n - a[k], k + 1, a);
	}
}





int main()
{
	cout << "Program of numbers partition" << endl;
	cout << "Enter n:" << endl;
	int n = 0;
	cin >> n;
	int *a = new int [n + 1];
	a[0] = 1;
	partition(n, 1, a);


	cin >> n;
	delete[] a;
	return 0;
}

