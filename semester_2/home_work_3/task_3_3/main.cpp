#include "mainwindow.h"
#include <QApplication>
#include "calculatortest.h"

int main(int argc, char *argv[])
{
	CalculatorTest test;
	QTest::qExec(&test);

	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
