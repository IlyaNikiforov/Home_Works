#include "stdafx.h"
#include "iostream"
#include "structs.h"

using namespace std;

struct ListElement;

struct List;

void createListElement(ListElement *newElement, int value, ListElement *next)
{
	newElement->value = value;
	newElement->next = next;
}

void createList(List *list)
{
	ListElement *elem = new ListElement;
	createListElement(elem, 0, nullptr);
	list->first = elem;
}

void addSortedElement(List *list, int element)
{
	ListElement *newElement = new ListElement; 

	if (list->first->next == nullptr)
	{
		createListElement(newElement, element, nullptr);
		list->first->next = newElement;
	}
	
	else 
	{
		ListElement *current = list->first->next;
	
		while ((element > current->value) && (current->next != nullptr))
		{
			current = current->next;
		}

		if (current->next == nullptr)
		{
			createListElement(newElement, element, current->next);
			current->next = newElement;
		}
		
		else
		{
			createListElement(newElement, current->value, current->next);
			current->value = element;
			current->next = newElement;
		}
	}
}

void addElement(List *list, int element)
{
	ListElement *newElement = new ListElement; 
	newElement->value = element;
	newElement->next = list->first->next;
	list->first->next = newElement;
}

void removeFirstElement (List *list)
{
	if (list->first->next != nullptr)
	{
		ListElement *tmp = list->first->next;
		list->first->next = tmp->next;
		delete tmp;
	}
}

void removeElement(List *list, int element)
{
	if (list->first->next == nullptr)
		cout << "There are no elements in your array" << endl;
	else
	{
		ListElement *current = list->first->next;
		ListElement *previous = list->first;
	
		while ((element != current->value) && (current->next != nullptr))
		{
			previous = current;
			current = current->next;
		}
		
		if (element == current->value)
		{
			previous->next = current->next;
			delete current;
		}

		else 
			cout << "There are no elements with this value in your array" << endl;
	}
}

void printList(List *list)
{
	if (list->first->next != nullptr)
	{
			ListElement *current = list->first->next;
	
			while (current->next != nullptr)
			{
				cout << current->value << " ";
				current = current->next;
			}

			if (current->next == nullptr)
				cout << current->value << " ";
	}

	else 
		cout << "Your array is empty" << endl;
}

void removeList(List *list)
{
	if (list->first->next != nullptr)
	{
		ListElement *current = list->first->next;
	
		while (current->next != nullptr)
			{
				ListElement *tmp = current;
				current = current->next;
				list->first->next = current;
				delete tmp;
			}
		delete current;
	}
}