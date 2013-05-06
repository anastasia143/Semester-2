#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "tree.h"

class BagTest : public QObject
{
     Q_OBJECT
public:
    explicit BagTest(QObject *parent = 0) : QObject(parent) {}
private:
    Bag<int>* intBag;
    Bag<char>* charBag;
private slots:
    void initTestCase()
    {
        intBag = new Bag<int>();
        charBag = new Bag<char>();
    }

    void testAddInt()
    {
        intBag->clear();
        intBag->add(4);
        QVERIFY(intBag->exist(4));
    }

    void testAddChar()
    {
        charBag->clear();
        charBag->add('4');
        QVERIFY(charBag->exist('4'));
    }

    void testExistInt()
    {
        intBag->clear();
        intBag->add(106);
        QVERIFY(intBag->exist(106));
        intBag->remove(106);
        QVERIFY(!intBag->exist(106));
    }

    void testExistChar()
    {
        charBag->clear();
        charBag->add('1');
        QVERIFY(charBag->exist('1'));
        charBag->remove('1');
        QVERIFY(!charBag->exist('1'));
    }
    void testRemoveInt()
    {
        intBag->clear();
        intBag->add(6);
        intBag->remove(6);
        QVERIFY(!intBag->exist(6));
    }

    void testRemoveChar()
    {
        charBag->clear();
        charBag->add('6');
        charBag->remove('6');
        QVERIFY(!charBag->exist('6'));
    }

    void testMultiplicity()
    {
        intBag->clear();
        intBag->add(2);
        intBag->add(2);
        QCOMPARE(intBag->returnCount(), 2);
        QCOMPARE(intBag->getElementCount(2), 2);
        intBag->remove(2);
        QCOMPARE(intBag->returnCount(), 1);
        QCOMPARE(intBag->getElementCount(2), 1);
        intBag->remove(2);
        intBag->add(1);
        QCOMPARE(intBag->returnCount(), 1);
        QCOMPARE(intBag->getElementCount(2), 0);
    }

    void cleanupTestCase()
    {
        delete intBag;
        delete charBag;
    }
};
