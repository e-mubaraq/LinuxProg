#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>


#define FISH 0x01
#define CHICKEN 0x02
#define ALUR 0x04
#define ALUM 0x08

int main(int argc, char *argv[])
{
     char ans = 0;
     char prompt;
     char strans[10];

    printf("Please answer the following questions with either y or n \n");

    fprintf(stdout, "Do you eat fish: ");
    fgets(strans, 9, stdin);
    prompt = strans[0];
    if (prompt == 'y') {
        ans = ans | FISH;
    }
    else if (prompt == 'n')
        ans = ans & ~FISH;    
      

    fprintf(stdout, "Do you eat chicken: ");
    fgets(strans, 9, stdin);
    prompt = strans[0];
    if (prompt == 'y') 
        ans = ans | CHICKEN;
    else if (prompt == 'n')
        ans = ans & ~CHICKEN;

    fprintf(stdout, "Do you study at ALU Rwanda: ");
    fgets(strans, 9, stdin);
    prompt = strans[0];
    if (prompt == 'y')
        ans = ans | ALUR;
    else if (prompt == 'n')
        ans = ans & ~ALUR;

    fprintf(stdout, "Do you study at ALU Mauritus: ");
    fgets(strans, 9, stdin);
    prompt = strans[0];
    if (prompt == 'y')
        ans = ans | ALUM;
    else if (prompt == 'n') {
        ans = ans & ~ALUM;
    }

    fprintf(stdout, "ans: 0x%0x\n", ans);
    
    if ((ans & FISH) && (ans & CHICKEN))
        fprintf(stdout, "\nYou are not a vegetarian");

    if ((ans & FISH) && !(ans & CHICKEN))
        fprintf(stdout, "\nYou are a pisceparian");

    if (!(ans & FISH) && !(ans & CHICKEN))
        fprintf(stdout, "\nYou are a vegetarian");

    if ((ans & ALUR) || (ans & ALUM))
        fprintf(stdout, "\nYou are an ALU student");
    else 
        fprintf(stdout, "\nYou are not  an ALU student");


}
