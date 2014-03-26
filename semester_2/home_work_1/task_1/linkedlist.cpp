#include "linkedlist.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() : List()
{
    first = nullptr;
}

LinkedList::~LinkedList()
{
    while (first != nullptr)
        {
            ListElement *temp = first->next;

            delete first;

            first = temp;
        }
}

void LinkedList::addValue(int value)
{
    ListElement *temp = new ListElement;
    temp->value = value;

    if (first == nullptr)
    {
        temp->next = nullptr;
        first = temp;
    }

    else
    {
        temp->next = first;
        first = temp;
    }

    size++;
}

bool LinkedList::isExist(int value) const
{
    ListElement *current = first;
    while (current != nullptr && current->value != value)
        current = current->next;
    if (current == nullptr)
        return false;
    return true;
}

void LinkedList::deleteValue(int value)
{
    if (!LinkedList::isExist(value))
    {
        cout << "This (" << value << ") element does not exist in your list" << endl;
        return;
    }

    if (value == first->value)
    {
        ListElement *temp = first;
        first = first->next;

        delete temp;

        size--;
        return;
    }

    ListElement *current = first;

    while (current->next->value != value)
            current = current->next;

    ListElement *temp = current->next;
    current->next = current->next->next;
    delete temp;
    size--;}

void LinkedList::print() const
{
    ListElement *temp = first;

        while (temp != nullptr)
        {
            cout << temp->value << ' ';

            temp = temp->next;
        }

        cout << endl;
}

int LinkedList::getSize() const
{
    return size;
}
