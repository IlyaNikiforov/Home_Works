#pragma once

#include <QObject>
#include <QTest>
#include "hashTable.h"
#include "hashFunctions.h"

class HashTableTest : public QObject
{
    Q_OBJECT
public:
    explicit HashTableTest(QObject *parent = 0) : QObject(parent) {}
    
private slots:
    void test_data()
    {
        QTest::addColumn<int>("hashFunctionNumber");

        QTest::newRow("Hash function 1") << 1;
        QTest::newRow("Hash function 2") << 2;
    }

    void test()
    {
        QFETCH(int, hashFunctionNumber);
        HashTable::HashFunction *hash[] = { &hash1, &hash2 };
        HashTable table(hash[hashFunctionNumber - 1]);
        QVERIFY(!table.isInTable("hello"));
        table.add("hello");
        QVERIFY(table.isInTable("hello") && !table.isInTable("world"));
        table.add("world");
        QVERIFY(table.isInTable("hello") && table.isInTable("world"));
        table.remove("hello");
        QVERIFY(!table.isInTable("hello") && table.isInTable("world"));
        table.remove("world");
        QVERIFY(!table.isInTable("hello") && !table.isInTable("world"));
    }
};
