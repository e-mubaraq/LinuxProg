
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
    int sum = 0;
    float average = 0;
    int count = 0;
    int number = 0;

    fprintf(stdout, "Please enter a number: ");
    fgets(line, 10, stdin);
    while(strncmp(line, "\n", 1) != 0)
    {
        count++;
        number = atoi(line);
        sum += number;
        fprintf(stdout, "Please enter another string: ");
        fgets(line, 10, stdin);
    }
    average = (float)sum / count;
    fprintf(stdout, "Average: %3.2f", average);
    return(0);
}

