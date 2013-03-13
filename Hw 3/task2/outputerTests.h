#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "outputer.h"
#include "createOutputer.h"
#include <iostream>

class OutputerTests : public QObject
{
     Q_OBJECT
public:
    explicit OutputerTests(QObject *parent = 0) : QObject(parent) {}

private:
    Outputer* fileOutputer;
    Outputer* consoleOutputer;

private slots:

    void initTestCase()
    {
        consoleOutputer = createOutputer(1);
        fileOutputer = createOutputer(2);
    }

    void commonTest()
    {
        int size = 5;
        int **array = new int*[size];
        for (int i = 0; i < size; i++)
            array[i] = new int[size];

        int value = 0;
        for(int i = 0; i < size; i++)
            for(int k = 0; k < size; k++)
            {
                value++;
                array[i][k] = value;
            }

        fileOutputer->output(array, size);
        std::cout << endl;
        consoleOutputer->output(array, size);
        std::cout << endl;

        for (int i = 0; i < size; i++)
            delete[] array[i];
        delete[] array;
    }

    void cleanupTestCase()
    {
        delete consoleOutputer;
        delete fileOutputer;
    }
};
