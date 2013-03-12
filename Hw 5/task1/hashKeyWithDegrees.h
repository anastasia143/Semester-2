#pragma once
#include "hashKeyFunctions.h"
#include "hashTable.h"

/** @HashKeyWithDegrees
This hashKey function makes polynomial from char codes.
It helps avoid many collisions.
  */
class HashKeyWithDegrees : public HashKeyFunctions
{
public:
    int getHashKey(char* str);
};
