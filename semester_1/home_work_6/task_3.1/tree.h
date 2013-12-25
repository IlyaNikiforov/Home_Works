#pragma once

struct TreeNode
{
	int value;
	int height;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int k) { value = k; left = right = nullptr; height = 1; }
};

struct Tree
{
	TreeNode *root;
};

Tree *createTree ();

TreeNode *addValue (TreeNode **node, int value);

TreeNode *removeNode (TreeNode *node, int value);

void printTreeInc (TreeNode *root);

void printTreeDec (TreeNode *root);

void printDebug(TreeNode* node);

void freeTree(TreeNode *tree);
