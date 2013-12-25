#include "iostream"
#include "fstream"
#include "list.h"
#include "tree.h"
#include "strings.h"

using namespace std;

struct CodeElement
{
	char a;
	String *cod;
};

bool isFilled(CodeElement *cde, int amount, char a)
{
	for (int i = 0; i < amount; i++)
		if (cde[i].a == a)
			return true;
	return false;
}

String* findElem(CodeElement *cde, char a)
{
	int i = 0;
	while (cde[i].a != a)
		i++;
	return cde[i].cod;
}

String* makeListFilled(ifstream &in, List* list)
{
	char *s = new char[1000];
	String *str = strCreate();
	int n = 0;

	while (!in.eof())
	{
		in.getline(s, 1000);
		String *newstr = strCreate();
		newstr->begin = s;
		newstr->length = strLen(newstr);
		n = newstr->length;
		for (int i = 0; i < n; i++)
		{
			addSortedElement(list, s[i]);
			//cout << endl;
			//printList(list);
		}
		strAdd(str, newstr);
	}

	return str;
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
		parent->code = strCreate();
		parent->value = left->value + right->value;
		addSortedElement(list, parent);
		//cout << endl;
		//printList(list);
	}
}

void findAndPrintCode(List *list, String *str, ofstream &out)
{
	int amount = 0;
	amountOfSymbols(list->first->next->value, amount);
	CodeElement *cde = new CodeElement[amount];
	int filled = 0;
	int j = 0;

	for (int i = 0; i < str->length; i++)
	{
		if (filled < amount)
			if(!isFilled(cde, amount, str->begin[i]))
			{
				cde[filled].a = str->begin[i];
				findCode(list->first->next->value, str->begin[i], cde[filled].cod);
				filled++;
			}

		while (cde[j].a != str->begin[i])
			j++;
		
		out << cde[j].cod->begin;
		j = 0;
	}
	
	for (int i = 0; i < amount; i++)
	{
		strDelete(cde[i].cod);
		delete cde[i].cod;
	}
	delete[] cde;
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
	
	String *str = makeListFilled(in, list);

	fromListToTree(list);

	printTree(list->first->next->value, out);

	list->first->value->code = strCreate();
	list->first->next->value->code = strCreate();

	getCoded(list->first->next->value);

	findAndPrintCode(list, str, out);

	in.close();
	out.close();
	removeTree(list->first->next->value);
	removeTree(list->first->value);
	strDelete(str);
	delete str;
	delete list->first->next;
	delete list->first;
	delete list;
	int n = 0;
	cin >> n;
	return 0;
}