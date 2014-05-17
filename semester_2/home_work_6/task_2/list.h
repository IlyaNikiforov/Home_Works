#pragma once
#include "iostream"

using namespace std;

template <typename type>
class List
{
	public:
		List() : size(0), first(nullptr) {}
		~List();
		void add(type value);
		void del(type value);
		/// Returns amount of this element in list. If there is no such element, returns 0.
		int isExists(type value);
		type element(int i);
		int getSize();
		void print();

	private:
		struct ListElement
		{
			type value;
			int count;
			ListElement *next;
		};

		ListElement *first;
		int size;
};

template <typename type>
List <type> ::~List()
{
	while (first != nullptr)
	{
		ListElement *temp = first;
		first = first->next;
		delete temp;
	}
}

template <typename type>
type List <type> ::element(int i)
{
	if (size <= i)
		return 0;
	ListElement *current = first;
	for (int j = 0; j < i; j++)
		current = current->next;
	return current->value;
}

template <typename type>
void List <type> ::add(type value)
{
	if (first == nullptr)
	{
		ListElement *newElement = new ListElement;
		newElement->next = nullptr;
		newElement->value = value;
		newElement->count = 1;
		first = newElement;
		size++;
		return;
	}
	ListElement *current = first;
	while (value > current->value && current->next != nullptr)
		current = current->next;

	if (current->value == value)
	{
		current->count++;
		size++;
		return;
	}

	ListElement *newElement = new ListElement;

	if (current->next == nullptr && current->value < value)
	{
		newElement->value = value;
		newElement->count = 1;
		newElement->next = nullptr;
		current->next = newElement;
		size++;
		return;
	}

	newElement->value = current->value;
	newElement->count = current->count;
	current->value = value;
	current->count = 1;
	newElement->next = current->next;
	current->next = newElement;

	size++;
}

template <typename type>
int List <type> ::isExists(type value)
{
	ListElement *current = first;
	while (current != nullptr)
	{
		if (current->value == value)
			return current->count;
		current = current->next;
	}

	return 0;
}

template <typename type>
void List <type> ::del(type value)
{
	if (!isExists(value))
		return;

	ListElement *current = first;
	ListElement *previous = current;

	while (current->value != value)
	{
		previous = current;
		current = current->next;
	}

	if (current->count > 1)
	{
		size--;
		current->count--;
		return;
	}

	if (first->value == value)
	{
		first = first->next;
		delete current;
		size--;
		return;
	}

	previous->next = current->next;
	delete current;

	size--;
}

template <typename type>
int List <type> ::getSize()
{
	return size;
}

template <typename type>
void List <type> ::print()
{
	ListElement *current = first;
	for (int i = 0; i < size; i++)
	{
		current->value << "(" << current->count << ")" << " ";
		current = current->next;
	}
	cout << endl;
}



