#include "QObject"
#include "QtTest/QTest"
#include "avltree.h"
#include "iostream"

using namespace std;

class AVLTreeTest : public QObject
{
	Q_OBJECT
	public:
		explicit AVLTreeTest(QObject* parent = 0) : QObject(parent) {}
	private slots:

		void init()
		{
			tree = new AVLTree;
		}

		void cleanup()
		{
			delete tree;
		}

		void testAdd()
		{
			tree->add(1);
			QVERIFY(tree->isExists(1));
		}

		void testDelete()
		{
			tree->add(1);
			tree->add(2);
			tree->del(1);
			QVERIFY(tree->getHeight() == 1);
			QVERIFY(!tree->isExists(1));
		}

		void testBalance()
		{
			tree->add(1);
			tree->printDebug();
			cout << endl;
			tree->add(3);
			tree->printDebug();
			cout << endl;
			tree->add(2);
			tree->printDebug();
			cout << endl;
			tree->add(4);
			tree->printDebug();
			cout << endl;
			tree->add(5);
			tree->printDebug();
			cout << endl;
		}

	private:
		AVLTree *tree;
};
