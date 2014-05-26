#include <QCoreApplication>
#include "vector.h"
#include "testVector.h"

int main()
{
	VectorTest vector;
    QTest::qExec(&vector);
    return 0;
}
