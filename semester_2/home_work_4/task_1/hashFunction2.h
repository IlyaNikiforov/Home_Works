#pragma once
#include "hashfunction.h"

class HashFunction2 : public HashFunction
{
	int hash(Strings *str)
	{
		int index = 0;
		char temp = 0;
		for (int i = 0; i < str->returnLength(); i++)
		{
			temp = str->element(i);
			index += (i + 1) * (temp - '0') * (73 + i);
		}
		index %= 100;

		if (index < 0)
			index = -index;
		return index;
	}
};
