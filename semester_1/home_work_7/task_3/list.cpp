
#include "iostream"
#include "structs.h"
#include "strings.h"

using namespace std;

struct ListElement;

struct List;

ListElement* createListElement()
{
	ListElement *newElement = new ListElement;
	newElement->value = nullptr;
	newElement->next = nullptr;
	newElement->count = 0;
	return newElement;
}

void addElement(List *list, String *element)
{
	ListElement *newElement = new ListElement; 
	newElement->next = list->first->next;
	newElement->value = strClone(element);
	newElement->count = 1;
	list->first->next = newElement;
	list->length++;
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
				strDelete(tmp->value);
				delete tmp->value;
				delete tmp;
			}
		strDelete(current->value);
		delete current->value;
		delete current;
	}
}

void printList(List *list)
{
	ListElement *current = list->first->next;
	for (int i = 0; i < list->length; i++)
	{
		cout << current->value << "(" << current->count << ") ";
		current = current->next;
	}
}