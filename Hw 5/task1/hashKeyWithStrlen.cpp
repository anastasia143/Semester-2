#include <iostream>
#include <string.h>
#include "hashKeyFunctions.h"
#include "hashKeyWithStrlen.h"

using namespace std;

int HashKeyWithStrlen::getHashKey(char *str)
{
    return (strlen(str) % arraySize);
}
