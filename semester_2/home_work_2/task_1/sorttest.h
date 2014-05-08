#pragma once
#include "QObject"
#include "QtTest/QTest"
#include "qsort.h"
#include "heapsort.h"
#include "bubblesort.h"

class SortTest : public QObject
{
	Q_OBJECT
	public:
		explicit SortTest(QObject* parent = 0) : QObject(parent) {}
	private slots:

		/// initialization of array and classes
		void init()
		{
			bubbleSort = new BubbleSort;
			quickSort = new QSort;
			heapSort = new HeapSort;
			array = new int [6];
			array[0] = 4;
			array[1] = 1;
			array[2] = 3;
			array[3] = 6;
			array[4] = 0;
			array[5] = 2;
		}

		/// deleting array and classes
		void cleanup()
		{
			delete heapSort;
			delete quickSort;
			delete bubbleSort;
			delete[] array;
		}

		void testQuickSort()
		{
			quickSort->sort(array, 6);
			for (int i = 0; i < 6; i++)
				QVERIFY(array[i] == i);
		}

		void testHeapSort()
		{
			heapSort->sort(array, 6);
			for (int i = 0; i < 6; i++)
				QVERIFY(array[i] == i);
		}

		void testBubbleSort()
		{
			bubbleSort->sort(array, 6);
			for (int i = 0; i < 6; i++)
				QVERIFY(array[i] == i);
		}

	private:
		Sort *bubbleSort;
		Sort *heapSort;
		Sort *quickSort;
		int *array;
};
