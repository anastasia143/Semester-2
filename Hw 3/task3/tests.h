#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "hashTable.h"
#include "sort.h"
#include "arrayFunctions.h"

class Tests : public QObject
{
     Q_OBJECT
public:
    explicit Tests(QObject *parent = 0) : QObject(parent) {}

private:
    int** array;
    int n;
    int m;

private slots:
    void initTestCase()
    {
        int n = 2;
        int m = 3;
        array = new int*[n];
        for(int i = 0; i < n; i++)
           array[i] = new int[m];
    }

    void testSort()
    {
        fill(array, n, m);
        sort(array, n, m);

        for(int i = 0; i < m - 1; i++)
            QVERIFY(comparison(array, i + 1, i, n));
    }

    void cleanupTestCase()
    {
        for (int i = 0; i < n; i++)
            delete[] array[i];
        delete[] array;
    }
};
