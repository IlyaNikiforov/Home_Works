#include "iostream"
#include "graphtest.h"

using namespace std;

int main()
{
	GraphTest graphTest;
	QTest::qExec(&graphTest);
	return 0;
}
