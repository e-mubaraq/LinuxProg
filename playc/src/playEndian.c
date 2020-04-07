#include    <stdio.h>
#include    <stdbool.h>

void printBytes(char *ptr);

int main(int argc, char *argv[])
{
    int x, y, z;

    x = 1;
    y = 255;
    z = 256;

    fprintf(stdout, "address x: %p sizeof  x: %lu\n", &x, sizeof(x));
    fprintf(stdout, "address y: %p sizeof  y: %lu\n", &y, sizeof(y));
    fprintf(stdout, "address z: %p sizeof  z: %lu\n", &z, sizeof(z));

    printBytes((void *)&x);
    printBytes((void *)&y);
    printBytes((void *)&z);
    return(0);
}

void printBytes(char *ptr)
{
    fprintf(stdout, "\n");
    fprintf(stdout, "sizeof ptr %lu\n", sizeof(*ptr));

    fprintf(stdout, "address %p value %02x\n", ptr, (char)*ptr);
    ptr++;
    fprintf(stdout, "address %p value %02x\n", ptr, *ptr);
    ptr++;
    fprintf(stdout, "address %p value %02x\n", ptr, *ptr);
    ptr++;
    fprintf(stdout, "address %p value %02x\n", ptr, *ptr);
}
