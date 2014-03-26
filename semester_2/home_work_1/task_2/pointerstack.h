#pragma once
#include "stack.h"
#include "iostream"

template <typename type>
class PointerStack : public Stack <type>
{
public:

    PointerStack()
    {
        first = nullptr;
    }

    ~PointerStack()
    {
        while (first != nullptr)
            {
                StackElement *temp = first->next;

                delete first;

                first = temp;
            }
    }

    void addValue(type value)
    {
        StackElement *temp = new StackElement;
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

        this->size++;
    }

    void deleteValue()
    {
        StackElement *temp = first;
        first = first->next;
        delete temp;
        this->size--;
    }

    type returnFirst() const
    {
        if (first == nullptr)
        {
            std::cout << "your stack is empty" << std::endl;
            return 0;
        }

        return first->value;
    }

    struct StackElement
    {
        type value;
        StackElement *next;
    };

    StackElement *first;
};

