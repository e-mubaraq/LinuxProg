
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    short  s = 10;
    int    i = 10;
    long   l = 10;
    double d = 10;
    float  f = 10;
    char  *name = "cathy";
    char   c = 'c';
    bool   b = true;

    unsigned u = 10;
    unsigned long   ul = 10;

    printf("s: %d i: %d l: %ld d: %f f: %f name: %s c: %c\n", s, i, l, d, f, name, c);
    fprintf(stdout, "s: %d i: %d l: %ld d: %f f: %f name: %s c: %c\n", s, i, l, d, f, name, c);
    fprintf(stderr, "is: %d : %d l: %ld d: %f f: %f name: %s c: %c\n", s, i, l, d, f, name, c);

    printf("\nsizeof()  s: %lu i: %lu  l: %lu d: %lu f: %lu name: %lu c: %lu b: %lu\n",
            sizeof(s), sizeof(i), sizeof(l), sizeof(d), sizeof(f),
            sizeof(name), sizeof(c), sizeof(b));

    printf("sizeof() us: %lu u: %lu lu: %lu\n\n",
            sizeof(unsigned short), sizeof(u), sizeof(ul));

    printf("INT_MAX: %d\n", INT_MAX);

    for (i = INT_MAX - 3; i < INT_MAX; i++)
    {
        printf("i: %d 0x%04X \n", i, i);
    }
    printf("i: %d\n", i);
    for (i = 0; i <=10; i++)
        printf("i: %d 0x%04X \n", i, i);
}
