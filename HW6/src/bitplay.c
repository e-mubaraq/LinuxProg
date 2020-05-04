#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

unsigned int invert(unsigned int x, int p, int n);

int main()
{
    unsigned int x;
    unsigned int y;
    unsigned int z;

    x = 255;
    y = invert(x, 0, 1);
    z = invert(y, 0, 1);

    fprintf(stdout, "x is %lu, inverted is %lu, inverted again is %lu\n", x, y, z);

    x = 0xbc;
    y = invert(x, 0, 1);
    z = invert(y, 0, 1);

    fprintf(stdout, "x is %lu, inverted is %lu, inverted again is %lu\n", x, y, z);

    // add your own test cases - at least 4 more.
}

unsigned int invert(unsigned int x, int p, int n) {

    return x;
}