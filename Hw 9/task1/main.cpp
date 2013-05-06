/**
@author Semenova Anastasia
*/

#include <iostream>
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "tree.h"
#include "bagTest.h"
#include "bagIteratorTest.h"
using namespace std;

int main()
{
    BagTest bagTest;
    QTest::qExec(&bagTest);

    BagIteratorTest bagIteratorTest;
    QTest::qExec(&bagIteratorTest);

    return 0;
}
