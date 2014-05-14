#include "iostream"
#include "set.h"
#include "settest.h"

using namespace std;

int main()
{
	SetTest test;
	QTest::qExec(&test);
	return 0;
}
