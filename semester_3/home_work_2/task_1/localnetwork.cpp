#include "localnetwork.h"
#include "fstream"
#include "iostream"

using namespace std;

LocalNetwork::LocalNetwork(char* nameOfFile, Random *random)
{
	//randomizer = random;
	ifstream in (nameOfFile);
	if (!in)
	{
		cout << "There is no file witn such name." << endl;
		return;
	}
	in >> amountOfComputers;
	bool infection;
	float probability;
	for (int i = 0; i < amountOfComputers; i++)
	{
		in >> infection >> probability;
		Computer *computer = new Computer(i, infection, probability, random);
		listOfComputers.append(computer);
	}
	bool isNeighbour;
	for (int i = 0; i < amountOfComputers; i++)
	{
		for (int j = 0; j < amountOfComputers; j++)
		{
			in >> isNeighbour;
			if (isNeighbour)
				listOfComputers.at(i)->addNeighbour(j);
		}
	}
	in.close();
}

LocalNetwork::~LocalNetwork()
{
	listOfComputers.clear();
}

void LocalNetwork::makeMove()
{
	QList<int> recentlyInfected;
	for (int i = 0; i < amountOfComputers; i++)

		if(listOfComputers.at(i)->isInfected()
			&& !recentlyInfected.contains(listOfComputers.at(i)->getID()))

			for (int j = 0; j < listOfComputers.at(i)->listOfNeighbours.size(); j++)

				if(!listOfComputers.at(listOfComputers.at(i)->listOfNeighbours.at(j))->isInfected()
					&& listOfComputers.at(listOfComputers.at(i)->listOfNeighbours.at(j))->tryToInfect())

					recentlyInfected.append(listOfComputers.at(i)->listOfNeighbours.at(j));
}

void LocalNetwork::printStatictics()
{
	for (int i = 0; i < amountOfComputers; i++)
		cout << i << "(" << listOfComputers.at(i)->isInfected() << ") ";
	cout << endl;
}

bool LocalNetwork::isInfected(int id)
{
	return listOfComputers.at(id)->isInfected();
}

bool LocalNetwork::isFinished()
{
	for (int i = 0; i < amountOfComputers; i++)
		if (!listOfComputers.at(i)->isInfected())
			return false;
	return true;
}
