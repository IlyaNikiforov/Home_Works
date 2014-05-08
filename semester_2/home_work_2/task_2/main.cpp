#include "printer.h"
#include "consoleprinter.h"
#include "fileprinter.h"
#include "matrixtest.h"
#include "iostream"

using namespace std;

int main()
{
	MatrixTest test;
	QTest::qExec(&test);
	return 0;
}
