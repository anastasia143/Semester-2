#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "vector.h"

class Test : public QObject
{
     Q_OBJECT
public:
    explicit Test(QObject *parent = 0) : QObject(parent) {}
private:
    Vector* vector1;
    Vector* vector2;
    Vector* vector3;
    int* coord;
    int len;
private slots:
    void initTestCase()
    {
        len = 5;
        coord = new int[len];
        for(int i = 0; i < len; i++)
            coord[i] = i;
        vector1 = new Vector(coord, len);
        vector2 = new Vector(*vector1);
        for(int i = 0; i < len; i++)
            coord[i] = 0;
        vector3 = new Vector(coord, len);
    }

    void testAddition()
    {
        coord = vector1->addition(vector2);
        for(int i = 0; i < len; i++)
            QCOMPARE(coord[i], i * 2);
    }

    void testSubtraction()
    {
        coord = vector1->subtraction(vector2);
        for(int i = 0; i < len; i++)
            QCOMPARE(coord[i], 0);
    }

    void testScalarMultiplication()
    {
        QCOMPARE(vector1->scalarMultiplication(vector2), 30);
    }

    void testIsNull()
    {
        QCOMPARE(vector1->isNull(), false);
        QCOMPARE(vector3->isNull(), true);
    }

    void cleanupTestCase()
    {
        delete vector1;
        delete vector2;
        delete vector3;
        delete[] coord;
    }
};
