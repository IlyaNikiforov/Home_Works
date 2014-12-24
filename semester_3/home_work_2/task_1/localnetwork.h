#pragma once
#include "computer.h"
#include "QList"
#include "string.h"
#include "random.h"

class LocalNetwork
{
public:
	LocalNetwork(char* nameOfFile, Random *random);
	~LocalNetwork();
	void makeMove();
	void printStatictics();
	bool isInfected (int id);
	bool isFinished();
private:
	QList<Computer*> listOfComputers;
	int amountOfComputers;
	Random *randomizer;
};


