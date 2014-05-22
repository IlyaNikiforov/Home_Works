#pragma once
#include "QObject"
#include "QtTest/QTest"
#include "strings.h"
#include "iostream"

class StringTest : public QObject
{
	Q_OBJECT
	public:

		explicit StringTest(QObject* parent = 0) : QObject(parent) {}

	private slots:

		void init()
		{
			str = new Strings;
		}

		void cleanup()
		{
			delete str;
		}

		void testCreate()
		{
			QVERIFY(str->returnLength() == 0);
		}

		void testAdd()
		{
			char temp[10] = "a";
			//std::cout << strlen(temp);
			str->add(temp);
			char *string = str->strToChar();
			QVERIFY(string[0] == 'a');
			delete[] string;
			QVERIFY(str->returnLength() == 1);
		}

		void testAddString()
		{
			Strings *str1 = new Strings;
			char temp[10] = "a";
			str1->add(temp);
			char temp1[10] = "b";
			str->add(temp1);
			str->add(str1);
			QVERIFY(str->returnLength() == 2);
			QVERIFY(str->element(0) == 'b');
			QVERIFY(str->element(1) == 'a');
		}

		void testCut()
		{
			str->add("abcdef");
			str->cut(1, 2);
			QVERIFY(str->returnLength() == 2);
			QVERIFY(str->element(0) == 'b');
			QVERIFY(str->element(1) == 'c');
		}



	private:
		Strings *str;
};
