
#include "iostream"
#include "structs.h"

using namespace std;


void createStack(Stack *stack)
{
	StackElement *elem = new StackElement;
	elem->value = 0;
	elem->next = nullptr;
	stack->first = elem;
}

void addElement(Stack *stack, char element)
{
	StackElement *newElement = new StackElement; 
	newElement->value = element;
	newElement->next = stack->first->next;
	stack->first->next = newElement;
}

void removeElement(Stack *stack)
{
	if (stack->first->next != nullptr)
	{
		StackElement *tmp = stack->first->next;
		stack->first->next = tmp->next;
		delete tmp;
	}
}

void deleteStack(Stack *stack)
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