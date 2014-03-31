#pragma once
#include "QObject"
#include "QtTest/QTest"
#include "pointerstack.h"
#include "arraystack.h"

class StackTest : public QObject
{
	Q_OBJECT
	public:
		explicit StackTest(QObject* parent = 0) : QObject(parent) {}
	private slots:

		void init()
		{
			arrayStack = new ArrayStack <int>;
			pointerStack = new PointerStack <int>;
		}

		void cleanup()
		{
			delete pointerStack;
			delete arrayStack;
		}

		void testIsEmpty()
		{
			QVERIFY(arrayStack->getSize() == 0);
			QVERIFY(pointerStack->getSize() == 0);
		}

		void testAddValue()
		{
			arrayStack->addValue(10);
			QVERIFY(arrayStack->getSize() == 1);
			QVERIFY(arrayStack->returnFirst() == 10);

			pointerStack->addValue(10);
			QVERIFY(pointerStack->returnFirst() == 10);
			QVERIFY(pointerStack->getSize() == 1);
		}

		void testDeleteValue()
		{
			arrayStack->addValue(10);
			QVERIFY(arrayStack->getSize() == 1);
			arrayStack->deleteValue();
			QVERIFY(arrayStack->getSize() == 0);

			linkedList->addValue(10);
			QVERIFY(pointerStack->getSize() == 1);
			pointerStack->deleteValue();
			QVERIFY(pointerStack->getSize() == 0);
		}

		void testFull()
		{
			arrayStack->addValue(10);
			arrayStack->addValue(1);
			arrayStack->addValue(2);
			arrayStack->addValue(3);
			arrayStack->addValue(4);
			QVERIFY(arrayStack->getSize() == 5);
			QVERIFY(arrayStack->returnFirst() == 4);
			arrayStack->deleteValue();
			QVERIFY(arrayStack->getSize() == 4);
			QVERIFY(arrayStack->returnFirst() == 3);
			arrayStack->deleteValue();
			QVERIFY(arrayStack->getSize() == 3);

			pointerStack->addValue(10);
			pointerStack->addValue(1);
			pointerStack->addValue(2);
			pointerStack->addValue(3);
			pointerStack->addValue(4);
			QVERIFY(pointerStack->getSize() == 5);
			QVERIFY(pointerStack->returnFirst() == 4);
			pointerStack->deleteValue();
			QVERIFY(pointerStack->getSize() == 4);
			QVERIFY(pointerStack->returnFirst() == 3);
			pointerStack->deleteValue();
			QVERIFY(pointerStack->getSize() == 3);
		}



	private:
		ArrayStack <int> *arrayStack;
		PointerStack <int> *pointerStack;
};
