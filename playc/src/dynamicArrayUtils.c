#include    <stdio.h>
#include    <stdlib.h>

#include    "dynamicArrayUtils.h"

bool initArrayDynamic(int **dynamicArray, int *n, int *maxSize, char *filename)
{
    FILE *inf;
    char line[100];
    int *list;
    int blockSize = 10;

    *maxSize = blockSize;
    *dynamicArray = malloc(sizeof(int) * *maxSize);
    list = *dynamicArray;

    inf = fopen(filename, "r");

    fprintf(stdout, "--- in initArrayDynamic\n");
    fprintf(stdout, "address of list   : %p\n", &list);
    fprintf(stdout, "address in list   : %p\n", list);
    fprintf(stdout, "address of dynamicArray   : %p\n", &dynamicArray);
    fprintf(stdout, "address in dynamicArray   : %p\n", dynamicArray);
    fprintf(stdout, "contents of dynamicArray   : %p\n", *dynamicArray);

    if (inf == NULL)
    {
        fprintf(stderr, "FAILED  to open file %s\n", filename);
        return false;
    }
        
    while(fgets(line, 100, inf) != NULL)
    {
        if (*n >= blockSize)
            increaseArray(dynamicArray, maxSize, blockSize);

        (*dynamicArray)[*n] = atoi(line);
        //Note: this is the same thing - list[*n] = atoi(line);
        (*n)++;
    }
    close(inf);

    fprintf(stdout, "address of list[0]: %p\n", &(list[0]));
    fprintf(stdout, "address of dynl[0]: %p\n", &((*dynamicArray)[0]));
    fprintf(stdout, "address of list[1]: %p\n", &(list[1]));
    fprintf(stdout, "address of dynl[1]: %p\n", &((*dynamicArray)[1]));
    fprintf(stdout, "\nRead in list, contains %d\n", *n);

    printArray(*dynamicArray, *n);
    return true;
}

void increaseArray(int **list, int *currentSize, int blockSize)
{
    int *newList;
    int newSize;
    int i;

    fprintf(stdout, "\n*** Need More!!\n");
return;

    newSize = *currentSize + blockSize;

    newList = malloc(sizeof(int) * newSize);

    fprintf(stdout, "contents of dynamicArray   : %p\n", *list);
    fprintf(stdout, "address in newList         : %p\n", newList);
    for (i = 0; i < *currentSize; i++)
    {
        newList[i] = (*list)[i];
    }
    fprintf(stdout, "contents of dynamicArray   : %p\n", *list);
    printArray(newList, *currentSize);
    printArray(*list, *currentSize);
    free (*list);

    //fprintf(stdout, "memsize: %d\n", memsize());
    *list = newList;
    *currentSize += blockSize;
}
