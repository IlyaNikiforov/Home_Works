#pragma once
#include "QList"
#include "random.h"

class Computer
{
public:
	Computer(int id, bool inf, float probability, Random *random)
		: id(id), infection(inf), probabilityOfInfection(probability), randomizer(random) {}
	~Computer() {}
	bool isInfected();
	float getBrobability();
	bool tryToInfect();
	void addNeighbour(int neighboursID);
	int getID();
	QList<int> listOfNeighbours;
private:
	int id;
	bool infection;
	float probabilityOfInfection;
	Random *randomizer;
};


