#pragma once
#include <QObject>
#include <QtTest/QTest>
#include "calculator.h"

class CalculatorTest : public QObject
{
	Q_OBJECT

	public:
		explicit CalculatorTest(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void testSum()
		{
			QCOMPARE(Calculator::doOperation(7, 3, '+'), (double)10);
		}
		void testSubtraction()
		{
			QCOMPARE(Calculator::doOperation(7, 3, '-'), (double)4);
		}
		void testMultiplication()
		{
			QCOMPARE(Calculator::doOperation(7, 3, '*'), (double)21);
		}
		void testDivision()
		{
			QCOMPARE(Calculator::doOperation(9, 3, '/'), (double)3);
		}
};
