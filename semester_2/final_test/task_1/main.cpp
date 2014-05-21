#include "sorttest.h"

int main()
{
	BubbleSortTest test;
	QTest::qExec(&test);

	return 0;
}
