#pragma once
#include <QObject>
#include <QTtest/QTest>
#include "sharedpointer.h"
#include "iostream"


class SharedPointerTest : public QObject
{
	Q_OBJECT

	public:
		explicit SharedPointerTest(QObject *parent = 0) : QObject(parent) {}

	private slots:

		void init()
		{
			pointer = new SharedPointer<int> (new int(10));
		}

		void cleanup()
		{
			delete pointer;
		}

		void testCopy()
		{
			SharedPointer<int> *newPointer = new SharedPointer<int>(*pointer);
			QVERIFY(newPointer->getCount() == 2);
			QVERIFY(*newPointer->getPointer() == 10);
			delete newPointer;
			QVERIFY(pointer->getCount() == 1);
		}

		void testAssignment()
		{
			SharedPointer<int> *newPointer1 = new SharedPointer<int>(new int(9));
			SharedPointer<int> newPointer2(*newPointer1);
			QVERIFY(newPointer2.getCount() == 2);
			QVERIFY(newPointer1->getCount() == 2);
			newPointer1 = pointer;
			//QVERIFY(newPointer2.getCount() == 1);
			QVERIFY(newPointer1->getCount() == 2);
			QVERIFY(pointer->getCount() == 2);
			QVERIFY(*newPointer1->getPointer() == 10);
			delete newPointer1;
		}

	private:
		SharedPointer<int> *pointer;
};
