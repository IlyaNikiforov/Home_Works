
#include "iostream"
#include "charStructs.h"

using namespace std;


void createCharStack(Stack *stack)
{
	StackElement *elem = new StackElement;
	elem->value = 0;
	elem->next = nullptr;
	stack->first = elem;
}

void addCharElement(Stack *stack, char element)
{
	StackElement *newElement = new StackElement; 
	newElement->value = element;
	newElement->next = stack->first->next;
	stack->first->next = newElement;
}

void removeCharElement(Stack *stack)
{
	if (stack->first->next != nullptr)
	{
		StackElement *tmp = stack->first->next;
		stack->first->next = tmp->next;
		delete tmp;
	}
}

void deleteCharStack(Stack *stack)
{
	while (stack->first->next != nullptr)
	{
		StackElement *tmp = stack->first->next;
		stack->first->next = tmp->next;
		delete tmp;
	}

	delete stack->first;
	delete stack;
}