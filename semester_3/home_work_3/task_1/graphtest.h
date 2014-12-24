#pragma once
#include "graph.h"
#include <QObject>
#include <QtTest/QtTest>


class GraphTest : public QObject
{
	Q_OBJECT
public:
	explicit GraphTest(QObject *parent = 0) : QObject(parent) {}

private slots:
	void cleanup()
	{
		delete graph;
	}

	void test1()
	{
		graph = new Graph("input1.txt");
		QVERIFY(graph->IsAllRobotsCrashable());
	}

	void test2()
	{
		graph = new Graph("input2.txt");
		QVERIFY(!graph->IsAllRobotsCrashable());
	}

private:
	Graph *graph;
};

