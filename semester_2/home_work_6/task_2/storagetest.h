#pragma once
#include "QObject"
#include "QtTest/QTest"
#include "uniquelist.h"

class ListTest : public QObject
{
	Q_OBJECT
	public:
		explicit ListTest(QObject* parent = 0) : QObject(parent) {}
	private slots:

		void init()
		{
			list = new UniqueList <int>;
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
			list->addUniqueElement(5);
			QVERIFY(list->getSize() == 1);
			list->addUniqueElement(4);
			QVERIFY(list->getSize() == 2);
			try
			{
				list->addUniqueElement(4);
			}
			catch (ListErrors::notUniqueError)
			{
				QVERIFY(list->getSize() == 2);
				return;
			}
			QFAIL("Exception wasn't thrown");
		}

		void testDel()
		{
			list->addUniqueElement(5);
			QVERIFY(list->getSize() == 1);
			list->addUniqueElement(4);
			QVERIFY(list->getSize() == 2);
			list->deleteUniqueElement(4);
			QVERIFY(list->getSize() == 1);
			try
			{
			list->deleteUniqueElement(4);
			}
			catch (ListErrors::notExistError)
			{
				QVERIFY(list->getSize() == 1);
				return;
			}
			QFAIL("Exception wasn't thrown");
		}

		void testIntersection()
		{
			UniqueList <int> *list2 = new UniqueList <int>;
			list2->add(1);
			list2->add(2);
			list2->add(3);
			list2->add(4);
			list->add(3);
			list->add(4);
			list->add(5);
			QVERIFY(list->getSize() == 3);
			Set<int> *newStorage = UniqueList<int>::intersection(list2, list);
			QVERIFY(newStorage->getSize() == 2);
			QVERIFY(newStorage->element(0) == 3);
			QVERIFY(newStorage->element(1) == 4);
			delete newStorage;
			delete list2;
		}

		void testUnification()
		{
			UniqueList <int> *list2 = new UniqueList <int>;
			list2->add(0);
			list2->add(1);
			list2->add(3);
			list2->add(4);
			list->add(3);
			list->add(4);
			list->add(5);
			QVERIFY(list->getSize() == 3);
			Set<int> *newStorage = UniqueList<int>::unification(list2, list);
			QVERIFY(newStorage->getSize() == 5);
			QVERIFY(newStorage->element(0) == 0);
			QVERIFY(newStorage->element(1) == 1);
			QVERIFY(newStorage->element(4) == 5);
			delete newStorage;
			delete list2;
		}

	private:
		UniqueList <int> *list;
};

