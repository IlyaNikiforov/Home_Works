
#include "list.h"
#include "strings.h"
#include "iostream"

using namespace std;

List** hashCreate(int sizeOfHash)
{
	List **list = new List*[sizeOfHash];

	for (int i = 0; i < sizeOfHash; i++)
	{
		list[i] = new List;
		list[i]->first = createListElement();
		list[i]->length = 0;
	}

	return list;
}

int hashFunction(String *str, int sizeOfHash)
{
	int index = 0;
	for (int i = 0; i < str->length; i++)
		index += (i + 1) * (str->begin[i] - '0') * (107 + i);
	index %= sizeOfHash;
	
	if (index < 0)
		index = -index;
	return index;
}

void hashAdd(String *str, List **hashTable, int sizeOfHash)
{
	const int n = hashFunction(str, sizeOfHash);
	
	if (hashTable[n]->length == 0)
	{
		addElement(hashTable[n], str);
		return;
	}

	ListElement *current = hashTable[n]->first->next;

	for (int i = 0; i < hashTable[n]->length; i++)
	{
		if (strIsEqual(str, current->value))
		{
			current->count++;
			return;
		}
		current = current->next;
	}

	addElement(hashTable[n], str);
}

bool hashExist(String *str, List **hashTable, int sizeOfHash)
{
	const int n = hashFunction(str, sizeOfHash);
	
	if (hashTable[n]->length == 0)
		return false;

	ListElement *current = hashTable[n]->first->next;

	for (int i = 0; i < hashTable[n]->length; i++)
	{
		if (strIsEqual(str, current->value))
			return true;
		current = current->next;
	}

	return false;
}

void hashPrint(List** hashTable, int sizeOfHash)
{
	for (int i = 0; i < sizeOfHash; i++)
	{
		ListElement *current = hashTable[i]->first->next;
		
		for (int j = 0; j < hashTable[i]->length; j++)
		{
			cout << " This word meets " << current->count << " time(s): " << current->value->begin << endl;
			current = current->next;
		}
	}
}

void hashDelete(List** &hashTable, int sizeOfHash)
{
	for (int i = 0; i < sizeOfHash; i++)
	{
		removeList(hashTable[i]);
		delete hashTable[i]->first;
		delete hashTable[i];
	}

	delete[] hashTable;
}