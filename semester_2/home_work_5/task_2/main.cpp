#include "iostream"
#include "storage.h"
#include "storagetest.h"

using namespace std;

int main()
{
	StorageTest test;
	QTest::qExec(&test);
	return 0;
}
