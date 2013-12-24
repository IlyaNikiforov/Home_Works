// Задача №4.cpp : Defines the entry point for the console application.
//

#include "iostream"

using namespace std;


int main()
{	int ticket = 0;
	int count = 0;
	
	for (int i = 0; i < 14; i++) 
	{
		for (int j = 0; j < 999; j++) 
		{ 
			if (j < 10) 
			{
				if (j == i) 
				{
					count ++;
				}
			}

			else if (j < 100) 
			{
				if (j % 10 + j / 10 == i) 
				{
					count ++;
				}
			}
			
			else if (j / 100 + (j % 100) / 10 + j % 10 == i) 
			{
				count++;
			}
			
		}
		ticket += count * count;
		count = 0;
	}

	cout << "There are " << ticket * 2 << " winning tickets" << endl;
	cin >> count;

	return 0;
}


