#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#include <errno.h>

#define EPSILON 1e-6

// a x^2 + b x + c
// quad ./program a b c

int getDouble(const char *str, double *result)
{
    char *end;
    errno = 0;
    *result = strtod(str, &end);

    if (str == end || *end != '\0' || errno == ERANGE)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        return 1;
    }

    double a, b, c;

    if (getDouble(*(argv + 1), &a) == 0)
        return 1;
    if (getDouble(*(argv + 2), &b) == 0)
        return 1;
    if (getDouble(*(argv + 3), &c) == 0)
        return 1;

    if (fabs(a) < EPSILON)
    {
        return 1;
    }

    double complex D = b * b - 4 * a * c;

    double complex x1 = (-b - csqrt(D)) / (2 * a);
    double complex x2 = (-b + csqrt(D)) / (2 * a);

    if (cabs(x1 - x2) < EPSILON)
    {
        if (fabs(cimag(x1)) < EPSILON)
        {
            printf("The Repeated Real Root is : %.2f\n", creal(x1));
        }
        else
        {
            printf(" The Repeated Complex Root is : %.2f %c %.2fi\n",
                   creal(x1), cimag(x1) < 0 ? '-' : '+', fabs(cimag(x1)));
        }
    }
    else if (fabs(cimag(x1)) < EPSILON && fabs(cimag(x2)) < EPSILON)
    {
        printf("The roots are %.2f AND %.2f \n", creal(x1), creal(x2));
    }
    else
    {
        printf("The roots are %.2f %c %.2fi AND %.2f %c %.2fi \n", creal(x1), cimag(x1) < 0 ? '-' : '+', fabs(cimag(x1)), creal(x2), cimag(x2) < 0 ? '-' : '+', fabs(cimag(x2)));
    }
    return 0;
}
