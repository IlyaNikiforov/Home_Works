#pragma once
#include "node.h"
#include "multiplication.h"
#include "summ.h"
#include "division.h"
#include "subtraction.h"
#include "number.h"

class Tree
{
	public:
		Tree();
		~Tree();
		Node *head;
		void createTree(char a[], int i);
		void printTree();
		double calculateTree();
	private:
		static Node *createSubTree(Node *currentNode, char a[], int &i);
		static Number* createNumberNode(int number);
		static Operation* createOperationNode(char symbol);
};


