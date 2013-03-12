#include "hashTable.h"
#include <iostream>
using namespace std;


HashTable::HashTable()
{
    elementsCount = 0;
    for(int i = 0; i < arraySize; i++)
        collisionsArray[i] = -1;
    maxListLength = 0;
}

void HashTable::addValue(char* str, HashKeyFunctions* hashKeyFunction)
{
    int key = hashKeyFunction->getHashKey(str);
    if (listArray[key].checkAvailability(str))
    {
        cout << "This element has already added." << endl;
        return;
    }
    listArray[key].add(str);
    collisionsArray[key]++;
    if (listArray[key].size > maxListLength)
        maxListLength = listArray[key].size;
    elementsCount++;
}

void HashTable::removeValue(char *str, HashKeyFunctions* hashKeyFunction)
{
    int key = hashKeyFunction->getHashKey(str);
    if (listArray[key].checkAvailability(str))
        listArray[key].remove(str);
    else
    {
        cout << "There is no this element in the table." << endl;
        return;
    }
    elementsCount--;

}

void HashTable::printTable()
{
    if (elementsCount == 0)
    {
        cout << "Table is empty";
        return;
    }
    for(int i = 0; i < arraySize; i++)
    {
        listArray[i].print();
    }
}


void HashTable::showStatistics()
{
    int collisionsCount = 0;
    for(int i = 0; i < arraySize; i++)
    {
        if (collisionsArray[i] != -1)
            collisionsCount += collisionsArray[i];
    }

    cout << endl << "Number of elements: " << elementsCount
         << endl << "Number of collisions: " << collisionsCount
         << endl << "Max length of list during the existence of hash table: " << maxListLength;
    cout << endl;
}

bool HashTable::checkAvailability(char* str, HashKeyFunctions* hashKeyFunction)
{
    int key = hashKeyFunction->getHashKey(str);
    return (listArray[key].checkAvailability(str));
}

HashTable::~HashTable()
{
    for(int i = 0; i < arraySize; i++)
    {
        listArray[i].~PointerList();
    }
}
