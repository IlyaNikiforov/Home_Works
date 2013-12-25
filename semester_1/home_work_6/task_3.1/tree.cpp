#include <stdio.h>
#include "tree.h"

Tree *createTree ()
{
	Tree *result = new Tree;
	result->root = nullptr;
	return result;
}

int height (TreeNode *node)
{
	if (node)
		return node->height;
	return 0;
}

int balanceFactor(TreeNode* node)
{
	return height(node->right)-height(node->left);
}

void findHeight (TreeNode* node)
{
	int heightLeft = height(node->left);
	int heightRight = height(node->right);
	node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

TreeNode *leftRoate (TreeNode *q)
{
	TreeNode *p = q->right;
	q->right = p->left;
	p->left = q;
	findHeight(p);
	findHeight(q);
	return p;
}

TreeNode *rightRoate (TreeNode *p)
{
	TreeNode *q = p->left;
	p->left = q->right;
	q->right = p;
	findHeight(p);
	findHeight(q);
	return q;
}

TreeNode *findMinNode (TreeNode *node)
{
	if (node->left)
		return findMinNode(node->left);
	return node;
}

TreeNode *balanseNode (TreeNode *node);

TreeNode *removeMinNode (TreeNode *node)
{
	if (node->left == nullptr)
		return node->right;
	node->left = removeMinNode(node->left);
	return balanseNode(node);
}

TreeNode *balanseNode (TreeNode *node)
{
	findHeight(node);
	if (balanceFactor(node) == 2)
	{
		if (balanceFactor(node->right) < 0)
			node->right = rightRoate(node->right);
		return leftRoate(node);
	}
	if (balanceFactor(node) == -2)
	{
		if (balanceFactor(node->left) > 0)
			node->left = leftRoate(node->left);
		return rightRoate(node);
	}
	return node;
}

TreeNode *addValue (TreeNode **node, int value)
{
	if (! *node)
		return new TreeNode(value);
	if (value < (*node)->value)
		(*node)->left = addValue(&(*node)->left, value);
	else
		(*node)->right = addValue(&(*node)->right, value);
	return balanseNode((*node));
}

TreeNode *removeNode(TreeNode *node, int value)
{
	if(!node) 
	{
		printf("Element not found!\n");
		return nullptr;
	}
	if(value < node->value)
		node->left = removeNode(node->left, value);
	else if(value > node->value)
		node->right = removeNode(node->right, value);        
	else // equal
	{
		TreeNode *left = node->left;
		TreeNode *right = node->right;
		delete node;
		if( !right ) 
			return left;
		TreeNode *min = findMinNode(right);
		min->right = removeMinNode(right);
		min->left = left;
		return balanseNode(min);
	}
	return balanseNode(node);
}

void printTreeInc (TreeNode *root)
{
	if(root->left != nullptr)
		printTreeInc(root->left);
	printf("%d  ", root->value);
	if(root->right != nullptr)
		printTreeInc(root->right);
}

void printTreeDec (TreeNode *root)
{
	if(root->right != nullptr)
		printTreeDec(root->right);

	printf("%d  ", root->value);
	if(root->left != nullptr)
		printTreeDec(root->left);
}

void printDebug(TreeNode* node)
{
	if (node == nullptr)
	{
		printf("null");
	}
	else
	{
		printf("(%d ", node->value);
		printDebug(node->left);
		printf(" ");
		printDebug(node->right);
		printf(")");
	}
}

void freeTree(TreeNode *tree)
{
	if (tree == nullptr) 
		return;
	if (tree->left)   
		freeTree(tree->left); 
	if (tree->right)  
		freeTree(tree->right); 
	delete tree;
}