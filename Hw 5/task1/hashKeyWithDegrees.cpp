#include "hashKeyWithDegrees.h"
#include <string.h>

int HashKeyWithDegrees::getHashKey(char *str)
{
    int len = strlen(str);
    int long long result = 0;
    int long long degree = 3;
    for (int i = 0; i < len; i++)
    {
        degree = degree*degree;
        result = result + ((int)str[i])*degree;
    }
    return (result % arraySize);
}
