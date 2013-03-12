/**
*@author Semenova Anastasia
*@version 1.0
*/

// Task is ready for check.

#include <iostream>
#include "hashTable.h"
#include "commands.h"
#include "tests.h"
using namespace std;

int main()
{
    // The code in the comments bellow is for the interactive mode

    /*HashTable* table = new HashTable();
    interactive(table);
    delete table;*/

    HashTableTests test;
    QTest::qExec(&test);
    
    return 0;
}
