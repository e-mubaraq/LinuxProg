
#include <stdio.h>

#include "utils1.h"
#include "utils2.h"

int main(int argc, char *argv[])
{
    int x;

    printArgs(argc, argv);
    x = addNums(3, 7); 
    printf("x is %d\n", x);
}
