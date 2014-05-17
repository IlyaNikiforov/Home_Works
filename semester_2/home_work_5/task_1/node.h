#pragma once

class Node
{
	public:
		Node() {}
		virtual ~Node() {}
		/// calculates value of sub tree
		virtual double calculateSubTree() = 0;
		/// prints sub tree
		virtual void printSubTree() = 0;
};


