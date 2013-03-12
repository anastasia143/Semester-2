#include "hashKeyFunctions.h"
#include "hashKeyWithDegrees.h"
#include "hashKeyWithStrlen.h"

HashKeyFunctions* hashKeyFunctionsCreator(int number)
{
    switch(number)
    {
    case 2:
    {
        HashKeyFunctions* key = new HashKeyWithDegrees();
        return key;
        break;
    }
    default:
    {
        HashKeyFunctions* key = new HashKeyWithStrlen();
        return key;
        break;
    }
    }
}
