
#include "iostream"
#include "fstream"
#include "tree.h"

using namespace std;


int main()
{
	cout << "Binary arithmetic tree" << endl;
	ifstream in ("input.txt");
	
	if (!in)
	{
		cout << "Error reading from file" << endl;
		int n = 0;
		cin >> n;
		return 1;
	}

	char str[1000];
    in.getline(str, 1000);

    cout << "Input expression" << endl << str << endl;

    TreeNode *tree;
    int i = 0;

    addNode(tree, str, i);

    cout << endl << "Tree as it realy is" << endl;
    printTree(tree);
    cout << endl << endl;

    cout << "Tree as expression" << endl;
    printExpression(tree);
    cout << endl << endl;

    calculateTree(tree);
    cout << "The answer is " << (tree->result);
    cout << endl << endl;
   
    in.close();
    removeTree(tree);
    delete tree;
	cin >> i;
    return 0;
}
