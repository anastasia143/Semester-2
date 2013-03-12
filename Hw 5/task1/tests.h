#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "hashTable.h"

class HashTableTests : public QObject
{
     Q_OBJECT
public:
    explicit HashTableTests(QObject *parent = 0) : QObject(parent) {}
private:
    HashTable table;
    HashKeyFunctions* hashKeyLen;
    HashKeyFunctions* hashKeyDeg;
    // 	Further:
    // notes "len" or "deg" will be mean hashKey function that we are testing
private slots:
    void initTestCase()
    {
        HashTable table;
        hashKeyLen = hashKeyFunctionsCreator(1);
        hashKeyDeg = hashKeyFunctionsCreator(2);
    }

    void testCheckLen()
    {
        char* str = "long";
        table.addValue(str, hashKeyLen);
        QCOMPARE(table.checkAvailability(str, hashKeyLen), true);
        table.removeValue(str, hashKeyLen);
        QCOMPARE(table.checkAvailability(str, hashKeyLen), false);
    }

    void testCheckDeg()
    {
        char* str = "long";
        table.addValue(str, hashKeyDeg);
        QCOMPARE(table.checkAvailability(str, hashKeyDeg), true);
        table.removeValue(str, hashKeyDeg);
        QCOMPARE(table.checkAvailability(str, hashKeyDeg), false);
    }

    void testAddLen()
    {
        char* str = "hello";
        table.addValue(str, hashKeyLen);
        QVERIFY(table.checkAvailability(str, hashKeyLen));
        str = "geome";
        table.addValue(str, hashKeyLen);
        QVERIFY(table.checkAvailability(str, hashKeyLen));
    }

    void testAddDeg()
    {
        char* str = "hello";
        table.addValue(str, hashKeyDeg);
        QVERIFY(table.checkAvailability(str, hashKeyDeg));
        str = "ertsu";
        table.addValue(str, hashKeyDeg);
        QVERIFY(table.checkAvailability(str, hashKeyDeg));
    }

    void testRemoveLen()
    {
        char* str = "hey";
        table.addValue(str, hashKeyLen);
        table.removeValue(str, hashKeyLen);
        QVERIFY(!(table.checkAvailability(str, hashKeyLen)));
    }

    void testRemoveDeg()
    {
        char* str = "hey";
        table.addValue(str, hashKeyDeg);
        table.removeValue(str, hashKeyDeg);
        QVERIFY(!(table.checkAvailability(str, hashKeyDeg)));
    }

    void cleanupTestCase()
    {
        table.~HashTable();
    }
};
