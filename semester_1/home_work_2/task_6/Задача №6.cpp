// Задача №6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

void conversion(char a[], int b[], int &j)
{
	int k = 0;
	bool c = 1;
	int p = 1;
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] != ' ') 
		{
			if (a[i] == '-')
			{
				c = 0;
				i++;
			}
			while (a[k + i] != ' ')
				k++;
			for (int l = i + k ; l >= i; l--)
			{
				b[j] += (a[l]-'0') * p;
				p *= 10;
			}
			if (!c)
				b[j] = -b[j];
			c = 1;
			j++;
			p = 1;
			i += k;
			k = 0;
		}
	}
}


int main()
{
	cout << "Programm of polynomial printing" << endl;
	cout << "Enter coefficients:" << endl;
	char str[100];
	fgets(str, 100, stdin);
	int polyn[100] = {0};	
	int length = 0;
	conversion (str, polyn, length);
	
	for (int i = 0; i < length; i++)
		cout << polyn[i] << " ";
	
	cout << endl;
	cin >> length;
	return 0;
}

