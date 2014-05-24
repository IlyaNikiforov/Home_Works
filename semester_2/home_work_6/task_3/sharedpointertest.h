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
			SharedPointer<int> newPointer(*pointer);
			QVERIFY(newPointer.getCount() == 2);
			QVERIFY(*newPointer.getPointer() == 10);
			delete newPointer;
			QVERIFY(pointer->getCount() == 1);
		}

		void testAssignment()
		{
			SharedPointer<int> newPointer(new int(5));
			newPointer = *pointer;
			QVERIFY(pointer->getCount() == 2);
			QVERIFY(*pointer->getPointer() == 10);
			QVERIFY(newPointer.getCount() == 2);
			QVERIFY(*newPointer.getPointer() == 5);
		}

	private:
		SharedPointer<int> *pointer;
};
