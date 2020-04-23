#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

/*
 * 
 * This is a program that plays around with C-stlye strings.
 *
 * Author: Cathy Bishop
 *
 */

#include "../include/playString.h"

int main(int argc, char *argv[])
{
    char anotherOne[10];
    char string[100];
    char *ptr;

     while( strcmp(string , "exit")) 
     {

     }

    strcpy(string, "abcd");
    fprintf(stdout, "string is  %s\n", string);
    reverseString1(string);
    fprintf(stdout, "reverse is %s\n", string);

    strcpy(string, "012345678");
    fprintf(stdout, "string is %s\n", string);
    reverseString1(string);
    fprintf(stdout, "reverse is %s\n", string);

    fprintf(stdout, "string is %s\n", string);
    reverseString2(string);
    fprintf(stdout, "reverse is %s\n", string);

    strcpy(string, "abcd");
    fprintf(stdout, "string is %s\n", string);
    reverseString2(string);
    fprintf(stdout, "reverse is %s\n", string);

    ptr = "This is a test";
    strcpy(string, ptr);

    fprintf(stdout, "string is %s\n", string);
    toUpper(string);
    fprintf(stdout, "string is %s\n", string);
    toLower(string);
    fprintf(stdout, "string is %s\n", string);

    // strings are hard! look at using strncpy()

    strcpy(anotherOne, "abcd");
    fprintf(stdout, "anotherOne is %s\n", anotherOne);

    strcpy(string, "Puff, the magic dragon, lived by the sea, and frolicked in the autumn mist in a land called Honalee!");
    fprintf(stdout, "len is %ld string is %s\n", strlen(string), string);
    fprintf(stdout, "sizeof string: %ld anotherOne: %ld\n", sizeof(string), sizeof(anotherOne));
    //fprintf(stdout, "string: %p anotherOne: %p\n", string, anotherOne);
    //fprintf(stdout, "string: %s string: %p\n", (string + 98), string + 98);
    
    fprintf(stdout, "anotherOne is %s\n", anotherOne);
    reverseString2(string);
    fprintf(stdout, "string is %s\n", string);

    //strcpy(anotherOne, "abcd");
    //fprintf(stdout, "string is %s\n", string);

    //strcpy(ptr, "abcd");
    return(0);
}

// reverse string using indices, no copies allowed

void reverseString1(char *str)
{
    int i,j;
    int len;
    char c;

    len = strlen(str);
    for (i = 0; i < len/2; i++)
    {
        j = len - i - 1;
        //fprintf(stdout, "switch %d and %d\n", i, j);

        // how can you change it to use the swapChar() function?

        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}

// reverse string using pointers, no copies allowed

void reverseString2(char *str)
{
    int len;
    char *ptr1, *ptr2;

    len = strlen(str);

    ptr1 = str;
    ptr2 = &(str[len - 1]);
    
    while (ptr1 < ptr2)
    {
        //fprintf(stdout, "switch %p and %p\n", ptr1, ptr2);
        swapChar(ptr1, ptr2);
        ptr1++;
        ptr2--;
    }
}

void swapChar(char *c1, char *c2)
{
    char c;
    c = *c1;
    *c1 = *c2;
    *c2 = c;
}


void toUpper(char *str)
{
    int i;
    int len;

    len = strlen(str);
    for (i = 0; i < len; i++)
        str[i] = toupper(str[i]);
}

void toLower(char *str)
{
    char *ptr;

    ptr = str;
    while (*ptr != '\0')
    {
        *ptr = tolower(*ptr);
        ptr++;
    }
}
