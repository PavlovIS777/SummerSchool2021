#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//binRoot documentation.
//type: function.
//description: double function that's finding root from number using bin search method.
//             Returns double root from number.
//example: binRoot(4), returns 2.
int isRootsReal(double *d)
{
    if ((*d) < 0){
        printf("Roots are complex!\n");
        (*d) = -*d;
        (*d) = sqrt((*d));
        return 0;
    } else {
        if ((*d) == 0)
        {
            printf("Root is real!\n");
            return 1;
        }
        else
        {
            (*d) = sqrt((*d));
            printf("Roots are real!\n");
            return 2;
        }
    }
}

void LinSolution(double *a, double *b)
{
    if ((*b) == 0 && (*a) == 0)
    {
        printf("Root: x belongs R");
        return;
    }
    else if ((*a) == 0)
    {
        printf("Root doesn't exist :^(");
        return;
    }
    else
    {
        printf("Root: x = %lf!", -(*b)/(*a));
        return;
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

int sqrSolution(double *a, double *b, double *c)
{
    double *disc = malloc(sizeof(double));
    (*disc) = (*b) * (*b) - 4 * (*a) * (*c);
    if ((*a) == 0 && (*b) == 0 && (*c) == 0)
    {
        printf("x belongs R");
        return 0;
    }
    if ((*a) == 0 && (*b) == 0)
    {
        printf("Root doesn't exist :^(");
        return 0;
    }
    if ((*a) == 0)
    {
        LinSolution(b, c);
    }
    int condition = isRootsReal(disc);
    if(condition == 2)
    {
        printf("Roots: x1 = %lf and x2 = %lf!",(-(*b)-(*disc))/(2*(*a)), (-(*b)+(*disc))/(2*(*a)));
    }
    else if (condition == 1)
    {
        printf("Root: x = %lf!", -(*b)/(2*(*a)));
    }
    else
    {
        printf("Roots: x1 = %lf - %lf""i and x2 = %lf + %lf""i", -(*b)/(2*(*a)), (*disc)/(2*(*a)), -(*b)/(2*(*a)), (*disc)/(2*(*a)));
    }
    return 1;
}

void interface(double *a, double *b, double *c)
{
    if(greeting() == 1)
    {
        getNumbersLin(a, b);
        (*c) = 0;
        LinSolution(a, b);
    }
    else
    {
        getNumbersSqr(a, b, c);
        sqrSolution(a, b, c);
    }
}

int main() {
    double a = 0, b = 0, c = 0;
    interface(&a, &b, &c);
    return 0;
}
