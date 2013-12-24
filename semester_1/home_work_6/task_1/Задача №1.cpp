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
		cout << "2: Check existing of element" << endl;
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
			addElement(tree, n);
		}

		else if (com == iremove)
		{
			cout << "Enter element you would like to delete:" << endl;
			int n = 0;
			cin >> n;
			deleteElement(tree, n);
		}

		else if (com == exist)
		{
			cout << "Enter the element you would like to check:" << endl;
			int n = 0;
			cin >> n;
			
			if (exists(tree, n))
				cout << "This element exists in tree" << endl;
			else 
				cout << "This element is not exists in tree" << endl;
		}

		else if (com == prInc)
			printIncTree(tree);

		else if (com == prDec)
			printDecTree(tree);

		else if (com == print)
			printTree(tree);

		cout << "It is done!" << endl << endl;
	}

	removeTree(tree);
	delete tree;

	int n = 0;
	cin >> n;
	return 0;
}
