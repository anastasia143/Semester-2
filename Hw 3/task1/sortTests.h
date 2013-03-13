#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "hashTable.h"
#include "createSort.h"
#include "arrayFunctions.h"

class SortTests : public QObject
{
     Q_OBJECT
public:
    explicit SortTests(QObject *parent = 0) : QObject(parent) {}

private:
    Sort* bubbleSort;
    Sort* quickSort;
    Sort* insertSort;
    int* array;
    int arrSize;
private slots:
    void initTestCase()
    {
        bubbleSort = createSort(1);
        quickSort = createSort(2);
        insertSort = createSort(3);
        arrSize = 10;
        array = new int[arrSize];
    }

    void testQuickSort()
    {
        fill(array, arrSize);
        quickSort->sortAscending(array, arrSize);
        for(int i = 0; i < arrSize - 1; i++)
            QVERIFY(array[i] <= array[i + 1]);
    }

    void testBubbleSort()
    {
        fill(array, arrSize);
        bubbleSort->sortAscending(array, arrSize);
        for(int i = 0; i < arrSize - 1; i++)
            QVERIFY(array[i] <= array[i + 1]);
    }

    void testInsertSort()
    {
        fill(array, arrSize);
        insertSort->sortAscending(array, arrSize);
        for(int i = 0; i < arrSize - 1; i++)
            QVERIFY(array[i] <= array[i + 1]);
    }

    // @sortDescending is used with sorted array (this function is common for all sorts)
    void testSortDescending()
    {
        fill(array, arrSize);
        insertSort->sortAscending(array, arrSize);
        quickSort->sortDescending(array, arrSize);
        for(int i = 0; i < arrSize - 1; i++)
            QVERIFY(array[i] >= array[i + 1]);
    }

    void cleanupTestCase()
    {
        delete bubbleSort;
        delete quickSort;
        delete insertSort;
        delete[] array;
    }
};
