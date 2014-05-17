#pragma once
#include "QObject"
#include "QtTest/QTest"
#include "set.h"

class SetTest : public QObject
{
	Q_OBJECT
	public:
		explicit SetTest(QObject* parent = 0) : QObject(parent) {}
	private slots:

		void init()
		{
			set = new Set <int>;
		}

		void cleanup()
		{
			delete set;
		}

		void testCreate()
		{
			QVERIFY(set->getSize() == 0);
		}

		void testAdd()
		{
			set->add(5);
			QVERIFY(set->getSize() == 1);
			set->add(4);
			QVERIFY(set->getSize() == 2);
			set->add(4);
			QVERIFY(set->getSize() == 3);
		}

		void testDel()
		{
			set->add(5);
			QVERIFY(set->getSize() == 1);
			set->add(4);
			QVERIFY(set->getSize() == 2);
			set->add(4);
			QVERIFY(set->getSize() == 3);
			set->del(4);
			QVERIFY(set->getSize() == 2);
			set->del(4);
			QVERIFY(set->getSize() == 1);
		}

		void testIntersection()
		{
			Set <int> *set2 = new Set <int>;
			set2->add(1);
			set2->add(2);
			set2->add(3);
			set2->add(4);
			set->add(3);
			set->add(4);
			set->add(5);
			QVERIFY(set->getSize() == 3);
			Set<int> *newSet = Set<int>::intersection(set2, set);
			QVERIFY(newSet->getSize() == 2);
			QVERIFY(newSet->element(0) == 3);
			QVERIFY(newSet->element(1) == 4);
			delete newSet;
			delete set2;
		}

		void testUnification()
		{
			Set <int> *set2 = new Set <int>;
			set2->add(0);
			set2->add(1);
			set2->add(3);
			set2->add(4);
			set->add(3);
			set->add(4);
			set->add(5);
			QVERIFY(set->getSize() == 3);
			Set<int> *newSet = Set<int>::unification(set2, set);
			QVERIFY(newSet->getSize() == 5);
			QVERIFY(newSet->element(0) == 0);
			QVERIFY(newSet->element(1) == 1);
			QVERIFY(newSet->element(4) == 5);
			delete newSet;
			delete set2;
		}

	private:
		Set <int> *set;
};

