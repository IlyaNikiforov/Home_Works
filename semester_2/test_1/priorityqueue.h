#pragma once
#include "iostream"

using namespace std;

template <typename type>
class PriorityQueue
{
public:

	PriorityQueue();
	~PriorityQueue();

	void enqueue(type value, int key); /// programm adds new element to queue according to it's key
	type dequeue(); /// programm deletes first element from queue
	int getSize() const;

	private:

		struct ListElement
		{
			type value;
			int key;
			ListElement *next;
		};

		int size;
		ListElement *first;
	};

class QueueError
{
public:
QueueError(char *errorText) {}
};




template <typename type>
PriorityQueue <type> ::PriorityQueue()
{
	first = nullptr;
	size = 0;
}


template <typename type>
PriorityQueue <type> ::~PriorityQueue()
{
	while (first != nullptr)
		{
			ListElement *temp = first->next;

			delete first;

			first = temp;
		}
}


template <typename type>
void PriorityQueue <type> ::enqueue(type value, int key)
{
	ListElement *temp = new ListElement;
	temp->value = value;
	temp->key = key;

	if (first == nullptr)
	{
		temp->next = nullptr;
		first = temp;
	}

	else
	{
		ListElement *current = first;

		if (first->key < key)
		{
			first = temp;
			temp->next = current;
			size++;
			return;
		}

		while (current->next->key > key)
			current = current->next;
		temp->next = current->next;
		current->next = temp;
	}

	size++;
}

template <typename type>
type PriorityQueue <type> ::dequeue()
{

	if (PriorityQueue::getSize() == 0)
		throw QueueError("Queue is empty!");

	type temp = first->value;
	ListElement *current = first->next;
	delete first;
	first = current;
	size--;
	return temp;
}


template <typename type>
int PriorityQueue <type> ::getSize() const
{
	return size;
}
