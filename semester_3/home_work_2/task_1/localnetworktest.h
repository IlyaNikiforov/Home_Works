#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "localnetwork.h"
#include "random.h"

class LocalNetworkTest : public QObject
{
	Q_OBJECT
public:
	explicit LocalNetworkTest(QObject *parent = 0) : QObject(parent) {}

private slots:

	void cleanup()
	{
		delete random;
		delete network;
	}

	void testWithTrueRandom()
	{
		random = new TrueRandom;
		network = new LocalNetwork("input1.txt", random);
		//network->printStatictics();
		network->makeMove();
		QVERIFY(network->isInfected(1) && !network->isInfected(2) && !network->isInfected(3));
		network->makeMove();
		QVERIFY(network->isInfected(2) && !network->isInfected(3));
		network->makeMove();
		QVERIFY(network->isInfected(3));
		QVERIFY(network->isFinished());
	}

	void testWithFakeRandom()
	{
		random = new TestRandom;
		network = new LocalNetwork("input2.txt", random);
		for (int i = 0; i < 3; i++)
		{
			network->makeMove();
			network->printStatictics();
			QVERIFY(!network->isInfected(1));
		}
		network->makeMove();
		network->printStatictics();
		QVERIFY(network->isInfected(1));
		network->makeMove();
		network->printStatictics();
		QVERIFY(network->isInfected(2) && !network->isInfected(3));
		network->makeMove();
		network->printStatictics();
		QVERIFY(network->isInfected(3));
		network->makeMove();
		network->printStatictics();
		QVERIFY(!network->isInfected(4));
		network->makeMove();
		network->printStatictics();
		QVERIFY(!network->isInfected(4));
		network->makeMove();
		network->printStatictics();
		QVERIFY(network->isInfected(4));
		QVERIFY(network->isFinished());
	}

private:
	Random *random;
	LocalNetwork *network;
};
