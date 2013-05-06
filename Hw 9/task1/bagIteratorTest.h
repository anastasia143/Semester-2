#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "tree.h"

class BagIteratorTest : public QObject
{
     Q_OBJECT
public:
    explicit BagIteratorTest(QObject *parent = 0) : QObject(parent) {}
private:
    Bag<int>* bag;

private slots:
    void init()
    {
        bag = new Bag<int>();
    }

    void testHasNext()
    {
        bag->add(20);
        bag->add(10);

        Bag<int>::Iterator iterator(bag);
        int value = iterator.next();
        QCOMPARE(iterator.hasNext(), true);
        value = iterator.next();
        QCOMPARE(iterator.hasNext(), false);
    }

    void testAdd()
    {
        bag->add(6);
        bag->add(3);
        bag->add(20);

        Bag<int>::Iterator iterator(bag);
        int value = iterator.next();
        iterator.add(4);
        QCOMPARE(iterator.next(), 4);
    }

    void testRemove()
    {
        bag->add(5);
        bag->add(5);
        bag->add(3);
        bag->add(20);

        Bag<int>::Iterator iterator(bag);
        int value = iterator.next();
        QCOMPARE(iterator.remove(), 5);
        QCOMPARE(iterator.next(), 5);
    }

    void testNext()
    {
        bag->add(20);
        bag->add(10);
        bag->add(15);
        bag->add(15);
        bag->add(18);
        bag->add(18);
        bag->add(18);
        bag->add(18);
        bag->add(3);
        bag->add(17);
        bag->add(19);
        bag->add(25);

        Bag<int>::Iterator iterator(bag);
        QCOMPARE(iterator.next(), 3);
        QCOMPARE(iterator.next(), 10);
        QCOMPARE(iterator.next(), 15);
        QCOMPARE(iterator.next(), 15);
        QCOMPARE(iterator.next(), 17);
        QCOMPARE(iterator.next(), 18);
        QCOMPARE(iterator.next(), 18);
        QCOMPARE(iterator.next(), 18);
        QCOMPARE(iterator.next(), 18);
        QCOMPARE(iterator.next(), 19);
        QCOMPARE(iterator.next(), 20);
        QCOMPARE(iterator.next(), 25);
    }

    void cleanup()
    {
        delete bag;
    }
};
