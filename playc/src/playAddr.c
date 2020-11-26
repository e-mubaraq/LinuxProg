#include    <stdio.h>
#include    <stdlib.h>
#include    <stdbool.h>
#include    <alloca.h>

// Note: this is a macro function

#define label(A) ((A == (void *)&x) ? "x" : ((A == (void *)n) ? "n" : ((A == (void *)&y) ? "y" : "")))

void printAddresses(void *a1, void *a2, void *a3);
void printInfo(char *label, void * addr, unsigned long size, void *data);

void *findMax(void *a1, void *a2, void *a3);
void *findMin(void *a1, void *a2, void *a3);

void nxy(char *arg);
void xny();
int *xyn();

int global1 = 12;
int global2;
int global3 = 57;

int main(int argc, char *argv[])
{
    char localString[4];
    char *dynStringStack = alloca(sizeof(char) * 4);
    char *constString = "abc";
    char *dynString = malloc(sizeof(char) * 4);

    int * q;
    q = xyn();

    fprintf(stdout, "%p %d\n", q, *q);

    fprintf(stdout, "functions(text):  ");
    printAddresses((void *)&main, (void *)&nxy, (void *)&xyn);
    fprintf(stdout, "cmd-line args:    ");
    printAddresses((void *)&argc, (void *)&argv, (void *)argv);
    fprintf(stdout, "data/bss:         ");
    printAddresses((void *)&global1, (void *)&global2, (void *)&global3);
    fprintf(stdout, "localString:      ");
    printAddresses((void *)&localString, (void *)localString, NULL);
    fprintf(stdout, "dynStringStack:   ");
    printAddresses((void *)&dynStringStack, (void *)dynStringStack, NULL);
    fprintf(stdout, "constString:      ");
    printAddresses((void *)&constString, (void *)constString, NULL);
    fprintf(stdout, "dynString (heap): ");
    printAddresses((void *)&dynString, (void *)dynString, NULL);

    // Uncomment to play with heap/stack

    nxy(dynString);
    xny();

}

void nxy(char *arg)
{
    int localStart;
    char n[1] = ""; // try 1
    int x = 0xffffffff;
    int y = 0xffffffff;
    
    void *a1, *a2, *a3, *firsta, *lasta;

    fprintf(stdout, "\n*** Declares n x y\n");
    a1 = (void *)&x;
    a2 = (void *)n;
    a3 = (void *)&y;

    lasta  = findMax(&x, n, &y);
    firsta = findMin(&x, n, &y);

    fprintf(stdout, "arg:                %p\n", arg);
    fprintf(stdout, "&arg:               %p\n", &arg);
    fprintf(stdout, "\n");

    fprintf(stdout, "first local:        %p\n", &localStart);
    fprintf(stdout, "passed stack frame: %p\n", alloca(1));

    fprintf(stdout, "highMem var is %s:   %p\n", label(lasta), lasta);
    fprintf(stdout, "lowMem  var is %s:   %p\n", label(firsta), firsta);
}
void xny()
{
    int localStart;
    int x = 0xffffffff;
    char n[1] = ""; // try 1
    int y = 0xffffffff;
    
    void *a1, *a2, *a3, *firsta, *lasta;

    fprintf(stdout, "\n*** Declares x n y\n");

    a1 = (void *)&x;
    a2 = (void *)n;
    a3 = (void *)&y;

    fprintf(stdout, "first local:        %p\n", &localStart);
    fprintf(stdout, "passed stack frame: %p\n", alloca(1));
    lasta  = findMax(&x, n, &y);
    firsta = findMin(&x, n, &y);

    fprintf(stdout, "highMem var is %s:   %p\n", label(lasta), lasta);
    fprintf(stdout, "lowMem  var is %s:   %p\n", label(firsta), firsta);
}
int *xyn()
{
    int localStart;
    int x = 0xffffffff;
    int y = 0xffffffff;
    char n[1] = ""; // try 1
    
    void *a1, *a2, *a3, *firsta, *lasta;

    fprintf(stdout, "\n*** Declares x y n\n");
    a1 = (void *)&x;
    a2 = (void *)n;
    a3 = (void *)&y;

    lasta  = findMax(&x, n, &y);
    firsta = findMin(&x, n, &y);

    fprintf(stdout, "first local:        %p\n", &localStart);
    fprintf(stdout, "passed stack frame: %p\n", alloca(1));
    fprintf(stdout, "highMem var is %s:   %p\n", label(lasta), lasta);
    fprintf(stdout, "lowMem  var is %s:   %p\n", label(firsta), firsta);
    return &x;
}
void printAddresses(void *a1, void *a2, void *a3)
{
    fprintf(stdout, "%-15p %-15p %-15p\n", a1, a2, a3);
}

void printInfo(char *label, void *addr, unsigned long size, void *data)
{
    fprintf(stdout, "%s:  address: %p size: %lu\n", label, addr, size);
    fprintf(stdout, "&s: arg1: %p arg2: %p arg3: %p arg4: %p\n",
                    &label, &addr, &size, &data);
}

void *findMax(void *a1, void *a2, void *a3)
{
    if ((a1 > a2) && (a1 > a3))
        return a1;
    if ((a2 > a1) && (a2 > a3))
        return a2;
    return a3;
}
void *findMin(void *a1, void *a2, void *a3)
{
    if ((a1 < a2) && (a1 < a3))
        return a1;
    if ((a2 < a1) && (a2 < a3))
        return a2;
    return a3;
}

