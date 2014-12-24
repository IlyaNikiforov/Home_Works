#pragma once


class Graph
{
public:
	Graph(char* nameOfFile);
	~Graph();
	bool IsAllRobotsCrashable();
private:
	void transformMatrix();
	bool **matrix;
	bool **changedMatrix;
	bool *robotPositions;
	int sizeOfGraph;
};

