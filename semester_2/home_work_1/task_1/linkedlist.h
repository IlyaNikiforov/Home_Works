#pragma once

#include "list.h"

class LinkedList : public List
{
public:
	LinkedList() : first(nullptr), List() {}
	~LinkedList();

	void addValue(int value);
	bool isExist(int value) const;
	void deleteValue(int value);
	void print() const;
	int getSize() const;

private:
	struct ListElement
	{
		int value; /// value of current element in list
		ListElement *next; /// pointer to its next element
	};

	ListElement *first;
};
