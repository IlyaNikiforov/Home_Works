#include <QObject>
#include <QtTest/QtTest>
#include <QString>
#include "bubblesort.h"

const int sizeOfArray = 10;

class BubbleSortTest: public QObject
{
	Q_OBJECT
	public:
			explicit BubbleSortTest(QObject* parent = 0) : QObject(parent) {}
		private slots:

			void intDecSortTest()
			{
				int array[sizeOfArray];
				for (int i = 0; i < sizeOfArray; i++)
					array[i] = qrand() % 50;
				IntDecCompare comparator;
				BubbleSort<int> sorter;
				sorter.sort(array, sizeOfArray, comparator);
				for (int i = 0; i < sizeOfArray - 1; i++)
					QVERIFY(array[i] <= array[i + 1]);
			}

			void intIncSortTest()
			{
				int array[sizeOfArray];
				for (int i = 0; i < sizeOfArray; i++)
					array[i] = qrand() % 50;
				IntIncCompare comparator;
				BubbleSort<int> sorter;
				sorter.sort(array, sizeOfArray, comparator);
				for (int i = 0; i < sizeOfArray - 1; i++)
					QVERIFY(array[i] >= array[i + 1]);
			}

			void QStringSortTest()
			{
				QString array[sizeOfArray] =
				{
					"aaa",
					"baa",
					"aba",
					"bba",
					"cba",
					"aab",
					"aac",
					"acb",
					"abc",
					"bbb"
				};

				QStringCompare comparator;
				BubbleSort<QString> sorter;
				sorter.sort(array, sizeOfArray, comparator);
				for (int i = 0; i < sizeOfArray - 1; i++)
					QVERIFY(!comparator(array[i], array[i + 1]));
			}

			void charSortTest()
			{
				char array[sizeOfArray] ={"agkcfebdh"};
				charCompare comparator;
				BubbleSort<char> sorter;
				sorter.sort(array, sizeOfArray, comparator);
				for (int i = 0; i < sizeOfArray - 1; i++)
					QVERIFY(array[i] <= array[i + 1]);
			}

		private:
			class IntDecCompare
			{
				public:
					bool operator()(const int &a, const int &b)
					{
						return a > b;
					}
			};

			class IntIncCompare
			{
				public:
					bool operator()(const int &a, const int &b)
					{
						return a < b;
					}
			};

			class QStringCompare
			{
				public:
					bool operator()(const QString &a, const QString &b)
					{
						return (QString::localeAwareCompare(a, b) < 0);
					}
			};

			class charCompare
			{
				public:
					bool operator()(const char &a, const char &b)
					{
						return a > b;
					}
			};

};
