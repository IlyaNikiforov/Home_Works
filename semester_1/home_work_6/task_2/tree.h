#pragma once


struct TreeNode 
{
	char value;
	double result;
	TreeNode *left;
	TreeNode *right;
};

struct Tree
{
	TreeNode *first;
};

TreeNode* create(char value);

bool isOperator(char a);

bool isBracketOrSpace(char a);

void addNode(TreeNode *&tree, char a[], int &i);

void calculateNode(TreeNode *&tree);

void calculateTree(TreeNode *&tree);

void printTree(TreeNode *tree);

void printExpression(TreeNode *tree);

void removeTree(TreeNode *&tree);