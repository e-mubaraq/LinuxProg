#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>


#define q1 0x01
#define q2 0x02
#define q3 0x04
#define q4 0x08

int main(int argc, char *argv[])
{
    char ans;

    printf("Please answer the following questions with either y or n \n");

    fprintf(stdout, "Do you eat beef: ");
    // ans = getchar();
    scanf("%c", &ans);
    if (ans == 'y') {
        ans = ans | q1;
        printf("ans: %c\n", ans);
    }
    else if (ans == 'n')
        ans = ans & ~q1;
    // printf("\n Entered character is: ");
    // putchar(ans);
    // printf("\n");
    
      

    fprintf(stdout, "Do you eat chicken: ");
    // ans = getchar();
    scanf("%c", &ans);
    if (ans == 'y') 
        ans = ans | q2;
    else if (ans == 'n')
        ans = ans & ~q2;

    fprintf(stdout, "Do you study at ALU Rwanda: ");
    // ans = getchar();
    scanf("%c", &ans);
    if (ans == 'y')
        ans = ans | q3;
    else if (ans == 'n')
        ans = ans & ~q3;

    fprintf(stdout, "Do you study at ALU Mauritus: ");
    // ans = getchar();
    scanf("%c", &ans);
    if (ans == 'y')
        ans = ans | q4;
    else if (ans == 'n') {
        ans = ans & ~q4;
        printf("ans: %c\n", ans);
    }


    if ((ans & (q1 | q2)) == 0)
        fprintf(stdout, "\nYou are not a vegetarian");
    else if ((ans & (q1 & q2)) == 1)
        fprintf(stdout, "\nYou are a vegetarian");
    
    if ((ans & (q3 | q4)) == 0)
        fprintf(stdout, "\nYou are not an ALU student");
    else if ((ans & (q3 | q4)) == 1)
        fprintf(stdout, "\nYou are an ALU student");


}