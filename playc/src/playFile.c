#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <stdbool.h>

/*
 * 
 * This is a program that plays around with input files.
 *
 * Author: Cathy Bishop
 *
 */

int main(int argc, char *argv[])
{
    FILE *inf;
    char *filename = "test1";
    char line[10];
    int numChars = 0;

    if (argc > 1)
        filename = argv[1];

    inf = fopen(filename, "r");

    if (inf == NULL)
    {
        fprintf(stdout, "FAILED  to open file %s\n", filename);
        return(1);
    }
        
    // Note: change inf to stdin to read for the keyboard. Type CTRL-D (EOF) to end the input

    while(fgets(line, 10, inf) != NULL)
    {
        fprintf(stdout, "Read line <%s> strlen: %zd\n", line, strlen(line));
        numChars += strlen(line);
    }

    close(inf);

    fprintf(stdout, "Read line %d characters\n", numChars);
    return(0);
}

