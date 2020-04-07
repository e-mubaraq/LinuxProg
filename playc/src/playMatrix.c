#include    <stdio.h>
#include    <stdbool.h>

/*
 * 
 * This is a program that plays around with C. It demonstrates structs and 2-dimensional
 * arrays.
 *
 * Author: Cathy Bishop
 *
 */

/*
 * struct Matrix:
 *
 * A Matrix is a 2-dimensional table of integer values, with a maximum of
 * 100 rows and 100 columns.
 *
 */

#define MAXROWS 3
#define MAXCOLS 5

typedef struct
{
    int rows, cols;
    int table[MAXROWS][MAXCOLS];
} Matrix;

void initMatrix(Matrix *m, int nRows, int nCols);
void printLabelledMatrix(Matrix *m);
void printMatrix(Matrix *m);
int findMax(Matrix *m);
int findDigits(int num);

int main(int argc, char *argv[])
{
    FILE *inf;
    char *filename = "test1";
    char line[100];

    Matrix m;

    fprintf(stdout, "sizeof(m) %ld\n", sizeof(m));
    fprintf(stdout, "calc sizeof(m.table) %ld\n", MAXROWS * MAXCOLS * sizeof(int));
    fprintf(stdout, "sizeof(m.table) %ld\n", sizeof(m.table));
    initMatrix(&m, 3, 5);
    printLabelledMatrix(&m);
    printMatrix(&m);
    
    return(0);
}

void initMatrix(Matrix *m, int nRows, int nCols)
{
    int i, j;

    m->rows=nRows;
    m->cols=nCols;

    fprintf(stdout, "rows: %d cols: %d\n", m->rows, m->cols);
    for (i = 0; i < m->rows; i++)
    {
        for (j = 0; j < m->cols; j++)
        {
            m->table[i][j] = ((i + 1) * 10) + j + 1;
        }
    }
        
}

/*
 * Function printMatrix.
 *
 * Prints a Matrix struct.
 *
 * The struct must be properly initialized.
 *
 */

void printMatrix(Matrix *m)
{
    int i, j;
    int max;
    int maxDigits = 0;

    max = findMax(m);
    maxDigits = findDigits(max);

    fprintf(stdout, "\nMatrix has rows: %d cols: %d\n", m->rows, m->cols);
    for (i = 0; i < m->rows; i++)
    {
        for (j = 0; j < m->cols; j++)
        {
            fprintf(stdout, "%*d", maxDigits + 1,  m->table[i][j]);
        }
        fprintf(stdout, "\n");
    }
}

void printLabelledMatrix(Matrix *m)
{
    int i, j;
    int *addr1, *addr2;

    fprintf(stdout, "\nMatrix has rows: %d cols: %d\n", m->rows, m->cols);
    fprintf(stdout, "\nMAX Matrix has rows: %d cols: %d\n", MAXROWS, MAXCOLS);
    addr1 = &(m->table[0][0]);
    addr2 = &(m->table[MAXROWS-1][MAXCOLS-1]);
    fprintf(stdout, "MAX Address first: %p address last: %p diff %ld\n",
            addr1, addr2, addr2 - addr1);
    addr2 = &(m->table[m->rows-1][m->cols-1]);
    fprintf(stdout, "Address first: %p address last: %p diff %ld\n",
            addr1, addr2, addr2 - addr1);
    for (i = 0; i < m->rows; i++)
    {
        for (j = 0; j < m->cols; j++)
        {
            fprintf(stdout, "%p matrix[%d, %d]: %d\n", &(m->table[i][j]), i, j, m->table[i][j]);
        }
    }
}

int findMax(Matrix *m)
{
    int i, j;
    int max;

    max = m->table[0][0];

    for (i = 0; i < m->rows; i++)
    {
        for (j = 0; j < m->cols; j++)
        {
            if (m->table[i][j] > max)
                max = m->table[i][j];
        }
    }
    return max;
}

int findDigits(int num)
{
    int n;
    int maxDigits = 0;

    n = num;
    while (n > 0)
    {
        maxDigits++;
        n = n / 10;
    }
    return maxDigits;
}
