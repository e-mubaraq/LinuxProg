#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "myfuncts.h"

int main(int argc, char *argv[])
{
    int i;
    long r1, r2;
    double n;

    time_t  utime;  // use current UNIX time as seed

    // Seed the random number generator

    srandom((unsigned) time(&utime));

    printf("arvg is: %d utime is %u\n", argc, (unsigned int)utime);
    
    for (i = 0; i < argc; i++)
    {
        printf("\nargv[%d]: %s\n", i, argv[i]);
        r1 = random();
        printf("random %ld ", r1);
        printf("random & 1: %d n", (int)(r1 & 0x01));
        printf("random %% 2: %d\n", (int)(r1 % 2));
        r2 = random();
        n = (double)r1 / (double)r2;
        printf("%ld / %ld = %lf rounded: %lf\n", r1, r1, n, round(n));
    }

    return 0;
}
