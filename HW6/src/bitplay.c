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
    x = 0xff;
    y = invert(x, 1, 1);
    z = invert(y, 1, 1);

    fprintf(stdout, "x is %lu, inverted is %lu, inverted again is %lu\n", x, y, z);

    x = 0x00;
    y = invert(x, 3, 1);
    z = invert(y, 3, 1);

    fprintf(stdout, "x is %lu, inverted is %lu, inverted again is %lu\n", x, y, z);

    x = 128;
    y = invert(x, 5, 4);
    z = invert(y, 5, 4);

    fprintf(stdout, "x is %lu, inverted is %lu, inverted again is %lu\n", x, y, z);

    x = 0b1010110;
    y = invert(x, 4, 3);
    z = invert(y, 4, 3);

    fprintf(stdout, "x is %lu, inverted is %lu, inverted again is %lu\n", x, y, z);
}

unsigned int invert(unsigned int x, int p, int n) {

    //return ~((x >> (p+1-n)) | (0 << n-1));
    if (p < n)
        p = n;
    return x ^= (1 << n) << (p-n);
}