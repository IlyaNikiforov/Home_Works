// Задача №10.cpp : Defines the entry point for the console application.
//
#include "iostream"


using namespace std;


int main()
{
	cout << "Enter the length of the text:" << endl;
	int n = 0;
	cin >> n;
	char  *str = new char [n];
	bool count = 1;
	cout << "Enter text:" << endl;
	cin >> str;
	for (int i = 0; i < n; i ++)
	{
		if (str[i] != str[n - i - 1]) 
		{
			cout << "This is not palindrome" << endl;
			count = 0;
			break;
		}
	}
	
	if (count == 1)
		cout << "This is palindrome" << endl;
	
	
	cin >> count;
	delete[] str;
	return 0;
}

