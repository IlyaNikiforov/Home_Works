#include "stdlib.h"
#include "tree.h"
#include "iostream"
#include "strings.h"
#include "fstream"

using namespace std;

Tree *createTree() 
{
	Tree *tree = new Tree;
	tree->root = nullptr;
	return tree;
}

void printTree(TreeNode *root) 
{
	if (root != nullptr) 
	{
		cout << root->symbol << "(" << root->value << ")";
		cout << "(";
		printTree(root->left);
		printTree(root->right);
		cout << ")";
	}

	else 
		cout << "null";
}

void printTree(Tree *tree) 
{
	printTree(tree->root);
}

void printTree(TreeNode *root, ofstream &out) 
{
	if (root != nullptr) 
	{
		out << root->symbol << "(" << root->value << ")";
		out << "(";
		printTree(root->left, out);
		printTree(root->right, out);
		out << ")";
	}

	else 
		out << "null";
}

void printIncTree(TreeNode *root) 
{
	if (root != nullptr) 
	{
		printIncTree(root->left);        
		cout << root->value << " ";        
		printIncTree(root->right);
	}
}

void printIncTree(Tree *tree) 
{
	printIncTree(tree->root);
}

void printDecTree(TreeNode *root) 
{
	if (root != nullptr) 
	{
		printDecTree(root->right);        
		cout << root->value << " ";        
		printDecTree(root->left);
	}
}

void printDecTree(Tree *tree) 
{
	printDecTree(tree->root);
}

void printUp(TreeNode *root) 
{
	if (root != nullptr) 
	{
		printUp(root->left);
		printUp(root->right);
		cout << root->value << endl;
	}
}

void printUp(Tree *tree) 
{
	printUp(tree->root);
}

bool exists(TreeNode *root, int value) 
{
	if (root == nullptr)
		return false;
	if (root->value == value)
		return true;
	if (root->value > value)
		return exists(root->left, value);
	else
		return exists(root->right, value);
}

bool exists(Tree *tree, int value) 
{
	return exists(tree->root, value);
}

TreeNode *createNode(int value, char symbol) 
{
	TreeNode *node = new TreeNode;
	node->value = value;
	node->symbol = symbol;
	node->left = nullptr;
	node->right = nullptr;
	//node->code = strCreate();
	return node;
}

void addElement(TreeNode *&node, int value, char symbol) 
{
	if (node == nullptr) 
	{
		node = createNode(value, symbol);
		return;
	}

	if (value == node->value)
		return;
	if (value < node->value)
		addElement(node->left, value, symbol);
	else 
		addElement(node->right, value, symbol);
}

void addElement(Tree *tree, int value, char symbol) 
{
	addElement(tree->root, value, symbol);
}

int deleteMin(TreeNode *&node) 
{
	if (node->left == nullptr) 
	{
		int result = node->value;
		TreeNode *temp = node;        
		node = node->right;
		temp = nullptr;
		delete temp;
		return result;
	}
	else
		return deleteMin(node->left);
}

int deleteMin(Tree *tree) 
{
	return deleteMin(tree->root);
}

void deleteElement(TreeNode *&node, int value) 
{
	if (node == nullptr)
		return;
	if (value < node->value)
		deleteElement(node->left, value);
	else if (value > node->value)
		deleteElement(node->right, value);
	else if (node->left == nullptr && node->right == nullptr) 
	{
		delete node;
		node = nullptr;
	} 

	else if (node->left == nullptr) 
	{
		TreeNode *temp = node;        
		node = node->right;
		delete temp;
	}

	else if (node->right == nullptr) 
	{
		TreeNode *temp = node;        
		node = node->left;
		delete temp;
	}

	else
		node->value = deleteMin(node->right);  
}

void deleteElement(Tree *tree, int value) 
{
	if (!exists(tree, value))
		return;
	deleteElement(tree->root, value);
}

void removeTree(TreeNode *&root) 
{
	if (root != nullptr) 
	{
		removeTree(root->left);
		removeTree(root->right);
		strDelete(root->code);
		delete root->code;
		delete root;
		root = nullptr;
	}
}

void removeTree(Tree *tree) 
{
	removeTree(tree->root);
}

void addCode(String *code, TreeNode *&node, char symbol)
{
		String *add = strCreate();
		char *a = new char;
		*a = symbol;
		add->begin = a;
		add->length = 1;
		node->code = strClone(code);
		strAdd(node->code, add);
}

void getCoded(TreeNode *&node)
{
	if (node->symbol != '#')
		cout << node->symbol << " " << node->code->begin << endl;

	if (node->left != nullptr)
	{
		addCode(node->code, node->left, '0');
		getCoded(node->left);
	}

	if (node->right != nullptr)
	{
		addCode(node->code, node->right, '1');
		getCoded(node->right);
	}
}

void amountOfSymbols(TreeNode *node, int &n)
{
	if (node->symbol != '#')
		n++;
	if (node->left != nullptr)
		amountOfSymbols(node->left, n);
	if (node->right != nullptr)
		amountOfSymbols(node->right, n);
}

void findCode(TreeNode *node, char a, String *&str)
{
	if (node->symbol == a)
	{	
		str = strClone(node->code);
		return;
	}

	if (node->left != nullptr)
		findCode(node->left, a, str);

	if (node->right != nullptr)
		findCode(node->right, a, str);
}

void getdecoded(TreeNode *node, char str[], int &i)
{
	TreeNode *current = node;
	while (str[i] != '\n')
	{
		while (current->symbol == '#')
		{
			if (str[i] == 1)
				current = current->right;
			else
				current = current->left;
			i++;
		}

		cout << current->symbol;
		i++;
		current = node;
	}
}
