// Задача №3.cpp : Defines the entry point for the console application.
//
#include "iostream"

using namespace std;


int main()
{
	cout << "Number changer" << endl;
	cout << "Enter your number:" << endl;
	int n = 0;
	cin >> n;
	double a[10] = {0};
	while (n > 0)
	{
		a[n % 10]++;
		n /= 10;
	}
	int i = 1;
	while (a[i] == 0)
		i++;
	cout << i;
	a[i]--;

	for (i = 0; i < 10; i++)
	{
		while (a[i] > 0)
		{
			cout << i;
			a[i]--;
		}
	}
	cin >> n;
	return 0;
}

