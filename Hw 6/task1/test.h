#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <iostream>
#include "tree.h"

class Test : public QObject
{
     Q_OBJECT
public:
    explicit Test(QObject *parent = 0) : QObject(parent) {}
private:
    Tree* tree;
    FILE* file;
    FILE* file2;
private slots:
    void initTestCase()
    {
        tree = new Tree();
        file = fopen("file.txt", "r");
        file2 = fopen("file2.txt", "r");
    }

    void testCalculateOne()
    {
        tree->clear();
        tree->collectingTree(file);
        QCOMPARE(tree->calculate(), 4);
    }

    void testCalculateTwo()
    {
        tree->clear();
        tree->collectingTree(file2);
        QCOMPARE(tree->calculate(), 6);
    }

    void cleanupTestCase()
    {
        delete tree;
        fclose(file);
        fclose(file2);
    }
};

