#include "iostream"
#include "fstream"
#include "tree.h"

using namespace std;

int main()
{
	cout << "Huffman decoding" << endl;
	ifstream in ("output.txt");

	if (!in)
	{
		cout << "error reading from file" << endl;
		int n = 0;
		cin >> n;
		return 1;
	}

	TreeNode *tree;
	char str[1000];
	in.getline(str, 1000);
	int i = 0;

	addNode(tree, str, i);
	i = 0;
	in.getline(str, 1000);
	//printTree(tree);
	cout << endl;
	getDecoded(tree, str, i);
	in.close();
	removeTree(tree);
	delete tree;
	int n = 0;
	cin >> n;
	return 0;
}