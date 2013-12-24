#include "iostream"
#include "string.h"

const int base = 2;

using namespace std;

long power(long a, long k) 
{
	long b = 1;
	while (k) {
		if ((k % 2) == 0) {
			k = k / 2;
			a = a * a;
		} else {
			k--;
			b = b * a;
		}
	}
	return b;
}

void hasher(char *str1, char *str2, int len, int &h1, int &h2) 
{
	h1 = 0;
	h2 = 0;
	for (int i = 0; i < len; i++)
	{
		h1 = (h1 * base + str1[i]);
		h2 = (h2 * base + str2[i]);
	}
}

int reHash(int old, int subt, int add, int d) 
{
	return ((old - subt * d) * base + add);
}

void search(char *str, char *ptr)
{
	int sLen = strlen(str);
	int pLen = strlen(ptr);
	int d = power(base, pLen - 1);
	int sum = 0;

	int p = 0;
	int t = 0;
	hasher(ptr, str, pLen, p, t);

	for (int i = 0; i <= sLen - pLen; i++)
	{
		if (p == t)
		{
			bool f = true;
			for (int j = 0; j < pLen; j++)
				if (ptr[j] != str[i + j])
				{
					f = false;
					break;
				}
				if (f)
				{
					cout << i + 1 << " ";
					sum++;
				}
		}
		if (i < sLen - pLen)
			t = reHash(t, str[i], str[i + pLen], d);
	}
	cout << endl << sum;
}

int main()
{
	const int arLen = 255;
	char str[arLen];
	char pattern[arLen];

	cout << "Rabin-Karp algorithm" << endl;
	cout << "Enter the string:" << endl;

	cin.getline(str, arLen);
	cout << "Enter the string to check:" << endl;
	cin.getline(pattern, arLen);
	
	search(str, pattern);

	int n = 0;
	cin >> n;
	return 0;
}