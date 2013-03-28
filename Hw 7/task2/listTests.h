#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "uniqueList.h"
#include "list.h"

class ListTests : public QObject
{
     Q_OBJECT
public:
    explicit ListTests(QObject *parent = 0) : QObject(parent) {}

private:
    List* uniqueList;

private slots:
    void initTestCase()
    {
        uniqueList = new UniqueList();
    }

    void testAdd()
    {
        int number = 5;
        uniqueList->add(number);
        QVERIFY(uniqueList->check(number));
    }

    void testRemove()
    {
        int number = 10;
        uniqueList->add(number);
        uniqueList->remove(number);
        QVERIFY(!(uniqueList->check(number)));
    }

    void testCheck()
    {
        int number = 13;
        uniqueList->add(number);
        QCOMPARE(uniqueList->check(number), true);
        uniqueList->remove(number);
        QCOMPARE(uniqueList->check(number), false);
    }
// This test demonstrate, that exception will not allow to add equal elements
    void testUniqueAdding()
    {
        uniqueList->add(3);
        int size1 = uniqueList->getSize();
        uniqueList->add(3);
        int size2 = uniqueList->getSize();
        QVERIFY(size1 == size2);
    }
// This test demonstrate, that exception will not allow to remove nonexistent element
    void testCheckExistBeforeRemoving()
    {
        uniqueList->clear();
        uniqueList->remove(5);
        QCOMPARE(uniqueList->getSize(), 0);
        uniqueList->add(7);
        uniqueList->remove(8);
        QCOMPARE(uniqueList->getSize(), 1);
    }

    void cleanupTestCase()
    {
        delete uniqueList;
    }
};
