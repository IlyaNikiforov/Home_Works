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
		/// creates left child
		void setLeft(Node *node);
		/// creates right child
		void setRight(Node *node);
		/// returns left child
		Node *getLeft();
		/// returns right child
		Node *getRight();
	protected:
		Node *left;
		Node *right;
};

