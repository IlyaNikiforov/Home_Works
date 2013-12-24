#include "stdafx.h"
#include "iostream"
#include "structs.h"

using namespace std;

struct ListElement;

struct List;

/*void createList(List *list)
{
	list = new List;
	ListElement *elem = new ListElement;
	elem->value = 1;
	elem->next = nullptr;
	list->first = elem;
}*/

void addElement(List *list, int element)
{
	ListElement *newElement = new ListElement;
	
	if (list->first->next == nullptr)
	{
		newElement->value = element;
		newElement->next = list->first;
		list->first->next = newElement;
	}
	
	else
	{
		newElement->value = element;
		newElement->next = list->first->next;
		list->first->next = newElement;
	}

	//cout << list->first->next->value << " ";
}

void removeElement(List *list, int index)
{
	ListElement *current = list->first->next;
	ListElement *previous = list->first;
	
	if (index == 0)
	{
		while (current != list->first)
		{
			previous = current;
			current = current->next;
		}
		list->first = current->next;
	}
	
	else
	{
		for (int i = 1; i < index; i++)
		{
			previous = current;
			current = current->next;
		}
	}
		
	previous->next = current->next;
	delete current;	
}

void printList(List *list)
{
	ListElement *current = list->first;
	
	do
	{
		cout << current->value << " ";
		current = current->next;
	} 
	while (current->value != list->first->value);
}