#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

#define y 01
#define n 02


int main(int argc, char *argv[])
{

    char r1[5], r2[5], r3[5], r4[5];

    printf("Please answer the following questions with either y or n \n");
    fprintf(stdout, "Do you eat beef: ");
    fgets(r1, 2, stdin);
    if (strlen(r1) != 1) {
        fprintf(stdout, "You didn't enter y or n");
        exit (0);
    }   

    fprintf(stdout, "Do you eat chicken: ");
    fgets(r2, 2, stdin);

    fprintf(stdout, "Do you study at ALU Rwanda: ");
    fgets(r3, 2, stdin);

    fprintf(stdout, "Do you study at ALU Mauritus: ");
    fgets(r4, 2, stdin);


    printf("%s\n" , r4);


}