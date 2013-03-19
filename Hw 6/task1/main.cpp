/**
@author Semenova Anastasia
*/

#include <iostream>
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "tree.h"
#include "test.h"
using namespace std;

int main()
{ 
    Test test;
    QTest::qExec(&test);
    return 0;
}
