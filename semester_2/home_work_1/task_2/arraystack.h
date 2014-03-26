#pragma once
#include "stack.h"
#include "iostream"

using namespace std;

template <typename type>
class ArrayStack : public Stack <type>
{
public:

	void addValue(type value);

	void deleteValue()
	{
		this->size--;
	}

	type returnFirst() const;

	type array[1000];
};

template <typename type>
void ArrayStack <type> :: addValue(type value)
{
	if (this->size > 1000)
	{
		cout << "Your stack is full, sorry" << endl;
		return;
	}
	array[this->size] = value;
	this->size++;
}

template <typename type>
type ArrayStack <type> :: returnFirst() const
{
	if (this->size == 0)
	{
		std::cout << "your stack is empty" << std::endl;
		return 0;
	}

	return array[this->size - 1];
}
