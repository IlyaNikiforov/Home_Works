#include "iostream"
#include "analyzer.h"

using namespace std;

int main() 
{
	cout << "This program lexical analyzer." << endl;
	cout << "You can use real numbers, brackets and multiply/addition operations." << endl;
	cout << "Enter the expression:" << endl;
	char str[255];
	cin >> str;
	if (isCorrectExpression(str))
		cout << "The expression is correct." << endl;
	else
		cout << "The expression is incorrect." << endl;

	int n = 0;
	cin >> n;
	return 0;
}