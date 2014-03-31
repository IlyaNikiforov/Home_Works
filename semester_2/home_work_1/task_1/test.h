#pragma once
#include "QObject"
#include "QtTest/QTest"
#include "list.h"
#include "arraylist.h"
#include "linkedlist.h"

class ListTest : public QObject
{
	Q_OBJECT
	public:
		explicit ListTest(QObject* parent = 0) : QObject(parent) {}
	private slots:

		void init()
		{
			linkedList = new LinkedList;
			arrayList = new ArrayList;
		}

		void cleanup()
		{
			delete linkedList;
			delete arrayList;
		}

		void testIsEmpty()
		{
			QVERIFY(arrayList->getSize() == 0);
			QVERIFY(linkedList->getSize() == 0);
		}

		void testAddValue()
		{
			arrayList->addValue(10);
			QVERIFY(arrayList->getSize() == 1);
			QVERIFY(arrayList->isExist(10));

			linkedList->addValue(10);
			QVERIFY(linkedList->isExist(10));
			QVERIFY(linkedList->getSize() == 1);
		}

		void testDeleteValue()
		{
			arrayList->addValue(10);
			QVERIFY(arrayList->getSize() == 1);
			arrayList->deleteValue(10);
			QVERIFY(arrayList->getSize() == 0);

			linkedList->addValue(10);
			QVERIFY(linkedList->getSize() == 1);
			linkedList->deleteValue(10);
			QVERIFY(linkedList->getSize() == 0);
		}

		void testFull()
		{
			arrayList->addValue(10);
			arrayList->addValue(1);
			arrayList->addValue(2);
			arrayList->addValue(3);
			arrayList->addValue(4);
			QVERIFY(arrayList->getSize() == 5);
			arrayList->deleteValue(10);
			QVERIFY(arrayList->getSize() == 4);
			arrayList->deleteValue(4);
			QVERIFY(arrayList->getSize() == 3);

			linkedList->addValue(10);
			linkedList->addValue(1);
			linkedList->addValue(2);
			linkedList->addValue(3);
			linkedList->addValue(4);
			QVERIFY(linkedList->getSize() == 5);
			linkedList->deleteValue(10);
			QVERIFY(linkedList->getSize() == 4);
			linkedList->deleteValue(4);
			QVERIFY(linkedList->getSize() == 3);
		}



	private:
		ArrayList *arrayList;
		LinkedList *linkedList;
};
