#include "list.h"
#include <iostream>

using namespace std;


List::~List()
{
	while (first != nullptr)
		{
			ListElement *temp = first->next;

			delete first->value;
			delete first;

			first = temp;
		}
}

void List::addValue(Strings *value)
{
	if (isExist(value))
	{
		ListElement *current = first;
		while (!current->value->isEqual(value))
			current = current->next;
		current->count++;
		return;
	}
	ListElement *temp = new ListElement;
	temp->count = 1;
	temp->value = value;

	temp->next = first;
	first = temp;

	size++;
}

bool List::isExist(Strings* value) const
{
	ListElement *current = first;
	while (current != nullptr && !current->value->isEqual(value))
		current = current->next;
	if (current == nullptr)
		return false;
	return true;
}

void List::deleteValue(Strings* value)
{
	if (!List::isExist(value))
	{
		//cout << "This (" << value << ") element does not exist in your list" << endl;
		return;
	}

	if (value->isEqual(first->value))
	{
		if (first->count > 1)
		{
			first->count--;
			return;
		}
		ListElement *temp = first;
		first = first->next;

		delete temp;

		size--;
		return;
	}

	ListElement *current = first;

	while (!current->next->value->isEqual(value))
			current = current->next;

	if (current->next->count > 1)
	{
		current->next->count--;
		return;
	}
	ListElement *temp = current->next;
	current->next = current->next->next;
	delete temp;
	size--;
}

void List::print() const
{
	ListElement *temp = first;

		while (temp != nullptr)
		{
			temp->value->print();
			cout << "(" << temp->count << ")" << ' ';

			temp = temp->next;
		}

		cout << endl;
}

int List::getSize() const
{
	return size;
}

Strings *List::element(int i)
{
	if (i >= size)
		return nullptr;
	ListElement *current = first;
	for (int j = 0; j < i; j++)
		current = current->next;
	return current->value;
}

int List::getCount(int i)
{
	if (i >= size)
		return 0;
	ListElement *current = first;
	for (int j = 0; j < i; j++)
		current = current->next;
	return current->count;
}
