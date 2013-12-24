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

TreeNode *createNode(int value) 
{
    TreeNode *node = new TreeNode;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void addElement(TreeNode *&node, int value) 
{
    if (node == nullptr) 
    {
		node = createNode(value);
        return;
    }
	
	if (value == node->value)
		return;
    if (value < node->value)
        addElement(node->left, value);
    else 
        addElement(node->right, value);
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
        delete root;
        root = nullptr;
    }
}

void removeTree(Tree *tree) 
{
	removeTree(tree->root);
}
