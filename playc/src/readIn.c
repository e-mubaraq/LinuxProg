#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <stdbool.h>

/*
 *
 * This is a program that reads input from the keyboard
 *
 * Author: Cathy Bishop
 *
 */

int main(int argc, char *argv[])
{
    char line[10];
    int numChars = 0;

    fprintf(stdout, "Please enter a string: ");
    fgets(line, 10, stdin);
    while(strncmp(line, "\n", 1) != 0)
    {
        fprintf(stdout, "Read line <%s> strlen: %zd\n", line, strlen(line));
        fprintf(stdout, "Please enter another string: ");
        fgets(line, 10, stdin);
    }
    return(0);
}

