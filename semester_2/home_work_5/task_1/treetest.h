#pragma once
#include "QObject"
#include "QTtest/QTest"
#include "tree.h"
#include <fstream>

using namespace std;

class TreeTest : public QObject
{
	Q_OBJECT

	public:
		explicit TreeTest(QObject *parent = 0) : QObject(parent) {}

	private slots:

		void init()
		{
			tree = new Tree;
		}

		void cleanup()
		{
			delete tree;
		}

		void testFull()
		{
			ifstream in ("input.txt");

			if (!in)
			{
				cout << "Error reading from file" << endl;
			}

			Tree tree;
			char str[1000];
			in.getline(str, 1000);
			cout << str << endl;
			tree.createTree(str, 0);

			cout <<"Your expression is: " << endl;
			tree.printTree();
			cout << endl;

			double answer = tree.calculateTree();
			cout << answer << endl;

			in.close();

			QVERIFY(answer == double(12));
		}

	private:
		Tree *tree;
};
