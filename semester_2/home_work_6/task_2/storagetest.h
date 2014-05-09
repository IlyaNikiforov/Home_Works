#pragma once
#include "QObject"
#include "QtTest/QTest"
#include "storage.h"

class StorageTest : public QObject
{
	Q_OBJECT
	public:
		explicit StorageTest(QObject* parent = 0) : QObject(parent) {}
	private slots:

		void init()
		{
			list = new Storage <int>;
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
			try
			{
				list->add(4);
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
			list->add(5);
			QVERIFY(list->getSize() == 1);
			list->add(4);
			QVERIFY(list->getSize() == 2);
			list->del(4);
			QVERIFY(list->getSize() == 1);
			try
			{
			list->del(4);
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
			Storage <int> *list2 = new Storage <int>;
			list2->add(1);
			list2->add(2);
			list2->add(3);
			list2->add(4);
			list->add(3);
			list->add(4);
			list->add(5);
			QVERIFY(list->getSize() == 3);
			Storage<int> *newStorage = Storage<int>::intersection(list2, list);
			QVERIFY(newStorage->getSize() == 2);
			QVERIFY(newStorage->element(0) == 3);
			QVERIFY(newStorage->element(1) == 4);
			delete newStorage;
			delete list2;
		}

		void testUnification()
		{
			Storage <int> *list2 = new Storage <int>;
			list2->add(0);
			list2->add(1);
			list2->add(3);
			list2->add(4);
			list->add(3);
			list->add(4);
			list->add(5);
			QVERIFY(list->getSize() == 3);
			Storage<int> *newStorage = Storage<int>::unification(list2, list);
			QVERIFY(newStorage->getSize() == 5);
			QVERIFY(newStorage->element(0) == 0);
			QVERIFY(newStorage->element(1) == 1);
			QVERIFY(newStorage->element(4) == 5);
			delete newStorage;
			delete list2;
		}

	private:
		Storage <int> *list;
};

