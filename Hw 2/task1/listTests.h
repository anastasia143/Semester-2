#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "hashTable.h"
#include "list.h"

class ListTests : public QObject
{
     Q_OBJECT
public:
    explicit ListTests(QObject *parent = 0) : QObject(parent) {}

private:
    List* arrayList;
    List* pointerList;

private slots:
    void initTestCase()
    {
        arrayList = listCreator(1);
        pointerList = listCreator(2);
    }

    void testAddArr()
    {
        int number = 5;
        arrayList->add(number);
        QVERIFY(arrayList->check(number));
    }

    void testAddPoint()
    {
        int number = 5;
        pointerList->add(number);
        QVERIFY(pointerList->check(number));
    }

    void testRemoveArr()
    {
        int number = 10;
        pointerList->add(number);
        pointerList->remove(number);
        QVERIFY(!(pointerList->check(number)));

    }

    void testRemovePoint()
    {
        int number = 10;
        arrayList->add(number);
        arrayList->remove(number);
        QVERIFY(!(arrayList->check(number)));
    }

    void testCheckArr()
    {
        int number = 13;
        arrayList->add(number);
        QCOMPARE(arrayList->check(number), true);
        arrayList->remove(number);
        QCOMPARE(arrayList->check(number), false);
    }

    void testCheckPoint()
    {
        int number = 13;
        pointerList->add(number);
        QCOMPARE(pointerList->check(number), true);
        pointerList->remove(number);
        QCOMPARE(pointerList->check(number), false);
    }

    void cleanupTestCase()
    {
        delete arrayList;
        delete pointerList;
    }
};
