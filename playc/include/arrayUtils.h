#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H

#include    <stdbool.h>

void printArray(int list[], int n);
void printArrayPtrs(int list[], int n);

int initArray1(int list[], char *file);
bool initArray2(int *list, int *n, char *file);

#endif
