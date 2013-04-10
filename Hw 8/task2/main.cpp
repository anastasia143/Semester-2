/**
@author Semenova Anastasia
*/

#include <iostream>
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "test.h"
#include "vector.h"
using namespace std;

int main()
{
    Test test;
    QTest::qExec(&test);
    return 0;
}
