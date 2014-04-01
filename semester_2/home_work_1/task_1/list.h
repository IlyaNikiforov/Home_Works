#pragma once

class List
{
public:
	List() : size(0) {}
	virtual ~List() {}
	virtual void addValue(int value) = 0; /// adds value, chosen by user
	virtual bool isExist(int value) const = 0; /// programm checks the existing of element in list
	virtual void deleteValue(int value) = 0; /// deletes value, chosen by user
	virtual void print() const = 0; /// prints list to console
	virtual int getSize() const = 0; /// programm returns the amount of elements in list

protected:
	int size; /// amount of elements in list
};


