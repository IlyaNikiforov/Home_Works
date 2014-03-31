#include "priorityqueue.h"
#include "queuetest.h"

int main()
{
	QueueTest test;
	QTest::qExec(&test);

	return 0;
}
