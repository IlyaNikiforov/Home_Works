#include "iostream"
#include "fstream"
#include "list.h"
#include "tree.h"

using namespace std;

void makeListFilled(ifstream &in, List* list)
{
	char s[1000];
	int n = 0;

	while (!in.eof())
	{
		in.getline(s, 1000);
		n = strlen(s);
		for (int i = 0; i < n; i++)
		{
			addSortedElement(list, s[i]);
			//cout << endl;
			//printList(list);
		}
	}
}

void fromListToTree(List *list)
{
	while (list->first->next->next != nullptr)
	{
		TreeNode *left = removeFirstElement(list);
		TreeNode *right = removeFirstElement(list);
		TreeNode *parent = new TreeNode;
		parent->left = left;
		parent->right = right;
		parent->symbol = '#';
		parent->index = 0;
		parent->value = left->value + right->value;
		addSortedElement(list, parent);
		//cout << endl;
		//printList(list);
	}
}

void findAndPrintCode(List *list, ifstream &in, ofstream &out)
{
	char s[1000];
	int n = 0;

	while (!in.eof())
	{
		in.getline(s, 1000);
		n = strlen(s);
		for (int i = 0; i < n; i++)
			findCode(list->first->next->value, s[i], out);
	}
}

int main()
{
	cout << "Huffman coding" << endl;
	
	ifstream in ("input.txt");
	ofstream out ("output.txt");
	
	if (!in)
	{
		cout << "error reading from file" << endl;
		int n = 0;
		cin >> n;
		return 1;
	}
	
	List* list = createList();
	
	makeListFilled(in, list);

	fromListToTree(list);

	printTree(list->first->next->value, out);

	getCoded(list->first->next->value);

	in.close();
	ifstream in1 ("input.txt");

	out << endl;

	findAndPrintCode(list, in1, out);

	in1.close();
	out.close();
	removeTree(list->first->next->value);
	removeTree(list->first->value);
	delete list->first->next;
	delete list->first;
	delete list;
	int n = 0;
	cin >> n;
	return 0;
}