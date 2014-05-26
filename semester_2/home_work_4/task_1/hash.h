#pragma once
#include "list.h"
#include "strings.h"
#include "hashfunction.h"

class Hash
{
	public:

		Hash(int size, HashFunction *newHashFunction);

		~Hash();

		void changeHashFunction(HashFunction *newHashFunction);

		void add(Strings *str);

		bool find(Strings *str);

		void del(Strings *str);

		void statistic();

		void print();

	private:

		int sizeOfHash;
		HashFunction *hashFunction;
		List **list;
};

