#include "iostream"
#include "storage.h"
#include "storagetest.h"

using namespace std;

int main()
{
	ListTest test;
	QTest::qExec(&test);
	return 0;
}
