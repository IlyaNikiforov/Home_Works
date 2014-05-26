#include "hash.h"
#include "iostream"

using namespace std;

Hash::Hash(int size, HashFunction *newHashFunction)
{
	sizeOfHash = size;
	hashFunction = newHashFunction;
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

void Hash::changeHashFunction(HashFunction *newHashFunction)
{
	hashFunction = newHashFunction;
	List **list1 = new List *[sizeOfHash];
	for (int i = 0; i < sizeOfHash; i++)
		list1[i] = new List;
	for (int i = 0; i < sizeOfHash; i++)
	{
		while (list[i]->getSize() > 0)
		{
			const int n = hashFunction->hash(list[i]->element(0)) % sizeOfHash;
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
	const int n = hashFunction->hash(str) % sizeOfHash;
	list[n]->addValue(str);
}

bool Hash::find(Strings *str)
{
	const int n = hashFunction->hash(str) % sizeOfHash;
	return list[n]->isExist(str);
}

void Hash::del(Strings *str)
{
	if (!find(str))
		return;
	const int n = hashFunction->hash(str) % sizeOfHash;
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

