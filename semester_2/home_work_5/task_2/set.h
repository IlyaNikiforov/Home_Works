#pragma once
#include "iostream"

using namespace std;

template <typename type>
class Set
{
	public:
		Set() : size(0), first(nullptr) {}
		~Set();
		void add(type value);
		void del(type value);
		int isExists(type value);
		type element(int i);
		///intersection of two Sets. Returns new Set
		static Set<type> *intersection(Set *list1, Set *list2);
		///unification of two Sets. Returns new Set
		static Set<type> *unification(Set *list1, Set *list2);
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
Set <type> ::~Set()
{
	while (first != nullptr)
	{
		ListElement *temp = first;
		first = first->next;
		delete temp;
	}
}

template <typename type>
type Set <type> ::element(int i)
{
	if (size <= i)
		return 0;
	ListElement *current = first;
	for (int j = 0; j < i; j++)
		current = current->next;
	return current->value;
}

template <typename type>
void Set <type> ::add(type value)
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
int Set <type> ::isExists(type value)
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
void Set <type> ::del(type value)
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
Set<type> *Set <type> ::intersection(Set *list1, Set *list2)
{
	Set *list = new Set;
	int temp1 = 0;
	int temp2 = 0;
	int size = list1->getSize();
	for (int i = 0; i < size; i++)
	{
		temp1 = list1->isExists(list1->element(i));
		temp2 = list2->isExists(list1->element(i));
		if (temp2 > temp1)
			for (int j = 0; j < temp1; j++)
				list->add(list1->element(i));
		else
			for (int j = 0; j < temp2; j++)
				list->add(list1->element(i));
	}
	return list;
}

template <typename type>
Set<type>* Set<type>::unification(Set *list1, Set *list2)
{
	Set *list = new Set;
	int size = list2->getSize();
	int temp1 = 0;
	int temp2 = 0;
	for (int i = 0; i < size; i++)
	{
		temp2 = list2->isExists(list2->element(i));
		for (int j = 0; j < temp2; j++)
			list->add(list2->element(i));
	}

	size = list1->getSize();

	for (int i = 0; i < size; i++)
	{
		temp1 = list1->isExists(list1->element(i));
		temp2 = list2->isExists(list1->element(i));
		if (temp1 > temp2)
			for (int j = 0; j < temp1 - temp2; j++)
				list->add(list1->element(i));
	}
	return list;
}

template <typename type>
int Set <type> ::getSize()
{
	return size;
}

template <typename type>
void Set <type> ::print()
{
	ListElement *current = first;
	for (int i = 0; i < size; i++)
	{
		current->value << "(" << current->count << ")" << " ";
		current = current->next;
	}
	cout << endl;
}



