#pragma once
#include <QObject>
#include <QtTest/QTest>
#include <calculator.h>

class CalculatorTest : public QObject
{
	Q_OBJECT

	public:
		explicit CalculatorTest(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void init()
		{
			calc = new Calculator;
		}
		void cleanup()
		{
			delete calc;
		}
		void testSum()
		{
			calc->addNumber(7);
			calc->addOperation("+");
			calc->addNumber(3);
			QCOMPARE(calc->calculateAnswer(), (double)10);
		}
		void testSubtraction()
		{
			calc->addNumber(7);
			calc->addOperation("-");
			calc->addNumber(3);
			QCOMPARE(calc->calculateAnswer(), (double)4);
		}
		void testMultiplication()
		{
			calc->addNumber(7);
			calc->addOperation("*");
			calc->addNumber(3);
			QCOMPARE(calc->calculateAnswer(), (double)21);
		}
		void testDivision()
		{
			calc->addNumber(9);
			calc->addOperation("/");
			calc->addNumber(3);
			QCOMPARE(calc->calculateAnswer(), (double)3);
		}
		void testFraction()
		{
			calc->addNumber(3);
			calc->addPoint();
			calc->addNumber(7);
			calc->addOperation("+");
			calc->addNumber(4);
			QCOMPARE(calc->calculateAnswer(), 7.7);
		}
		void testDivisionByZero()
		{
			calc->addNumber(3);
			calc->addOperation("/");
			calc->addNumber(0);
			QVERIFY(!calc->isCorrectOperation());
		}

	private:
		Calculator *calc;
};
