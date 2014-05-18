#pragma once
#include "list.h"
#include "strings.h"

class Hash
{
	public:

		Hash(int size);

		~Hash();

		int hashFunction(Strings *str);

		void changeHashFunction(int newFactor, int newMod);

		void add(Strings *str);

		bool find(Strings *str);

		void del(Strings *str);

		void statistic();

		void print();

	private:

		int sizeOfHash;
		int factor;
		int mod;
		List **list;
};

