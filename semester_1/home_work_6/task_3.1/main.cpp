#include "iostream"
#include "tree.h"

using namespace std;

enum command 
{
	add,
	iremove,
	exist,
	prInc,
	prDec,
	print
};

bool isCommand (int temp)
{
	return (temp == add) || (temp == iremove) || (temp == exist) || (temp == prInc) || (temp == prDec) || (temp == print);
}

int main()
{
	cout << "Tree" << endl;
	
	int com = add;
	Tree *tree = createTree();
	while (isCommand(com))
	{
		cout << "What would you like to do?" << endl;
		cout << "0: Add an element to tree" << endl;
		cout << "1: Remove element from tree" << endl;
		cout << "3: Print increasing tree" << endl;
		cout << "4: Print decreasing tree" << endl;
		cout << "5: Print tree as it realy looks" << endl;
		cout << "Everything else: exit" << endl;

		cin >> com;

		if (com == add)
		{
			cout << "Enter new element:" << endl;
			int n = 0;
			cin >> n;
			tree->root = addValue(&tree->root, n);
		}

		else if (com == iremove)
		{
			cout << "Enter element you would like to delete:" << endl;
			int n = 0;
			cin >> n;
			 tree->root = removeNode(tree->root, n);
		}

		else if (com == prInc)
			printTreeInc(tree->root);

		else if (com == prDec)
			printTreeDec(tree->root);

		else if (com == print)
			printDebug(tree->root);

		cout << "It is done!" << endl << endl;
	}

	freeTree(tree->root);
	delete tree;

	int n = 0;
	cin >> n;
	return 0;
}
