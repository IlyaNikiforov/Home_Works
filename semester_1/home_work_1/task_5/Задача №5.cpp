// Задача №5.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include "stdio.h"


using namespace std;


int main()
{
	
	char str[1000];
	int count = 0;
	cout << "Enter the text:" << endl;
	gets(str);
	
	for (int i = 0; i < 1000; i++)
	{
		if (str[i] == '(') 
			count++;
		
		else if (str[i] == ')') 
			count--;
		
		if (count < 0) 
		{
			cout << "The positions of brackets are not correct" << endl;
			break;
		}
	}
	
	if (count == 0) 
		cout << "brackets are placed correctly" << endl;
	
	else 
		cout << "The positions of brackets are not correct" << endl;
	
	cin >> count;

	return 0;
}
