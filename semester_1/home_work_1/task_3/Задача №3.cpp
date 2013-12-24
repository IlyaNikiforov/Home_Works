// Задача №3.cpp : Defines the entry point for the console application.
//

#include "stdlib.h"
#include "iostream"
#include "time.h"

using namespace std;


void reverse(int a[], int begin, int end) 
{
	for (int i = begin; i < (begin + end) / 2; i ++) 
	{
		a[i] = a[i] + a[begin + end - i - 1];
		a[begin + end - i - 1] = a[i] - a[begin + end - i - 1];
		a[i] = a[i] - a[begin + end - i - 1];
	}
}

void out(int a[], int begin, int end)
{
	for (int i = begin; i < end; i++) 
	{
		cout << a[i] << " ";
	}
	cout << endl;
}


int main()
{
	cout << "Enter the length of parts of massive." << endl << "Enter the length of first part:" << endl;
	int m = 0;
	cin >> m;
	cout << "Enter the length of second part:" << endl;
	int n = 0;
	cin >> n;
	srand(time(NULL));
	cout << "Your massive:" << endl;
	int *a = new int [n + m];
	
	for (int i = 0; i < n + m; i ++) 
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	
	cout << endl;
	reverse (a, 0, m);
	//out (a, 0, m);
	reverse (a, m, m + n);
	//out (a, m, n + m);
	reverse (a, 0, n + m);

	cout << "Your new massive:" << endl;
	out (a, 0, n + m);
	
	delete[] a;
	cin >> m;
	return 0;
}


