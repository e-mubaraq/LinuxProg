#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

/*
 * 
 * This is a program that plays around with C-stlye strings and malloc().
 *
 * Author: Cathy Bishop
 *
 */

void printMemory(char *ptr, char *label);

int main(int argc, char *argv[])
{
    char anotherOne[10];
    char string[5];
    char *ptr1;
    char *ptr2 = NULL;

    strcpy(string, "abcd");

    ptr1 = (char *)malloc(strlen(string + 1));
    ptr2 = (char *)malloc(3);
    strcpy(ptr1, string);
    fprintf(stdout, "string is %s\n", string);

    fprintf(stdout, "Addresses:\n");
    fprintf(stdout, "anotherOne: %p\n", &anotherOne);
    fprintf(stdout, "string:     %p\n", &string);
    fprintf(stdout, "ptr1:       %p\n", &ptr1);
    fprintf(stdout, "ptr2:       %p\n", &ptr2);

    fprintf(stdout, "Value of ptrs:\n");
    fprintf(stdout, "ptr1:   %p\n", ptr1);
    fprintf(stdout, "ptr2:   %p\n", ptr2);
    printMemory(ptr1, "ptr1");
    printMemory(ptr2, "ptr2");

    fprintf(stdout, "sizeof string: %ld anotherOne: %ld\n", sizeof(string), sizeof(anotherOne));
    fprintf(stdout, "sizeof ptr1: %ld ptr1: %ld\n", sizeof(ptr1), sizeof(ptr2));
    
    free(ptr1);
    ptr2 = (char *)malloc(strlen(string + 1));
    printMemory(ptr1, "ptr1");
    printMemory(ptr2, "ptr2");
    strcpy(ptr1, "this is much much too big");
    fprintf(stdout, "ptr1: %s\n", ptr1);
    fprintf(stdout, "ptr2: %s\n", ptr2);
    return(0);
}

void printMemory(char *ptr, char *label)
{
    char *p;
    int i = 0;

    fprintf(stdout, "&ptr:   %p\n", &ptr);
    fprintf(stdout, "%s\n", label);
    fprintf(stdout, " ptr:   %p\n", ptr);

    p = ptr;
    while (*p != '\0')
    {
        fprintf(stdout, "char %d: <%c> at %p\n", i, *p, p);
        i++;
        p++;
    }
}
