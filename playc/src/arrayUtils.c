#include    <stdio.h>
#include <stdlib.h>

#include    "arrayUtils.h"

/*
 * Function printArray.
 *
 * Prints an array of ints.
 *
 */

void printArray(int list[], int n)
{
    int i;

    fprintf(stdout, "\n***** Printing Array with indices\n");
    fprintf(stdout, "***** list %p\n", list);
    for (i = 0; i < n; i++)
    {
        fprintf(stdout, "list[%d]: %d\n", i, list[i]);
    }
}
void printArrayPtrs(int list[], int n)
{
    int i;
    int *ptr = list;

    fprintf(stdout, "\n***** Printing Array with pointers\n");
    for (i = 0; i < n; i++)
    {
        fprintf(stdout, "list[%d]: %d\n", i, *ptr);
        ptr++;
    }
}

int initArray1(int list[], char *filename)
{
    FILE *inf;
    char line[100];
    int i = 0;

    inf = fopen(filename, "r");

    if (inf == NULL)
        fprintf(stderr, "FAILED  to open file %s\n", filename);
        
    while(fgets(line, 100, inf) != NULL)
    {
        list[i] = atoi(line);
        i++;
    }
    fclose(inf);

    fprintf(stdout, "\naddress of list   : %p\n", list);
    fprintf(stdout, "address of list[0]: %p\n", &(list[0]));
    fprintf(stdout, "address of list[1]: %p\n", &(list[1]));
    fprintf(stdout, "\nsizeof list: %ld sizeof list[0]: %ld numElements: %d\n",
                    sizeof(list), sizeof(list[0]), i);
    fprintf(stdout, "\nRead in list, contains %d\n", i);

    return i;
}

bool initArray2(int list[], int *n, char *filename)
{
    FILE *inf;
    char line[100];

    inf = fopen(filename, "r");

    if (inf == NULL)
    {
        fprintf(stderr, "FAILED  to open file %s\n", filename);
        return false;
    }
        
    while(fgets(line, 100, inf) != NULL)
    {
        list[*n] = atoi(line);
        (*n)++;
    }
    fclose(inf);

    fprintf(stdout, "\naddress of list   : %p\n", list);
    fprintf(stdout, "address of list[0]: %p\n", &(list[0]));
    fprintf(stdout, "address of list[1]: %p\n", &(list[1]));
    fprintf(stdout, "\nsizeof list: %ld sizeof list[0]: %ld numElements: %d\n",
                    sizeof(list), sizeof(list[0]), *n);
    fprintf(stdout, "\nRead in list, contains %d\n", *n);

    printArray(list, *n);
    return true;
}
