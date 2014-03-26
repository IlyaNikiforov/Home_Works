#include "arraylist.h"
#include "iostream"

using namespace std;

void ArrayList::addValue(int value)
{
	size++;
	if (size > 1000)
	{
		cout << "List is full, sorry" << endl;
		size--;
		return;
	}
	array[size-1] = value;
}

bool ArrayList::isExist(int value) const
{
	for (int i = 0; i < size; i++)
		if (array[i] == value)
			return true;
	return false;
}

void ArrayList::deleteValue(int value)
{
	if (!ArrayList::isExist(value))
	{
		cout << "This (" << value << ") element does not exist in your list" << endl;
		return;
	}
	int i = 0;
	while (array[i] != value)
		i++;
	for (int j = i; j < size - 1; j++)
		array[j] = array[j + 1];
	size--;
}

void ArrayList::print() const
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

int ArrayList::getSize() const
{
	return size;
}
