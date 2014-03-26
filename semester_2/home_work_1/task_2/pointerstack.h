#pragma once
#include "stack.h"
#include "iostream"

template <typename type>
class PointerStack : public Stack <type>
{
public:

	PointerStack() : first(nullptr) {}

	~PointerStack();

	void addValue(type value);

	void deleteValue();

	type returnFirst() const;

	struct StackElement
	{
		type value;
		StackElement *next;
	};

	StackElement *first;
};


template <typename type>
PointerStack <type> :: ~PointerStack()
{
	while (first != nullptr)
		{
			StackElement *temp = first->next;
			delete first;
			first = temp;
		}
}

template <typename type>
void PointerStack <type> :: addValue(type value)
{
	StackElement *temp = new StackElement;
	temp->value = value;
	if (first == nullptr)
	{
		temp->next = nullptr;
		first = temp;
	}
	else
	{
		temp->next = first;
		first = temp;
	}
	this->size++;
}

template <typename type>
void PointerStack <type> :: deleteValue()
{
	StackElement *temp = first;
	first = first->next;
	delete temp;
	this->size--;
}

template <typename type>
type PointerStack <type> :: returnFirst() const
{
	if (first == nullptr)
	{
		std::cout << "your stack is empty" << std::endl;
		return 0;
	}
	return first->value;
}

