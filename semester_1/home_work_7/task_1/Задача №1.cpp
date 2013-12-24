// Задача №1.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include "fstream"

using namespace std;


int main()
{
	cout << "Results of testing problem" << endl;
	ifstream in ("input.txt");
	int n = 0;
	in >> n;
	int *a = new int [n];
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	for (int i = 3; i < n; i++)
		a[i] = 0;

	int num = 0;
	int task = 0;

	while (!in.eof())
	{
		in >> num >> task;
		a[num - 1] = task;
	}

	int temp = 0;

	for (int i = 3; i < n; i++)
	{
		if (a[i] == 0)
			continue;
		temp = a[i];
		a[i] = a[temp - 1];
		
		for (int j = 3; j < n; j++)
			if (a[j] == temp)
				a[j] = a[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
			cout << i + 1 << ": This student should be dismissed" << endl;
		else 
			cout << i + 1 << ": " << a[i] << endl;
	}

	delete[] a;
	cin >> n;
	return 0;
}

