#include <iostream>
#include "outputer.h"
#include "consoleOutputer.h"
using namespace std;

void ConsoleOutputer::output(int **array, int size)
{
    int count = 0;
    int coutNumbers = 0;

    int i = size / 2;
    int j = size / 2;

    cout << array[i][j] << " ";
    while (count < size * 2 - 1)
    {
        if (coutNumbers != size - 1)
        {
            if (count % 2 == 0)
                coutNumbers++;
        }
        count++;
        int direction = count % 4;
        switch(direction)
        {
        case 0:
        {
            for (int k = 1; k <= coutNumbers; k++)
                cout << array[--i][j] << " ";
            break;
        }
        case 1:
        {
            for (int k = 1; k <= coutNumbers; k++)
                cout << array[i][++j] << " ";
            break;
        }
        case 2:
        {
            for (int k = 1; k <= coutNumbers; k++)
                cout << array[++i][j] << " ";
            break;
        }
        case 3:
        {
            for (int k = 1; k <= coutNumbers; k++)
                cout << array[i][--j] << " ";
            break;
        }
        }

    }
}
