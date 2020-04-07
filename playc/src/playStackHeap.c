#include    <stdio.h>
#include    <stdlib.h>
#include    <stdbool.h>
#include    <alloca.h>

void printAddresses(void *a1, void *a2, void *a3);
void printInfo(char *label, void * addr, unsigned long size, void *data);

void nxy(char *arg);
void xny();
void xyn();

int main(int argc, char *argv[])
{
    char localString[4];
    char *dynStringStack = alloca(sizeof(char) * 4);
    char *constString = "abc";
    char *dynString = malloc(sizeof(char) * 4);

    fprintf(stdout, "localString:    ");
    printAddresses((void *)&localString, (void *)localString, (void *)localString);
    fprintf(stdout, "dynStringStack: ");
    printAddresses((void *)&dynStringStack, (void *)dynStringStack, (void *)dynStringStack);
    fprintf(stdout, "constString:    ");
    printAddresses((void *)&constString, (void *)constString, (void *)constString);
    fprintf(stdout, "dynString:      ");
    printAddresses((void *)&dynString, (void *)dynString, (void *)dynString);

    nxy(dynString);
    xyn();
    xyn();
}

void nxy(char *arg)
{
    int localStart;
    char n[4] = ""; // try 1
    int x = 0xffffffff;
    int y = 0xffffffff;
    
    void *a1, *a2, *lasta;

    a1 = (void *)&x;
    a2 = (void *)n;
    if (a1 < a2)
    {
        fprintf(stdout,"x is before n in memory\n");
        a1 = a2;
    }
    else
    {
        fprintf(stdout,"x is after n in memory\n");
    }

    lasta = (void *)&y;
    if (lasta < a1)
    {
        fprintf(stdout, "y is not the last var in the function\n");
        lasta = a1;
    }

    fprintf(stdout, "last local var:     %p\n", lasta);

    fprintf(stdout, "arg:                %p\n", arg);
    fprintf(stdout, "&arg:               %p  size: %lu\n", &arg, sizeof(arg));

    a1 = (void *) &arg;
    a2 = (void *) &localStart;
    fprintf(stdout, "locals:             %p  diff: %lu\n", &localStart, a2 - a1);
    fprintf(stdout, "passed stack frame: %p\n", alloca(4));

    fprintf(stdout, "Declares n x y\n");
    fprintf(stdout, "x, y, n\n");
    printAddresses((void *)&x, (void *)&y, n);


    printInfo("n", &n, sizeof(n), n);
    printInfo(n, &n, sizeof(n), n);
    printInfo("x", &x, sizeof(x), &x);
    printInfo("y", &y, sizeof(y), &y);

}
void xny()
{
    int x = 0xffffffff;
    char n[4] = "";
    int y = 0xffffffff;
    
    void *a1, *a2;

    fprintf(stdout, "Declares x n y\n");
    fprintf(stdout, "x, y, n\n");
    printAddresses((void *)&x, (void *)&y, n);

    a1 = (void *)&x;
    a2 = (void *)n;
    if (a1 < a2)
        fprintf(stdout,"x is before n in memory\n");
    else
        fprintf(stdout,"x is after n in memory\n");

    printInfo("n", &n, sizeof(n), n);
    printInfo(n, &n, sizeof(n), n);
    printInfo("x", &x, sizeof(x), &x);
    printInfo("y", &y, sizeof(y), &y);

}
void xyn()
{
    int x = 0xffffffff;
    int y = 0xffffffff;
    char n[4] = "";
    
    void *a1, *a2;

    fprintf(stdout, "Declares x y n\n");
    fprintf(stdout, "x, y, n\n");
    printAddresses((void *)&x, (void *)&y, n);

    a1 = (void *)&x;
    a2 = (void *)n;
    if (a1 < a2)
        fprintf(stdout,"x is before n in memory\n");
    else
        fprintf(stdout,"x is after n in memory\n");

    printInfo("n", &n, sizeof(n), n);
    printInfo(n, &n, sizeof(n), n);
    printInfo("x", &x, sizeof(x), &x);
    printInfo("y", &y, sizeof(y), &y);

}
void printAddresses(void *a1, void *a2, void *a3)
{
    fprintf(stdout, "%p %p %p\n", a1, a2, a3);
}

void printInfo(char *label, void * addr, unsigned long size, void *data)
{
    fprintf(stdout, "%s: arg1: %p arg2: %p arg3: %p arg4: %p\n",
                    label, &label, &addr, &size, &data);
    fprintf(stdout, "%s: address: %p size: %lu\n", label, addr, size);
}

