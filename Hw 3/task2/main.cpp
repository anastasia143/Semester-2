#include <iostream>
#include "outputer.h"
#include "fileOutputer.h"
#include "consoleOutputer.h"
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

    switch(command)
    {
    case 1:
    {
        cout << endl << "Spiral: ";
        Outputer* outputer = new ConsoleOutputer();
        outputer->output(array, size);
        delete outputer;
        break;
    }
    case 2:
    {
        Outputer* outputer = new FileOutputer();
        outputer->output(array, size);
        delete outputer;
        cout << endl << "Spiral was printed in file.";
        break;
    }
    }

    for(int i = 0; i < size; i++)
    {
       delete[] array[i];
    }
    delete[] array;

    return 0;
}
