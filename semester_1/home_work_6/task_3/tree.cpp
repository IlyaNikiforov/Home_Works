#include <stdlib.h>
#include "tree.h"
#include <iostream>

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
		cout << root->value;
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

int height(TreeNode *node)
{
	if (node == nullptr)
		return 0;
	return node->height;
}

int balanceFactor(TreeNode *node)
{
	return height(node->right) - height(node->left);
}

void updateHeight(TreeNode *node)
{
	if (height(node->left) > height(node->right))
		node->height = height(node->left) + 1;
	else 
		node->height = height(node->right) + 1;
}

TreeNode* rotateRight(TreeNode* root)
{
	TreeNode* pivot = root->left;
	root->left = pivot->right;
	pivot->right = root;
	updateHeight(root);
	updateHeight(pivot);
	return pivot;
}

TreeNode* rotateLeft(TreeNode* root)
{
	TreeNode* pivot = root->right;
	root->right = pivot->left;
	pivot->left = root;
	updateHeight(root);
	updateHeight(pivot);
	return pivot;
}

TreeNode* balance(TreeNode* node)
{
	updateHeight(node);

	if (balanceFactor(node) == 2)
	{
		if (balanceFactor(node->right) < 0)
			node->right = rotateRight(node->right);

		return rotateLeft(node);
	}

	if (balanceFactor(node) == -2)
	{
		if (balanceFactor(node->left) > 0)
			node->left = rotateLeft(node->left);

		return rotateRight(node);
	}

	return node;
}

TreeNode *createNode(int value) 
{
	TreeNode *node = new TreeNode;
	node->value = value;
	node->height = 0;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

void addElement(TreeNode *&current, int value) 
{
	if (current == nullptr)
		current = createNode(value);

	if (current->value == value)
		return;

	if (current->value < value)
	{
		if (current->right == nullptr)
		{
			current->right = createNode(value);
			updateHeight(current);
			return;
		}
		addElement(current->right, value);
		updateHeight(current);
		current = balance(current);
		return;
	}

	if (current->value > value)
	{
		if (current->left == nullptr)
		{
			current->left = createNode(value);
			updateHeight(current);
			return;
		}
		addElement(current->left, value);
		updateHeight(current);
		current = balance(current);
		return;
	}
}

void addElement(Tree *tree, int value) 
{
	addElement(tree->root, value);
}

int deleteMin(TreeNode *&node) 
{
	if (node->left == nullptr) 
	{
		int result = node->value;
		TreeNode *temp = node;
		node = node->right;
		delete temp;
		temp = nullptr;
		return result;
	}
	else
		return deleteMin(node->left);
}

int deleteMin(Tree *tree) 
{
	return deleteMin(tree->root);
}

void deleteElement(TreeNode *&child, int value) 
{
	if (child->value == value)
	{
		if ((child->left == nullptr) && (child->right == nullptr))
		{
			delete child;
			child = nullptr;
			child = balance(child);
			return;
		}

		if ((child->left != nullptr) && (child->right == nullptr))
		{
			TreeNode *temp = child;

			child = child->left;
			delete temp;
			child = balance(child);
			return;
		}

		if ((child->left == nullptr) && (child->right != nullptr))
		{
			TreeNode *temp = child;

			child =  child->right;
			delete temp;
			child = balance(child);
			return;
		}

		if ((child->left != nullptr) && (child->right != nullptr))
		{
			child->value = deleteMin(child->right);
			child = balance(child);
			return;
		}
	}

	if ((child->value > value) && (child->left != nullptr))
	{
		deleteElement(child->left, value);
		child = balance(child);
	}

	if ((child->value < value) && (child->right != nullptr))
	{
		deleteElement(child->right, value);
		child = balance(child);
	}
	return; 
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
		delete root;
		root = nullptr;
	}
}

void removeTree(Tree *tree) 
{
	removeTree(tree->root);
}
