#pragma once
#include "vector.h"
#include <QObject>
#include <QTest>

class VectorTest : public QObject {
	Q_OBJECT

	public:
		explicit VectorTest(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void init()
		{
			double firstInput[3] = {1, 2, 3};
			firstVect = new Vector<3>(firstInput);
			double secondInput[3] = {-1, -2, -3};
			secondVect = new Vector<3>(secondInput);
		}

		void cleanup()
		{
			delete firstVect;
			delete secondVect;
		}

		void testSum()
		{
			Vector<3> testVect;
			testVect = *firstVect + *secondVect;
			QVERIFY(testVect.isZero());
		}

		void testSubtaction()
		{
			Vector<3> testVect;
			testVect = *firstVect - *secondVect;
			double test[3] = {2, 4, 6};
			QVERIFY(Vector<3>(test) == testVect);
		}

		void testScalarMult()
		{
			double res = *firstVect * *secondVect;
			QVERIFY(res == (double)(-14));
		}

		void testCopy()
		{
			delete firstVect;
			firstVect = new Vector<3>(*secondVect);
			QVERIFY(*firstVect == *secondVect);
		}

	private:
		Vector<3> *firstVect;
		Vector<3> *secondVect;
};
