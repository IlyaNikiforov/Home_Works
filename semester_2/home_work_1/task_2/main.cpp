#include "iostream"
#include "pointerstack.h"
#include "arraystack.h"
#include "infToPost.h"
#include "postCount.h"

using namespace std;

int main()
{
	/*ArrayStack <int> stack;
	stack.addValue(3);
	stack.addValue(5);
	stack.addValue(6);
	cout << stack.returnFirst() << endl;
	stack.deleteValue();
	cout << stack.returnFirst() << endl;*/

	cout << "Strange calculator" << endl;
	cout << "Enter the expression, you want to count" << endl;
	char a[1000] = {'\0'};
	fgets (a, 100, stdin);
	char ans[1000] = {'\0'};
	infToPost(a, ans);
	cout << postCount(ans) << endl;
	return 0;
}
