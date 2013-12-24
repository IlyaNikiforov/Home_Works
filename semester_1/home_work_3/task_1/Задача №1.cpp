// Задача №1.cpp : Defines the entry point for the console application.
//
#include "iostream"
#include "stdio.h"
#include "string.h"
using namespace std;


int main()
{
	cout << "String checker" << endl;
	cout << "Enter first string:" << endl;
	const int n = 10;
	char s1[n];
	fgets(s1, n, stdin);
	cout << "Enter second string:" << endl;
	char s2[n];
	fgets(s2, n, stdin);
	int a[256] = {0};

	for (int i = 0; i < strlen(s1); i++)
	{
		a[int(s1[i])]++;
		a[int(s2[i])]--;
	}

	int k = 0;
	
	for (int i = 0; i < 256; i++)
		if (a[i] != 0)
		{
			cout << "This strings are not similar" << endl;
			cin >> k;
			return 0;
		}

	cout << "This strings are similar" << endl;
	cin >> k;
	return 0;
}

