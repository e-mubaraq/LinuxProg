#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

struct {
unsigned int q1 : 1;
unsigned int q2 : 1;
unsigned int q3 : 1;
unsigned int q4 : 1;
} opts;

int main(int argc, char *argv[]) {
     char ans;

    printf("Please answer the following questions with either y or n \n");

    fprintf(stdout, "Do you eat beef: ");
    ans = getchar();
    if (ans == 'y')
        opts.q1 = 1;
    else if (ans == 'n')
        opts.q1 = 0;
    // printf("\n Entered character is: ");
    // putchar(ans);
    // printf("\n");
    
      

    fprintf(stdout, "Do you eat chicken: ");
    ans = getchar();
    if (ans == 'y')
        opts.q2 = 1;
    else if (ans == 'n')
        opts.q2 = 0;

    fprintf(stdout, "Do you study at ALU Rwanda: ");
    ans = getchar();
    if (ans == 'y')
        opts.q3 = 1;
    else if (ans == 'n')
        opts.q3 = 0;

    fprintf(stdout, "Do you study at ALU Mauritus: ");
    ans = getchar();
    if (ans == 'y')
        opts.q4 = 1;
    else if (ans == 'n')
        opts.q4 = 0;


    if (opts.q1 == 0 && opts.q2 == 0)
        fprintf(stdout, "\nYou are not a vegetarian");
    else if (opts.q1 == 1 && opts.q2 == 1)
        fprintf(stdout, "\nYou are a vegetarian");
    
    if (opts.q3 == 0 && opts.q4 == 0)
        fprintf(stdout, "\nYou are not an ALU student");
    else if (opts.q3 == 1 || opts.q4 == 1)
        fprintf(stdout, "\nYou are an ALU student");

}