
#include <math.h>       // for pow and ceil

double round(double x)
{
    return ceil(x - 0.5);
}

/*
double round(double x, int n)
{
    double factor;
    if (n < 0)
        return x;

    factor = pow(10.0, n);
    return ceil(x * factor - 0.5) / factor;
}
*/

