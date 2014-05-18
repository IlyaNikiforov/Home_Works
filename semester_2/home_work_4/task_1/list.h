#pragma once
#include "strings.h"

class List
{
public:
	List() : first(nullptr), size(0){}
	~List();

	void addValue(Strings* value);
	bool isExist(Strings* value) const;
	void deleteValue(Strings* value);
	Strings *element(int i);
	void print() const;
	int getSize() const;
	int getCount(int i);

private:
	struct ListElement
	{
		int count;
		Strings* value; /// value of current element in list
		ListElement *next; /// pointer to its next element
	};

	ListElement *first;
	int size;
};
