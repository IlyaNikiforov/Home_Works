#pragma once
#include "stack.h"
#include "iostream"

template <typename type>
class ArrayStack : public Stack <type>
{
public:

    ArrayStack()
    {
    }

    ~ArrayStack()
    {
    }

    void addValue(type value)
    {
        array[this->size] = value;
        this->size++;
    }

    void deleteValue()
    {
        this->size--;
    }

    type returnFirst() const
    {
        if (this->size == 0)
        {
            std::cout << "your stack is empty" << std::endl;
            return 0;
        }

        return array[this->size - 1];
    }

    type array[1000];
};
