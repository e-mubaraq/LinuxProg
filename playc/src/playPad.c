#include    <stdio.h>
#include    <stdbool.h>

#define MAXROWS 3
#define MAXCOLS 5

typedef struct
{
    int rows, cols;
    int table[MAXROWS][MAXCOLS];
} Matrix1;

typedef struct
{
    char c;
    int rows, cols;
    int table[MAXROWS][MAXCOLS];
} Matrix2;

void printAddresses1(Matrix1 m);
void printAddresses2(Matrix2 m);

void printAddresses3(const Matrix1 *m);
void printAddresses4(const Matrix2 *m);

int main(int argc, char *argv[])
{
    Matrix1 m1;
    Matrix2 m2;

    fprintf(stdout, "address(m1) %p\n", &m1);
    fprintf(stdout, "sizeof(m1) %ld\n", sizeof(m1));
    fprintf(stdout, "\n");
    fprintf(stdout, "address(m2) %p\n", &m2);
    fprintf(stdout, "sizeof(m2) %ld\n", sizeof(m2));
    fprintf(stdout, "\n");
    
    printAddresses1(m1);
    printAddresses2(m2);
    fprintf(stdout, "\n");
    
    printAddresses3(&m1);
    printAddresses4(&m2);
    fprintf(stdout, "\n");
    
    return(0);
}

void printAddresses1(Matrix1 m)
{
    fprintf(stdout, "--------- Matrix1 pass-by-value ---------\n");
    fprintf(stdout, "address(m) %p\n", &m);
    fprintf(stdout, "sizeof(m) %ld\n", sizeof(m));

    fprintf(stdout, "address(m.rows) %p\n", &m.rows);
    fprintf(stdout, "sizeof(m.rows) %ld\n", sizeof(m.rows));

    fprintf(stdout, "address(m.cols) %p\n", &m.cols);
    fprintf(stdout, "sizeof(m.cols) %ld\n", sizeof(m.cols));

    fprintf(stdout, "sizeof(m.table) %ld\n", sizeof(m.table));
    fprintf(stdout, "address(m.table) %p\n", &m.table);
}
void printAddresses2(Matrix2 m)
{
    fprintf(stdout, "--------- Matrix2 pass-by-value ---------\n");
    fprintf(stdout, "address(m) %p\n", &m);
    fprintf(stdout, "sizeof(m) %ld\n", sizeof(m));

    fprintf(stdout, "address(m.rows) %p\n", &m.rows);
    fprintf(stdout, "sizeof(m.rows) %ld\n", sizeof(m.rows));

    fprintf(stdout, "address(m.cols) %p\n", &m.cols);
    fprintf(stdout, "sizeof(m.cols) %ld\n", sizeof(m.cols));

    fprintf(stdout, "sizeof(m.c) %ld\n", sizeof(m.c));
    fprintf(stdout, "address(m.c) %p\n", &m.c);

    fprintf(stdout, "sizeof(m.table) %ld\n", sizeof(m.table));
    fprintf(stdout, "address(m.table) %p\n", &m.table);
}
void printAddresses3(const Matrix1 *m)
{
    fprintf(stdout, "--------- Matrix1 pass-by-address (pointer) ---------\n");
    fprintf(stdout, "address(m) %p\n", m);
    fprintf(stdout, "sizeof(*m) %ld\n", sizeof(*m));

    fprintf(stdout, "address(m->rows) %p\n", &m->rows);
    fprintf(stdout, "sizeof(m->rows) %ld\n", sizeof(m->rows));

    fprintf(stdout, "address(m->cols) %p\n", &m->cols);
    fprintf(stdout, "sizeof(m->cols) %ld\n", sizeof(m->cols));

    fprintf(stdout, "sizeof(m->table) %ld\n", sizeof(m->table));
    fprintf(stdout, "address(m->table) %p\n", &m->table);
}
void printAddresses4(const Matrix2 *m)
{
    fprintf(stdout, "--------- Matrix2 pass-by-address (pointer) ---------\n");
    fprintf(stdout, "address(m) %p\n", m);
    fprintf(stdout, "sizeof(m) %ld\n", sizeof(*m));

    fprintf(stdout, "address(m->rows) %p\n", &m->rows);
    fprintf(stdout, "sizeof(m->rows) %ld\n", sizeof(m->rows));

    fprintf(stdout, "address(m->cols) %p\n", &m->cols);
    fprintf(stdout, "sizeof(m->cols) %ld\n", sizeof(m->cols));

    fprintf(stdout, "sizeof(m->c) %ld\n", sizeof(m->c));
    fprintf(stdout, "address(m->c) %p\n", &m->c);

    fprintf(stdout, "sizeof(m->table) %ld\n", sizeof(m->table));
    fprintf(stdout, "address(m->table) %p\n", &m->table);
}
