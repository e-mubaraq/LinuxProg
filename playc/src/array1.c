#include    <stdio.h>
#include    "arrayUtils.h"
/*
 * 
 * This is a great program that plays around with C. It demonstrates functions, prototypes,
 * reading an input file, creating an array, #define, and passing and using
 * pointer arguments.
 *
 * Author: Cathy Bishop
 *
 */

#define MAX 100

int main(int argc, char *argv[])
{
    char *filename = "nums";
    int nums[MAX];
    int n = 0;

    fprintf(stdout, "address of nums   : %p\n", nums);
    fprintf(stdout, "address of nums[0]: %p\n", &(nums[0]));
    fprintf(stdout, "address of nums[1]: %p\n", &(nums[1]));
    if (argc > 1)
        filename = argv[1];

    n = initArray1(nums, filename);
    printArray(nums, n);
    printArrayPtrs(nums, n);
    
    return(0);
}
