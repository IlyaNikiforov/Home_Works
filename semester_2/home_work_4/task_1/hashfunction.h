#pragma once
#include "strings.h"

class HashFunction
{
	public:
		HashFunction() {}
		virtual int hash(Strings *str) = 0;
};
