
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <stdbool.h>

/*
 *
 * This is a program to play with errors.
 *
 * Author: Cathy Bishop
 *
 */

double calculate(double n1, double n2);

int main(int argc, char *argv[])
{
    char line[10];

    //fprintf(stdout, "Please enter a string: ");
    printf("Please enter a string: ");
    gets(line);
    //fgets(line, 10, stdin);
    fprintf(stdout, "Read line <%s> strlen: %zd\n", line, strlen(line));
    fprintf(stdout, "calling calculate: %f\n", calculate(88.5, 92.37));

    return(0);
}

double calculate(double n1, double n2)
{
    return (n1 + n2) /2.0;
}
