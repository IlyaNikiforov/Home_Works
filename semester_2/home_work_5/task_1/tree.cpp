#include "tree.h"
#include "cstdio"
#include "iostream"

using namespace std;

Tree::Tree()
{
	head = nullptr;
}

Tree::~Tree()
{
	delete head;
}

Number *Tree::createNumberNode(int number)
{
	Number *newNode = new Number(number);
	return newNode;
}

Operation* Tree::createOperationNode(char symbol)
{

	Operation *newNode;

	if (symbol == '+')
		newNode = new Summ;
	else if (symbol == '-')
		newNode = new Subtraction;
	else if (symbol == '*')
		newNode = new Multiplication;
	else if (symbol == '/')
		newNode = new Division;
	return newNode;
}

bool isOperator(char a)
{
	return a == '+' || a == '-' || a == '*' || a == '/';
}

bool isBracketOrSpace(char a)
{
	return a == '(' || a == ')' || a == ' ';
}

bool isNumber(char symbol)
{
	return ((symbol >= '0') && (symbol <= '9'));
}

Node *Tree::createSubTree(Node *current, char a[], int &i)
{
		while (a[i] != '\n')
		{
			if (a[i] == '(')
			{
				if (current == nullptr)
				{
					i++;
					continue;
				}
				Node *newNode;
				Operation *copy = dynamic_cast<Operation *>(current);
				copy->setLeft(newNode);
				i++;
				createSubTree(newNode, a, i);
			}
			else if(a[i] == ')')
			{
				i++;
				break;
			}
			else if (isNumber(a[i]))
			{
				int number = a[i] - '0';
				i++;
				while (isNumber(a[i]))
				{
					number = number * 10 + (a[i] - '0');
					i++;
				}
				current = createNumberNode(number);
				break;
			}

			else if (isOperator(a[i]))
			{
				current = createOperationNode(a[i]);
				i++;
				Operation *copy = dynamic_cast<Operation *>(current);
				copy->setLeft(createSubTree(copy->getLeft(), a, i));
				copy->setRight(createSubTree(copy->getRight(), a, i));
			}

			else
				i++;
		}

			return current;
}


void Tree::createTree(char a[], int i)
{
	this->head = createSubTree(head, a, i);
}

void Tree::printTree()
{
	head->printSubTree();
}


double Tree::calculateTree()
{
	return head->calculateSubTree();
}
