#pragma once

template <typename type>
class Stack
{
public:
    Stack()
    {
        size = 0;
    }
    ~Stack() {}
    virtual void addValue(type value) = 0;
    virtual void deleteValue() = 0;
    virtual type returnFirst() const = 0;
    int returnSize() const
    {
        return size;
    }

protected:
    int size;
};


