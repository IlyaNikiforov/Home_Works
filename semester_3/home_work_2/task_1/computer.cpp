#include "computer.h"

bool Computer::isInfected()
{
	return infection;
}

float Computer::getBrobability()
{
	return probabilityOfInfection;
}

void Computer::addNeighbour(int neighboursID)
{
	listOfNeighbours.append(neighboursID);
}

int Computer::getID()
{
	return id;
}

bool Computer::tryToInfect()
{
	float x = randomizer->getRandom();
	if (x <= probabilityOfInfection)
		infection = true;
	return infection;
}
