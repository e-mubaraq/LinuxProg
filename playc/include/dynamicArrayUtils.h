#ifndef DYNAMICARRAYUTILS_H
#define DYNAMICARRAYUTILS_H

#include    <stdbool.h>

bool initArrayDynamic(int **dynamicArray, int *n, int *maxSize, char *filename);
void increaseArray(int **list, int *currentSize, int blockSize);

#endif
