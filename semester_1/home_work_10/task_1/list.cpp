
#include "iostream"
#include "structs.h"
#include "strings.h"

using namespace std;

struct ListElement;

struct List;

ListElement* createListElement(char value, ListElement *next)
{
	ListElement *newElement = new ListElement;
	newElement->value = createNode(1, value);
	newElement->next = next;
	return newElement;
}

List* createList()
{
	List* list = new List;
	ListElement *elem = createListElement(0, nullptr);
	list->first = elem;
	return list;
}

void addSortedElement(List *list, char element)
{
	if (list->first->next == nullptr)
		list->first->next = createListElement(element, nullptr);
	
	else 
	{
		ListElement *current = list->first->next;
		ListElement *previous = current;
	
		while ((element != current->value->symbol) && (current->next != nullptr))
		{
			previous = current;
			current = current->next;
		}

		if (element == current->value->symbol)
		{
			current->value->value++;
			if (current->next == nullptr)
				return;

			if (current->next->value->value < current->value->value)
			{
				ListElement *changer = current;
				current = current->next;
				while (current->next != nullptr && current->next->value->value < changer->value->value)
					current = current->next;
				char temp = current->value->symbol;
				current->value->symbol = changer->value->symbol;
				changer->value->symbol = temp;
				current->value->value += changer->value->value;
				changer->value->value = current->value->value - changer->value->value;
				current->value->value = current->value->value - changer->value->value;
			}
			return;
		}

		if (current->next == nullptr)
			list->first->next = createListElement(element, list->first->next);
		
		else
		{
			ListElement* newElement = createListElement(current->value->symbol, current->next);
			current->value->symbol = element;
			current->next = newElement;
		}
	}
}

void addSortedElement(List *list, TreeNode *treeNode)
{
	if (list->first->next == nullptr)
	{
		ListElement* newElement =  new ListElement;
		newElement->value = treeNode;
		newElement->next = nullptr;
		list->first->next = newElement;
		return;
	}

	ListElement *current = list->first->next;
	ListElement *previous = list->first;
	
	while (current->value->value < treeNode->value && current->next != nullptr)
	{
		previous = current;
		current = current->next;
	}
	
	ListElement* newElement =  new ListElement;
	newElement->value = treeNode;
	newElement->next = previous->next;
	previous->next = newElement;
}

TreeNode* removeFirstElement (List *list)
{
	if (list->first->next != nullptr)
	{
		ListElement *tmp = list->first->next;
		list->first->next = tmp->next;
		TreeNode *node = tmp->value;
		delete tmp;
		return node;
	}

	return nullptr;
}

void printList(List *list)
{
	if (list->first->next != nullptr)
	{
			ListElement *current = list->first->next;
	
			while (current->next != nullptr)
			{
				cout << current->value->symbol << "(" << current->value->value << ")" << " ";
				current = current->next;
			}

			if (current->next == nullptr)
				cout << current->value->symbol << "(" << current->value->value << ")" << " ";
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