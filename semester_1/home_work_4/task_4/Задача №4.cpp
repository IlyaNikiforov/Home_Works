#include "iostream"
#include "stdio.h"
#include "infToPost.h"
#include "postCount.h"

using namespace std;

int main()
{
	cout << "Strange calculator" << endl;
	cout << "Enter the expression, you want to count" << endl;
	char a[1000] = {'\0'};
	fgets (a, 100, stdin);
	char ans[1000] = {'\0'};
	infToPost(a, ans);
	cout << postCount(ans) << endl;
	int b = 0;
	cin >> b;
	return 0;
}
