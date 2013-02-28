#include <iostream>
#include "outputer.h"
#include "fileOutputer.h"
#include "consoleOutputer.h"
#include "createOutputer.h"
using namespace std;


/**
  @author Semenova Anastasia
  @version 1.0
  */

int main()
{
    int size = 2;
    cout << "Enter size of array (ODD natural number): ";
    cin >> size;

    while(size % 2 == 0)
    {
        cout << "Please, enter ODD natural number: ";
        cin >> size;
    }

    int **array = new int*[size];
    for (int i = 0; i < size; i++)
        array[i] = new int[size];

    int initialization = 0;
    cout << "Source array: " << endl;
    for(int i = 0; i < size; i++)
    {
        for(int k = 0; k < size; k++)
        {
            initialization++;
            array[i][k] = initialization;
            cout << array[i][k] << " ";
        }
        cout << endl;
    }


    cout << endl << "Where do you want to output spiral array?"
         << endl << "1 - console"
         << endl << "2 - file" << endl;
    int command = 0;
    cin >> command;

    Outputer* outputer = createOutputer(command);
    outputer->output(array, size);
    delete outputer;

    for(int i = 0; i < size; i++)
    {
       delete[] array[i];
    }
    delete[] array;

    return 0;
}
