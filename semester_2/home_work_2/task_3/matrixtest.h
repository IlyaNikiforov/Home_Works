#pragma once
#include "QObject"
#include "QtTest/QTest"
#include "matrixsort.h"
#include "iostream"
#include "time.h"

using namespace std;

class MatrixTest : public QObject
{
	Q_OBJECT
	public:
		explicit MatrixTest(QObject* parent = 0) : QObject(parent) {}
	private slots:

		void init()
		{
			sort = new MatrixSort;
		}

		void cleanup()
		{
			delete sort;
		}

		void test()
		{
			int N = 5;
			int M = 6;
			srand(time(NULL));
			int **matrix = new int *[N];

			for (int i = 0; i < N; i++)
				matrix[i] = new int [M];

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					matrix[i][j] = rand()%10;
					cout << matrix[i][j] << " ";
				}
				cout << endl;
			}

			sort->sortMatrix(matrix, N, M);

			cout << endl;

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					cout << matrix[i][j] << " ";
				}
				cout << endl;
			}

			for (int i = 0; i < N; i++)
				delete[] matrix[i];

			delete[] matrix;

		}

	private:
		MatrixSort *sort;
};
