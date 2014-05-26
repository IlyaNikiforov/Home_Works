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

		void testCopy()
		{
			SharedPointer<int> pointer(new int (10));
			SharedPointer<int> newPointer(pointer);
			QVERIFY(newPointer.getCount() == 2);
			QVERIFY(*newPointer.getPointer() == 10);
			QVERIFY(pointer.getCount() == 2);
		}

		void testAssignment()
		{
			SharedPointer<int> pointer(new int (10));
			SharedPointer<int> newPointer1(new int(9));
			SharedPointer<int> newPointer2(newPointer1);
			QVERIFY(newPointer2.getCount() == 2);
			QVERIFY(newPointer1.getCount() == 2);
			newPointer1 = pointer;
			QVERIFY(newPointer2.getCount() == 1);
			QVERIFY(newPointer1.getCount() == 2);
			QVERIFY(pointer.getCount() == 2);
			QVERIFY(*newPointer1.getPointer() == 10);
		}

};
