// C program to illustrate 
// gets() 
#include <stdio.h> 
#define MAX 15 
  
int main() 
{ 
    char buf[MAX], buf2[MAX], buf3[10], buf4[5]; 
    int b1, b2, b3, b4;
    printf("Enter a string: "); 
    b1 = getchar();
    //fgets(buf, 4, stdin); //gets(buf); 
    printf("string is: %c\n", b1); 

    printf("Enter a string: "); 
    b2 = getchar();
    //fgets(buf2, 4, stdin); //gets(buf); 
    printf("string is: %c\n", b2); 

        printf("Enter a string: "); 
    fgets(buf3, 4, stdin); //gets(buf); 
    //printf("string is: %s\n", buf3); 

        printf("Enter a string: "); 
    fgets(buf4, 4, stdin); //gets(buf); 
    printf("string is: %s\n", buf4); 
  
    return 0; 
} 