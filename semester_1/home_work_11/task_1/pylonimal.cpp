#include "iostream"
#include "list.h"
#include "math.h"
#include "pylonimal.h"

using namespace std;

bool pylIsEqual(List* pyl1, List* pyl2)
{
	ListElement *current1 = pyl1->first->next;
	ListElement *current2 = pyl2->first->next;
	while (current1 != nullptr || current2 != nullptr)
	{
		if (current1->degree != current2->degree || current1->value != current2->value)
			return 0;
		current1 = current1->next;
		current2 = current2->next;
	}

	if (current1 == nullptr || current2 == nullptr)
		return 1;
	return 0;
}

float pylValue(List *pyl, double x)
{
	double result = 0;
	ListElement *current = pyl->first->next;
	
	while (current != nullptr)
	{
		result += current->value * pow(x, double(current->degree));
		current = current->next;
	}

	return result;
}

void pylAdd(List *pyl1, List* pyl2)
{
	ListElement *current1 = pyl1->first->next;
	ListElement *previous1 = pyl1->first;
	ListElement *current2 = pyl2->first->next;
	//ListElement *previous2 = pyl1->first;

	while (current2 != nullptr)
	{
		while (current1 != nullptr && current1->degree != current2->degree)
		{
			previous1 = current1;
			current1 = current1->next;
		}

		if (current1 == nullptr)
			addSortedElement(pyl1, current2->value, current2->degree);

		if (current1->degree == current2->degree)
		{
			if (current1->value == -current2->value)
			{
				previous1->next = current1->next;
				current1->next = nullptr;
				delete current1;
			}

			else
				current1->value += current2->value;
		}

		current2 = current2->next;
	}

	removeList(pyl2);
	delete pyl2->first;
	delete pyl2;
}