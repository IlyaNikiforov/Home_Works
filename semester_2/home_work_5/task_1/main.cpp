#include "tree.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include "treetest.h"

using namespace std;

int main()
{

	TreeTest test;
	QTest::qExec(&test);

//	ifstream in ("input.txt");

//	if (!in)
//	{
//		cout << "Error reading from file" << endl;
//		int n = 0;
//		cin >> n;
//		return 1;
//	}

//	Tree tree;
//	char str[1000];
//	in.getline(str, 1000);
//	cout << str << endl;
//	tree.createTree(str, 0);

//	cout <<"Your expression is: " << endl;
//	tree.printTree();
//	cout << endl;

//	double answer = tree.calculateTree();
//	cout << answer << endl;

//	in.close();
	return 0;
}
