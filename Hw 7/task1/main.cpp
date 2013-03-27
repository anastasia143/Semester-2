#include <iostream>
#include "example.h"

int main()
{
    try
    {
        Thrower* thrower = new Thrower();
    }
    catch(int const &exception)
    {
        std::cout << "EXCEPTION WAS CATCHED.";
    }
    return 0;
}
