#pragma once
#include "stdio.h"

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
};

struct Tree
{
    TreeNode *root;
};

Tree *createTree();

bool exists(Tree *tree, int value);

void addElement(Tree *tree, int value);

void printTree(Tree *tree);

void printIncTree(Tree *tree);

void printDecTree(Tree *tree);

void printUp(Tree *tree);

int deleteMin(Tree *tree);

void deleteElement(Tree *tree, int value);

void removeTree(Tree *tree);