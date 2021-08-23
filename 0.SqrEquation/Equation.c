#include "Equation.h"
enum condition {complex, rational, linearExist, infinite, nonExistent};

struct EqRoots{
    double bPart, dPart;
    int condition;
};

void LinSolution(double *a, double *b, struct EqRoots* roots)
{
    if ((*b) == 0 && (*a) == 0)
    {
        roots->condition = infinite;
        return;
    }

    if ((*a) == 0)
    {
        roots->condition = nonExistent;
        return;
    }
    else
    {
        roots->condition = linearExist;
        roots->bPart = -(*b)/(*a);
    }
}

int greeting(void){
    printf("Hello, user! Please, choose which equation you would like to solve\n Type \"s\" for square and \"l\" "
           "for linear.\n");
    char type = ' ';
    do
    {
        scanf("%c", &type);
        if (type != 's' && type != 'l')
        {
            printf("Type \"s\" for square and \"l\" for linear.\n");
        }
    } while (type != 's' && type != 'l');

    if (type == 's')
    {
        printf("Please, enter the coefficients.\nExample: For equation x^2 + 2.1x + 1 = 0\n"
               "Write: 1 2.1 1\n");
        return 0;
    }
    else
    {
        printf("Please, enter the coefficients.\nExample: For equation x + 1 = 0\n"
               "Write: 1 1\n");
        return 1;
    }
}

int getNumbersSqr(double *a, double *b, double *c)
{
    while(scanf("%lf %lf %lf", a, b, c) != 3)
    {
        while(fgetc(stdin) != '\n');
        printf ("Wrong input, try again.\n");
    };
}

int getNumbersLin(double *a, double *b)
{
    while(scanf("%lf %lf", a, b) != 2)
    {
        while(fgetc(stdin) != '\n');
        printf ("Wrong input, try again.\n");
    };
}

void sqrSolution(double *a, double *b, double *c,  struct EqRoots* roots)
{
    if ((*a) == 0)
    {
        LinSolution(b, c, roots);
        return;
    }

    double* disc = malloc(sizeof(double));
    (*disc) = (*b) * (*b) - 4 * (*a) * (*c);
    roots->bPart = -(*b)/(2*(*a));

    if ((*disc) == 0)
    {
        roots->condition = linearExist;
        return;
    }
    if ((*disc) < 0)
    {
        (*disc) *= -1;
        (*disc) = sqrt((*disc));
        roots->condition = complex;
    }
    else
    {
        (*disc) = sqrt((*disc));
        roots->condition = rational;
    }
    roots->dPart = (*disc)/(2*(*a));
    return;
}

void interface(double *a, double *b, double *c)
{
    struct EqRoots* roots = malloc(sizeof (struct EqRoots));
    if(greeting() == 1)
    {
        getNumbersLin(a, b);
        (*c) = 0;
        LinSolution(a, b, roots);
        switch (roots->condition) {
            case nonExistent:
                printf("Root doesn't exist.");
                break;
            case infinite:
                printf("x belongs R");
                break;
            case linearExist:
                printf("Root is rational.\n"
                       "x = %lf", roots->bPart);
                break;
        }
    }
    else
    {
        getNumbersSqr(a, b, c);
        sqrSolution(a, b, c, roots);
        switch (roots->condition) {
            case rational:
                printf("Roots are rational.\n"
                       "x1 = %lf and x2 = %lf", roots->bPart - roots->dPart, roots->bPart + roots->dPart);
                break;
            case linearExist:
                printf("Root is rational.\n"
                       "x = %lf", roots->bPart);
                break;
            case complex:
                printf("Roots are complex.\n"
                       "x1 = %lf - %lf""i and x2 = %lf + %lf""i",
                       roots->bPart, roots->dPart, roots->bPart, roots->dPart);
                break;
        }
    }
}


