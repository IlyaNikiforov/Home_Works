#pragma once

#include "list.h"

class LinkedList : public List
{
public:
	LinkedList();
	~LinkedList();

	void addValue(int value);
	bool isExist(int value) const;
	void deleteValue(int value);
	void print() const;
	int getSize() const;

private:
	struct ListElement
	{
		int value;
		ListElement *next;
	};

	ListElement *first;
};
