#pragma once
#include "node.h"
#include "iostream"

using namespace std;

class Operation : public Node
{
	public:
		Operation() {}
		~Operation()
		{
			delete left;
			delete right;
		}

		//Node *left;
		//Node *right;
};

