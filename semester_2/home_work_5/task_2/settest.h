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
			list = new Set <int>;
		}

		void cleanup()
		{
			delete list;
		}

		void testCreate()
		{
			QVERIFY(list->getSize() == 0);
		}

		void testAdd()
		{
			list->add(5);
			QVERIFY(list->getSize() == 1);
			list->add(4);
			QVERIFY(list->getSize() == 2);
			list->add(4);
			QVERIFY(list->getSize() == 3);
		}

		void testDel()
		{
			list->add(5);
			QVERIFY(list->getSize() == 1);
			list->add(4);
			QVERIFY(list->getSize() == 2);
			list->add(4);
			QVERIFY(list->getSize() == 3);
			list->del(4);
			QVERIFY(list->getSize() == 2);
			list->del(4);
			QVERIFY(list->getSize() == 1);
		}

		void testIntersection()
		{
			Set <int> *list2 = new Set <int>;
			list2->add(1);
			list2->add(2);
			list2->add(3);
			list2->add(4);
			list->add(3);
			list->add(4);
			list->add(5);
			QVERIFY(list->getSize() == 3);
			Set<int> *newSet = Set<int>::intersection(list2, list);
			QVERIFY(newSet->getSize() == 2);
			QVERIFY(newSet->element(0) == 3);
			QVERIFY(newSet->element(1) == 4);
			delete newSet;
			delete list2;
		}

		void testUnification()
		{
			Set <int> *list2 = new Set <int>;
			list2->add(0);
			list2->add(1);
			list2->add(3);
			list2->add(4);
			list->add(3);
			list->add(4);
			list->add(5);
			QVERIFY(list->getSize() == 3);
			Set<int> *newSet = Set<int>::unification(list2, list);
			QVERIFY(newSet->getSize() == 5);
			QVERIFY(newSet->element(0) == 0);
			QVERIFY(newSet->element(1) == 1);
			QVERIFY(newSet->element(4) == 5);
			delete newSet;
			delete list2;
		}

	private:
		Set <int> *list;
};

