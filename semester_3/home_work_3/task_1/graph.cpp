#include "graph.h"
#include "iostream"
#include "fstream"
#include "QList"

using namespace std;

Graph::Graph(char* nameOfFile)
{
	ifstream in (nameOfFile);
	if (!in)
	{
		std::cout << "Error reading from file" << std::endl;
		return;
	}
	in >> sizeOfGraph;
	robotPositions = new bool [sizeOfGraph];
	for (int i = 0; i < sizeOfGraph; i++)
		in >> robotPositions[i];
	matrix = new bool *[sizeOfGraph];
	changedMatrix = new bool *[sizeOfGraph];
	for (int i = 0; i < sizeOfGraph; i++)
	{
		matrix[i] = new bool [sizeOfGraph];
		changedMatrix[i] = new bool [sizeOfGraph];
	}
	for (int i = 0; i < sizeOfGraph; i++)
		for (int j = 0; j < sizeOfGraph; j++)
		{
			in >> matrix[i][j];
			changedMatrix[i][j] = false;
		}
	in.close();
}

Graph::~Graph()
{
	for (int i = 0; i < sizeOfGraph; i++)
	{
		delete matrix[i];
		delete changedMatrix[i];
	}
	delete[] matrix;
	delete[] changedMatrix;
	delete robotPositions;
}

void Graph::transformMatrix()
{
	for (int i = 0; i < sizeOfGraph; i++)
		for (int j = 0; j < sizeOfGraph; j++)
		{
			if(matrix[i][j])
			{
				for (int k = 0; k < sizeOfGraph; k++)
					changedMatrix[i][k] = matrix[j][k] || changedMatrix[i][k];
				changedMatrix[i][i] = 0;
			}
		}
}

bool Graph::IsAllRobotsCrashable()
{
	transformMatrix();
	bool *notVisited = new bool[sizeOfGraph];
	for (int i = 0; i < sizeOfGraph; i++)
		notVisited[i] = true;
	QList<int> visited;
	QList<int> queue;
	for (int i = 0; i < sizeOfGraph; i++)
	{
		if (!notVisited[i])
			continue;
		queue.append(i);
		while (!queue.isEmpty())
		{
			for (int i = 0; i < sizeOfGraph; i++)
				if (changedMatrix[queue.at(0)][i]
						&& !queue.contains(i)
						&& !visited.contains(i))
					queue.append(i);
			visited.append(queue.at(0));
			notVisited[queue.at(0)] = false;
			queue.removeAt(0);
		}
		int counter = 0;
		for (int i = 0; i < sizeOfGraph; i++)
			if(robotPositions[i] && visited.contains(i))
				counter++;
		if (counter <= 1)
		{
			delete notVisited;
			return false;
		}
		counter = 0;
		visited.clear();
	}

	delete notVisited;
	return true;
}
