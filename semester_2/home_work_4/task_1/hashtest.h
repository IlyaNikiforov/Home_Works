#pragma once
#include "hash.h"
#include "QObject"
#include "QtTest/QTest"
#include "hashfunction1.h"

class HashTest : public QObject
{
	Q_OBJECT
	public:
		explicit HashTest(QObject* parent = 0) : QObject(parent) {}
	private slots:

		void init()
		{
			function = new HashFunction1;
			hash = new Hash(10, function);
		}

		void cleanup()
		{
			delete hash;
			delete function;
		}

		void testAdd()
		{
			Strings *str = new Strings;
			char temp[10] = "a";
			str->add(temp);
			hash->add(str);
			QVERIFY(hash->find(str));
		}

		void testDel()
		{
			Strings *str = new Strings;
			char temp[10] = "a";
			str->add(temp);
			hash->add(str);
			hash->del(str);
			QVERIFY(!hash->find(str));
			delete str;
		}

		void testFull()
		{
			Strings *str1 = new Strings;
			char temp1[10] = "a";
			str1->add(temp1);
			hash->add(str1);
			Strings *str2 = new Strings;
			char temp2[10] = "a";
			str2->add(temp2);
			hash->add(str2);
			QVERIFY(hash->find(str1));
			Strings *str3 = new Strings;
			char temp3[10] = "b";
			str3->add(temp3);
			hash->add(str3);
			Strings *str4 = new Strings;
			char temp4[10] = "c";
			str4->add(temp4);
			hash->add(str4);
			hash->statistic();
			hash->print();
			hash->del(str3);
			hash->print();
			delete str3;
		}

	private:
		Hash *hash;
		HashFunction *function;
};
