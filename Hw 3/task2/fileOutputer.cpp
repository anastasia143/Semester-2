#include <stdio.h>
#include "outputer.h"
#include "fileOutputer.h"

void FileOutputer::print(int number)
{
    FILE* file = fopen("file.txt", "a");
    fprintf(file, "%d", number);
    fprintf(file, " ");
    fclose(file);
}
