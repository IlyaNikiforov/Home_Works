#include "sharedpointer.h"
#include "sharedpointertest.h"

int main()
{
	SharedPointerTest test;
	QTest::qExec(&test);
	return 0;
}
