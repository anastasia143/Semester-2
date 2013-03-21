#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "tree.h"
#include "setOperations.h"

class Test : public QObject
{
     Q_OBJECT
public:
    explicit Test(QObject *parent = 0) : QObject(parent) {}
private:
    Tree<int>* intTree;
    Tree<int>* intTree2;
    Tree<char>* charTree;
private slots:
    void initTestCase()
    {
        intTree = new Tree<int>();
        intTree2 = new Tree<int>();
        charTree = new Tree<char>();
    }

    void testMerger()
    {
        intTree->clear();
        intTree2->clear();
        intTree->add(9);
        intTree->add(1);
        intTree2->add(7);
        intTree2->add(1);
        intTree->add(2);
        intTree2->add(9);
        Tree<int>* mergerTree = merger(intTree, intTree2);
        QVERIFY(mergerTree->exist(9));
        QVERIFY(mergerTree->exist(7));
        QVERIFY(mergerTree->exist(2));
        QVERIFY(mergerTree->exist(1));
        delete mergerTree;
    }

    void testIntersection()
    {
        intTree->clear();
        intTree2->clear();
        intTree->add(5);
        intTree->add(8);
        intTree2->add(8);
        intTree2->add(4);
        intTree->add(6);
        intTree2->add(6);
        Tree<int>* interTree = intersection(intTree, intTree2);
        QVERIFY(interTree->exist(6));
        QVERIFY(interTree->exist(8));
        QVERIFY(!interTree->exist(4));
        QVERIFY(!interTree->exist(5));
        delete interTree;
    }

    void testAddInt()
    {
        intTree->add(4);
        QVERIFY(intTree->exist(4));
    }
    void testAddChar()
    {
        charTree->add('4');
        QVERIFY(charTree->exist('4'));
    }
    void testExistInt()
    {
        intTree->add(106);
        QVERIFY(intTree->exist(106));
        intTree->remove(106);
        QVERIFY(!intTree->exist(106));
    }
    void testExistChar()
    {
        charTree->add('1');
        QVERIFY(charTree->exist('1'));
        charTree->remove('1');
        QVERIFY(!charTree->exist('1'));
    }
    void testRemoveInt()
    {
        intTree->add(6);
        intTree->remove(6);
        QVERIFY(!intTree->exist(6));
    }
    void testRemoveChar()
    {
        charTree->add('6');
        charTree->remove('6');
        QVERIFY(!charTree->exist('6'));
    }

    void testUniqueness()
    {
        intTree->clear();
        intTree->add(2);
        intTree->add(2);
        intTree->add(2);
        QCOMPARE(intTree->returnCount(), 1);
    }

    void cleanupTestCase()
    {
        delete intTree;
        delete intTree2;
        delete charTree;
    }
};
