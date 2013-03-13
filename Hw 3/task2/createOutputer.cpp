#include <iostream>
#include "createOutputer.h"
#include "fileOutputer.h"
#include "consoleOutputer.h"
using namespace std;

Outputer* createOutputer(int command)
{

    // Operators in comments don`t need in tests
    switch(command)
    {
    case 1:
    {
        //cout << endl << "Spiral: ";
        return new ConsoleOutputer();
        break;
    }
    case 2:
    {
        //cout << endl << "Spiral was printed in file.";
        return new FileOutputer();
        break;
    }
    }
}
