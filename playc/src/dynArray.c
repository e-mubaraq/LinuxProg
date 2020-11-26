#include    <stdio.h>
#include    "arrayUtils.h"
#include    "dynamicArrayUtils.h"

/*
 * 
 * This is a program that plays around with C. It demonstrates functions, prototypes,
 * reading an input file, creating an array, #define, and passing and using
 * pointer arguments.
 *
 * Author: Cathy Bishop
 *
 */

int main(int argc, char *argv[])
{
    char *filename = "nums";
    int *nums;
    int n = 0;
    int maxSize = 0;

    fprintf(stdout, "address of nums   : %p\n\n", &nums);
    if (argc > 1)
        filename = argv[1];

    initArrayDynamic(&nums, &n, &maxSize, filename);

    fprintf(stdout, "\n------ After init ----------\n");
    fprintf(stdout, "MaxSize of array  : %d\n", maxSize);
    fprintf(stdout, "address of nums   : %p\n", &nums);
    fprintf(stdout, "address in nums   : %p\n", nums);
    fprintf(stdout, "address of nums[0]: %p\n", &(nums[0]));
    fprintf(stdout, "address of nums[1]: %p\n", &(nums[1]));

    printArrayPtrs(nums, n);
    
    return(0);
}
