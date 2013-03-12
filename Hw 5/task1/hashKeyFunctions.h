#pragma once

class HashKeyFunctions
{
public:
    virtual int getHashKey(char* str) = 0;
};

/**
  @hashKeyFunctionsCreator
  This function chooses realisation of virtual @getHashKey by wishing the user
  */

HashKeyFunctions* hashKeyFunctionsCreator(int number);
