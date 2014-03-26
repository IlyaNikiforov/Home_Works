#pragma once

class List
{
public:
    List();
    virtual ~List() = 0;
    virtual void addValue(int value) = 0;
    virtual bool isExist(int value) const = 0;
    virtual void deleteValue(int value) = 0;
    virtual void print() const = 0;
    virtual int getSize() const = 0;

protected:
    int size;
};


