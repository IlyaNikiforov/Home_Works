// Задача №6.cpp : Defines the entry point for the console application.
//
#include "iostream"
#include "stdio.h"
#include "string.h"

using namespace std;


int main()
{
	cout << "Enter s:" << endl;
	char s[1000];
	fgets(s, 1000, stdin);
	cout << "Enter s1:" << endl;
	char s1[100];
	fgets(s1, 100, stdin);
	int k = 0;
	int c = 0;
	int length = strlen(s) - 1;
	int length1 = strlen(s1) - 1;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length1; j++)
		{
			if (s[j + i] == s1[j])
				k++;
			
			else break;
		}
		if (k == length1)
			c++;
		k = 0;
	}
	
	cout << c << endl;
	cin >> k;
	return 0;
}

