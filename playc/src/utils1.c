
#include <stdio.h>
#include "utils1.h"

void printArgs(int argc, char *argv[])
{
    int i;

    for (i = 0; i < argc; i++)
    {
        printf("arg: %d is %s\n", i, argv[i]);
    }
}

