#pragma once
#include "node.h"
#include "iostream"

using namespace std;

class Operation : public Node
{
	public:
		Operation() : left(nullptr), right(nullptr) {}
		~Operation()
		{
			delete left;
			delete right;
		}
		void setLeft(Node *node);
		void setRight(Node *node);
		Node *getLeft();
		Node *getRight();
	protected:
		Node *left;
		Node *right;
};

