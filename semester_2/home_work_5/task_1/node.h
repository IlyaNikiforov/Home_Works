#pragma once

class Node
{
	public:
		Node() {}
		virtual ~Node() {}
		virtual double calculateSubTree() = 0;
		virtual void printSubTree() = 0;
};


