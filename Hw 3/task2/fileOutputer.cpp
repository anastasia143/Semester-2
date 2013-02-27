#include "stdio.h"
#include "outputer.h"
#include "fileOutputer.h"

void FileOutputer::output(int** array, int size)
{
    FILE* file = fopen("file.txt", "w");

    int count = 0;
    int coutNumbers = 0;

    int i = size / 2;
    int j = size / 2;

    fprintf(file, "%d", array[i][j]);
    fprintf(file, " ");
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
            {
                fprintf(file, "%d", array[--i][j]);
                fprintf(file, " ");
            }
            break;
        }
        case 1:
        {
            for (int k = 1; k <= coutNumbers; k++)
            {
                fprintf(file, "%d", array[i][++j]);
                fprintf(file, " ");
            }
            break;
        }
        case 2:
        {
            for (int k = 1; k <= coutNumbers; k++)
            {
                fprintf(file, "%d", array[++i][j]);
                fprintf(file, " ");
            }
            break;
        }
        case 3:
        {
            for (int k = 1; k <= coutNumbers; k++)
            {
                fprintf(file, "%d", array[i][--j]);
                fprintf(file, " ");
            }
            break;
        }
        }
    }
    fclose(file);
}
