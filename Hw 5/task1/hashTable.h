#pragma once
#include "pointerList.h"
#include "hashKeyFunctions.h"

// Small size of array will be chosen because of wishing to watch the statistics.
const int arraySize = 10;

class HashTable
{
public:
    HashTable();
    ~HashTable();
    void addValue(char* str, HashKeyFunctions* hashKeyFunction);
    void removeValue(char* str, HashKeyFunctions* hashKeyFunction);
    void showStatistics();
    void printTable();
    bool checkAvailability(char* str, HashKeyFunctions* hashKeyFunction);

private:
    PointerList listArray[arraySize];
    /** @collisionsArray[]
      @maxListLength
      @elementsCount
      Variables for statistic.
      */
    int collisionsArray[arraySize];
    int maxListLength;
    int elementsCount;

};
