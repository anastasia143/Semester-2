/**
*@author Semenova Anastasia
*@version 1.0
*/

#include <iostream>
#include "listTests.h"
using namespace std;

int main()
{
    ListTests test;
    QTest::qExec(&test);
    return 0;
}
