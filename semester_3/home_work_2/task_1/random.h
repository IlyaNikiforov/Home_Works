#pragma once
#include "time.h"

class Random
{
public:
	virtual double getRandom() = 0;
	virtual ~Random() {}
};

class TrueRandom : public Random
{
public:
	TrueRandom() {}
	~TrueRandom() {}
	double getRandom()
	{
		return rand() / double(RAND_MAX);
	}
private:
};

class TestRandom : public Random
{
public:
	~TestRandom() {}
	double getRandom()
	{
		count += diff;
		return (double)(count % 10) / 10;
	}
private:
	int count = 0;
	const int diff = 3;
};
