#include <iostream>
#include "createOutputer.h"
#include "fileOutputer.h"
#include "consoleOutputer.h"
using namespace std;

Outputer* createOutputer(int command)
{
    switch(command)
    {
    case 1:
    {
        return new ConsoleOutputer();
        cout << endl << "Spiral: ";
        break;
    }
    case 2:
    {
        cout << endl << "Spiral was printed in file.";
        return new FileOutputer();
        break;
    }
    }
}
