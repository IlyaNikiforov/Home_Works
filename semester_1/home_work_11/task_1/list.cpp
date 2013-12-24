
#include "iostream"
#include "structs.h"

using namespace std;

struct ListElement;

struct List;

ListElement* createListElement(double value, int degree, ListElement *next)
{
	ListElement *newElement = new ListElement;
	newElement->value = value;
	newElement->degree = degree;
	newElement->next = next;
	return newElement;
}

List* createList()
{
	List* list = new List;
	ListElement *elem = createListElement(0, 0, nullptr);
	list->first = elem;
	return list;
}

void addSortedElement(List *list, double element, int degree)
{
	if (list->first->next == nullptr)
	{
		ListElement *newElement = createListElement(element, degree, nullptr);
		list->first->next = newElement;
	}
	
	else 
	{
		ListElement *current = list->first->next;
	
		while ((degree > current->degree) && (current->next != nullptr))
			current = current->next;
		
		if (current->degree == degree)
		{
			current->value += element;
			return;
		}

		/*if (current->next == nullptr)
		{
			ListElement *newElement = createListElement(element, degree, current->next);
			current->next = newElement;
		}*/
		
		else
		{
			ListElement *newElement = createListElement(current->value, current->degree, current->next);
			current->value = element;
			current->degree = degree;
			current->next = newElement;
		}
	}
}


void printList(List *list)
{
	if (list->first->next != nullptr)
	{
			ListElement *current = list->first->next;
	
			while (current != nullptr)
			{
				cout << current->value << "x^" << current->degree << " ";
				current = current->next;
			}
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