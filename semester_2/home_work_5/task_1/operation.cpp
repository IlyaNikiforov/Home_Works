#include "operation.h"

void Operation::setLeft(Node *node)
{
	this->left = node;
}

void Operation::setRight(Node *node)
{
	this->right = node;
}

Node* Operation::getLeft()
{
	return left;
}

Node* Operation::getRight()
{
	return right;
}
