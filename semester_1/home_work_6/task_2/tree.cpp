
#include "iostream"
#include "tree.h"
using namespace std;

TreeNode* create(char value)
{
	TreeNode *head = new TreeNode;
	head->value = value;
	head->result = (value - 48);
	head->left = nullptr;
	head->right = nullptr;
	return head;
}

bool isOperator(char a)
{
	return a == '+' || a == '-' || a == '*' || a == '/';
}

bool isBracketOrSpace(char a)
{
	return a == '(' || a == ')' || a == ' ';
}

void addNode(TreeNode *&tree, char a[], int &i)
{
	if (isBracketOrSpace(a[i]))
	{
		i++;
		addNode(tree, a, i);
	}

	else if (a[i] != '\n')
	{
		if (isOperator(a[i]))
		{
			tree = create(a[i]);
			i++;
			addNode(tree->left, a, i);
			addNode(tree->right, a, i);
		}

		else 
		{
			tree = create(a[i]);
			i++;
		}
	}

	else 
		return;
}

void calculateNode(TreeNode *&tree)
{
	double result = 0;

	switch (tree->value)
	{
		case '+':
		{
			result = tree->left->result + tree->right->result;
			break;
		}
		case '-':
		{
			result = tree->left->result - tree->right->result;
			break;
		}
		case '*':
		{
			result = tree->left->result * tree->right->result;
			break;
		}
		case '/':
		{
			result = tree->left->result / tree->right->result;
			break;
		}
	}

	delete tree->left;
	tree->left = nullptr;
	delete tree->right;
	tree->right = nullptr;
	tree->value = '0';
	tree->result = result;
}

void calculateTree(TreeNode *&tree)
{
	if (isOperator(tree->value))
	{
		if (!isOperator(tree->left->value) && !isOperator(tree->right->value))
			calculateNode(tree);
		else 
		{
			if (isOperator(tree->left->value))
                calculateTree(tree->left);
            if (isOperator(tree->right->value))
                calculateTree(tree->right);
            calculateTree(tree);
		}
	}
}

void printTree(TreeNode *tree)
{
	if (tree == nullptr)
		return;
	cout << " " << tree->value << " ";
	if (tree->left != nullptr)
		cout << "(";
	printTree(tree->left);
	printTree(tree->right);
	if (tree->left != nullptr)
		cout << ")";
}

void printExpression(TreeNode *tree)
{
	if (tree == nullptr)
		return;
	
	if (tree->left != nullptr)
		cout << "(";
	printExpression(tree->left);
	cout <<tree->value;
	printExpression(tree->right);
	if (tree->left != nullptr)
		cout << ")";
	
}

void removeTree(TreeNode *&tree)
{
	if (tree == nullptr)
		return;
	removeTree(tree->left);
	removeTree(tree->right);
	delete tree;
	tree = nullptr;
}