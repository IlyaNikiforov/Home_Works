// Задача №9.cpp : Defines the entry point for the console application.
//

#include "iostream"

using namespace std;


int main()
{
	cout << "Enter a:" << endl;
	int a = 0;
	cin >> a;
	cout << "Enter n:" << endl;
	int n = 0;
	cin >> n;
	long double ans = 1;

	for (int i = 0; i < n; i ++)
		ans *= a;

	cout << a << "^" << n << "=" << ans << endl;

	cin >> n;
	return 0;
}

