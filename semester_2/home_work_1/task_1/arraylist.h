#pragma once
#include "list.h"

const int sizeOfArray = 1000;

class ArrayList : public List
{
public:
	void addValue(int value);
	bool isExist(int value) const;
	void deleteValue(int value);
	void print() const;
	int getSize() const;
private:
	int array[sizeOfArray];

};


