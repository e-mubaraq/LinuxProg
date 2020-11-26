#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <stdbool.h>

/*
 * 
 * This is a program that plays around with C strings and parsing them.
 * It reads from an input file and parses the data.
 * pointer arguments.
 *
 * Author: Cathy Bishop
 *
 */

int main(int argc, char *argv[])
{
    FILE *inf;
    char *filename = "test1";
    char line[100];
    bool plusOperation;

    double p = 0.0, x = 0.0, y = 0.0;
    char *ptr;

    if (argc > 1)
        filename = argv[1];

    inf = fopen(filename, "r");

    if (inf == NULL)
    {
        fprintf(stdout, "FAILED  to open file %s\n", filename);
        return(1);
    }
        
    while(fgets(line, 100, inf) != NULL)
    {
        fprintf(stdout, "Read line %s\n", line);
        ptr = strtok(line, " ");
        ptr = strtok(NULL, " ");
        p = atof(ptr);
        if (p == 0.0)
        {
            if (*ptr = '-')
                p = -1.0;
            else
                p = 1.0;
        }

        ptr = strtok(NULL, " ");
        ptr = strtok(NULL, " ");
        x = atof(ptr);
        if (x == 0.0)
        {
            if (*ptr = '-')
                x = -1.0;
            else
                x = 1.0;
        }

        ptr = strtok(NULL, " ");
        if (*ptr == '-')
            plusOperation = false;
        else
            plusOperation = true;
        ptr = strtok(NULL, " ");
        y = atof(ptr);
        if (y == 0.0)
        {
            if (*ptr = '-')
                y = -1.0;
            else
                y = 1.0;
        }

        fprintf(stdout, "p is: %f\n", p);
        fprintf(stdout, "x is: %f\n", x);
        if (plusOperation)
            fprintf(stdout, "operation is plus\n");
        else
            fprintf(stdout, "operation is minus\n");
        fprintf(stdout, "y is: %f\n", y);
    }

    close(inf);

    return(0);
}

