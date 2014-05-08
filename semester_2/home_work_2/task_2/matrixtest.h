#pragma once
#include "QObject"
#include "QtTest/QTest"
#include "printer.h"
#include "consoleprinter.h"

class MatrixTest : public QObject
{
	Q_OBJECT
	public:
		explicit MatrixTest(QObject* parent = 0) : QObject(parent) {}
	private slots:

		void init()
		{
			printer = new ConsolePrinter;
		}

		void cleanup()
		{
			delete printer;
		}

		void test()
		{
			int **matrix = new int *[5];
			for (int i = 0; i < 5; i++)
			{
				matrix[i] = new int[5];
			}
			int k = 0;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					matrix[i][j] = k;
					k++;
					//cout << matrix[i][j] << " ";
				}
				//cout << endl;
			}
			printer->transfer(matrix, 5);
			printer->print();

			for (int i = 0; i < 5; i++)
			{
				delete[] matrix[i];
			}

			delete[] matrix;
		}

	private:
		ConsolePrinter *printer;
};
