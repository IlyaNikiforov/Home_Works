#include "hash.h"
#include "iostream"

using namespace std;

Hash::Hash(int size)
{
	sizeOfHash = size;
	mod = 1000;
	factor = 107;
	list = new List*[sizeOfHash];

	for (int i = 0; i < sizeOfHash; i++)
	{
		list[i] = new List;
	}
}

Hash::~Hash()
{
	for (int i = 0; i < sizeOfHash; i++)
	{
		delete list[i];
	}

	delete[] list;
}

int Hash::hashFunction(Strings *str)
{
	int index = 0;
	char temp = 0;
	for (int i = 0; i < str->returnLength(); i++)
	{
		temp = str->element(i);
		index += (i + 1) * (temp - '0') * (factor + i);
	}
	index %= mod;

	if (index < 0)
		index = -index;
	return index % sizeOfHash;
}

void Hash::changeHashFunction(int newFactor, int newMod)
{
	mod = newMod;
	factor = newFactor;
	List **list1 = new List *[sizeOfHash];
	for (int i = 0; i < sizeOfHash; i++)
		list1[i] = new List;
	for (int i = 0; i < sizeOfHash; i++)
	{
		while (list[i]->getSize() > 0)
		{
			const int n = hashFunction(list[i]->element(0));
			list1[n]->addValue(list[i]->element(0));
			list[i]->deleteValue(list[i]->element(0));
		}
		delete list[i];
	}
	delete[] list;
	list = list1;
}

void Hash::add(Strings *str)
{
	const int n = hashFunction(str);
	list[n]->addValue(str);
}

bool Hash::find(Strings *str)
{
	const int n = hashFunction(str);
	return list[n]->isExist(str);
}

void Hash::del(Strings *str)
{
	if (!find(str))
		return;
	const int n = hashFunction(str);
	list[n]->deleteValue(str);
}

void Hash::statistic()
{
	int maxLength = 0;
	int wordAmount = 0;
	int emptyValues = 0;
	int sumLength = 0;

	for (int i = 0; i < sizeOfHash; i++)
	{
		if (maxLength < list[i]->getSize())
			maxLength = list[i]->getSize();

		for (int j = 0; j < list[i]->getSize(); j++)
			wordAmount += list[i]->getCount(j);

		if (list[i]->getSize() == 0)
			emptyValues++;

		sumLength += list[i]->getSize();
	}

	cout << "max length: " << maxLength << endl;
	cout << "word amount: " << wordAmount << endl;
	cout << "load factor: " << float(wordAmount / float(sizeOfHash)) << endl;
	cout << "empty values: " << emptyValues << endl;
	cout << "mean length: " << float(sumLength) / float(sizeOfHash - emptyValues) << endl;
}

void Hash::print()
{
	for (int i = 0; i < sizeOfHash; i++)
	{
		cout << i << ": ";
		if (list[i]->getSize() > 0)
			list[i]->print();
		else
			cout << "0" << endl;
	}
}

