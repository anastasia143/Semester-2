#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "bubbleSort.h"

// Arranging numbers in ascending
template <class C>
class IntComparative: public Comparative<C>
{
public:
    bool compare(int elementOne, int elementTwo)
    {
        return(elementOne > elementTwo);
    }
};

// Arranging chars in ascending of ASCII-code
template <class C>
class CharComparative : public Comparative<C>
{
public:
    bool compare(char elementOne, char elementTwo)
    {
        return(elementOne > elementTwo);
    }
};

class Test : public QObject
{
     Q_OBJECT
public:
    explicit Test(QObject *parent = 0) : QObject(parent) {}
private:
    int* intArray;
    char* charArray;
    int size;
    Comparative<int>* intComparative;
    Comparative<char>* charComparative;
    BubbleSort<int>* intSorter;
    BubbleSort<char>* charSorter;

private slots:
    void initTestCase()
    {
        size = 100;

        intArray = new int[size];
        for(int i = 0; i < size; i++)
            intArray[i] = rand() % 1000;

        charArray = new char[size];
        for(int i = 0; i < size; i++)
            charArray[i] = (char)(rand() % 50 + 42);

        intComparative = new IntComparative<int>;
        charComparative = new CharComparative<char>;
        intSorter = new BubbleSort<int>;
        charSorter = new BubbleSort<char>;
    }

    void testIntSorting()
    {
        intSorter->sort(intArray, size, intComparative);
        for(int i = 0; i < size - 1; i++)
            QVERIFY(intArray[i] <= intArray[i + 1]);
    }

    void testCharSorting()
    {
        charSorter->sort(charArray, size, charComparative);
        for(int i = 0; i < size - 1; i++)
            QVERIFY(charArray[i] <= charArray[i + 1]);
    }


    void cleanupTestCase()
    {
        delete[] intArray;
        delete[] charArray;
        delete intSorter;
        delete charSorter;
        delete intComparative;
        delete charComparative;
    }
};
