
#include "iostream"
#include "intStructs.h"

using namespace std;


void createIntStack(Stack *stack)
{
	StackElement *elem = new StackElement;
	elem->value = 0;
	elem->next = nullptr;
	stack->first = elem;
}

void addIntElement(Stack *stack, int element)
{
	StackElement *newElement = new StackElement; 
	newElement->value = element;
	newElement->next = stack->first->next;
	stack->first->next = newElement;
}

void removeIntElement(Stack *stack)
{
	if (stack->first->next != nullptr)
	{
		StackElement *tmp = stack->first->next;
		stack->first->next = tmp->next;
		delete tmp;
	}
}

void deleteIntStack(Stack *stack)
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