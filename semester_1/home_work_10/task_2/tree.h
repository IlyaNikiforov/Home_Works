#pragma once
#include "stdio.h"
#include "strings.h"
#include "fstream"

using namespace std;

struct TreeNode
{
	char symbol;
	int value;
	TreeNode *left;
	TreeNode *right;
	String *code;
};

struct Tree
{
	TreeNode *root;
};

Tree *createTree();

TreeNode* create(char symbol);

bool isBracket(char a);

void addNode(TreeNode *&tree, char a[], int &i);

TreeNode *createNode(int value, char symbol);

bool exists(Tree *tree, int value);

void addElement(Tree *tree, int value);

void printTree(TreeNode *root);

void printTree(Tree *tree);

void printTree(TreeNode *root, ofstream &out);

void printIncTree(Tree *tree);

void printDecTree(Tree *tree);

void printUp(Tree *tree);

int deleteMin(Tree *tree);

void deleteElement(Tree *tree, int value);

void removeTree(TreeNode *&root);

void removeTree(Tree *tree);

void getCoded(TreeNode *&node);

void amountOfSymbols(TreeNode *node, int &n);

void findCode(TreeNode *node, char a, String *&str);

void getDecoded(TreeNode *node, char str[], int &i);