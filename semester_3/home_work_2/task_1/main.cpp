#include "localnetwork.h"
#include "localnetworktest.h"

int main()
{
//	LocalNetwork *network = new LocalNetwork("input.txt");
//	network->printStatictics();
//	while (!network->isFinished())
//	{
//		network->makeMove();
//		network->printStatictics();
//	}

	LocalNetworkTest networkTest;
	QTest::qExec(&networkTest);

	return (0);
}
