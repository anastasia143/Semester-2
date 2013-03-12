#pragma once
#include "hashKeyFunctions.h"
#include "hashTable.h"

/** @HashKeyWithStrLen
This simple hashKey function returns length of the string.
It helps easily watch number of collisions.
  */
class HashKeyWithStrlen : public HashKeyFunctions
{
public:
    int getHashKey(char* str);
};

