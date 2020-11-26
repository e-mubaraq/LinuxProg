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
    char string[100];
    char *res;
    char *ptr;

    fprintf(stdout, "Please enter a string: ");
    fgets(string, 100, stdin);
    while(strncmp(string, "\n", 1) != 0) 
    {
        reverseString1(string);
        fprintf(stdout, "reverseString1 is %s\n", string);

        reverseString1_a(string);
        fprintf(stdout, "reverseString1_a is %s\n", string);

        fprintf(stdout, "String is %s\n", string);
        res = reverse1(string);
        fprintf(stdout, "reverse1 is %s\n", res);

        fprintf(stdout, "String is %s\n", string);
        res = reverse2(string);
        fprintf(stdout, "reverse2 is %s\n", res);
        fprintf(stdout, "String is %s\n", string);


        fprintf(stdout, "Please enter another string: ");
        fgets(string, 100, stdin);
    }

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

char *reverse1(char *str)
{
    char *result;
    int i,j;
    int len;
    char c;

    len = strlen(str);
    result = (char*)malloc(len*sizeof(char));
    j = 0;
    for (i = len-1; i >= 0; i--) 
    {
        result[j] = str[i];
        j++;
    }

    return result;
}

void reverseString1_a(char *str)
{
    int i,j;
    int len;
    char c;

    len = strlen(str);
    for (i = 0; i < len/2; i++)
    {
        j = len - i - 1;
        swapChar(&str[i], &str[j]);
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

char* reverse2(char *str)
{
    char *result;
    int len;
    char *ptr1, *ptr2;

    len = strlen(str);
    result = (char*)malloc(len*sizeof(char));

    strcpy(result, str);
    ptr1 = result;
    ptr2 = &(result[len - 1]);
    
    while (ptr1 < ptr2)
    {
        swapChar(ptr1, ptr2);
        ptr1++;
        ptr2--;
    }

    return result;
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
