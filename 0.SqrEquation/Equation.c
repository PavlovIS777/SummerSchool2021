#include "Equation.h"
enum condition {COMPLEX, RATIONAL, LINEAR_EXISTS, INF, NON_EXISTENT};

struct Equation{
    double bPart, dPart;
    int condition;
};

int isEqualToZero(double* d)
{
    double eps = 1e-12;
    if (fabs((*d)) < eps)
        return 1;
    else
        return 0;
}
struct Equation solveSqr(double* a, double* b, double* c, struct Equation* Equation)
{
    double disc = (*b) * (*b) - 4 * (*a) * (*c);
    Equation->bPart = -(*b)/(2*(*a));
    if (isEqualToZero(&disc))
    {
        Equation->condition = LINEAR_EXISTS;
        return *Equation;
    }
    if (disc < 0)
    {
        disc *= -1;
        disc = sqrt(disc);
        Equation->condition = COMPLEX;
    }
    else
    {
        disc = sqrt(disc);
        Equation->condition = RATIONAL;
    }
    Equation->dPart = disc/(2*(*a));
    return *Equation;
}

struct Equation solveLin(double *a, double *b, struct Equation* Equation)
{
    if (isEqualToZero(a) && isEqualToZero(b))
    {
        Equation->condition = INF;
        return *Equation;
    }

    if (isEqualToZero(a))
    {
        Equation->condition = NON_EXISTENT;
        return *Equation;
    }
    else
    {
        Equation->condition = LINEAR_EXISTS;
        Equation->bPart = -(*b)/(*a);
        return *Equation;
    }
}

void getCoefficients(double* a, double* b, double* c){
    printf("Please, enter the coefficients.\nExample: For equation x^2 + 2.1x + 1 = 0\n"
           "Write: 1 2.1 1\n");

    while(scanf("%lf %lf %lf", a, b, c) != 3)
    {
        while(fgetc(stdin) != '\n');
        printf ("Wrong input, try again.\n");
    };
}

void Solve(double *a, double *b, double *c,  struct Equation* Equation)
{
    if (isEqualToZero(a))
    {
        *Equation = solveLin(b, c, Equation);
        return;
    }
    else
    {
        *Equation = solveSqr(a, b, c, Equation);
        return;
    }
}

void checkTest(struct Equation* test, double a, double b, double c)
        {
    double rationalPart;
    double rationalPartMinus;
    double complexPartPlus;
    double complexPartMinus;
    switch (test->condition) {
        case COMPLEX:
            rationalPart = (a)*(test->bPart*test->bPart - test->dPart*test->dPart) +
                    + (b)*(test->bPart)+(c);
            complexPartPlus = (a) * (test->bPart * test->dPart * 2)+(b) * (test->dPart);
            complexPartMinus = (a) * (-test->bPart * test->dPart * 2)+(b) * (-test->dPart);
            if (isEqualToZero(&rationalPart) && isEqualToZero(&complexPartMinus) &&
                isEqualToZero(&complexPartPlus))
            {
                printf("success test\n");
            }
            else
            {
                printf("error test\n Expected: %lf * (%lf +/- %lf""i)^2 + "
                       "%lf * (%lf +/- %lf""i) + %lf = 0\n", a, test->bPart, test->dPart,
                       b, test->bPart, test->dPart, c);
                printf("Get: %lf + %lf and %lf + %lf", rationalPart, complexPartPlus,
                       rationalPart, complexPartMinus);
            }
            break;
            case RATIONAL:
                rationalPart = a*(test->dPart+test->bPart)*(test->bPart+test->dPart) + b*(test->bPart+test->dPart) + c;
                rationalPartMinus = a*(test->bPart - test->dPart)*(test->bPart - test->dPart) + b*(test->bPart - test->dPart) + c;
                if (isEqualToZero(&rationalPart) && isEqualToZero(&rationalPartMinus))
                {
                    printf("success test\n");
                }
                else
                {
                    double x1 = (test->bPart - test->dPart) / (2 * a);
                    double x2 = (test->bPart + test->dPart) / (2 * a);
                    printf("error test\n Expected: %lf * (%lf / %lf)^2 + "
                           "%lf * (%lf / % lf) + %lf = 0\n", a, x1,
                           x2, b, x1, x2, c);
                    printf("Get: %lf and %lf", rationalPartMinus, rationalPart);
                }
                break;
                case LINEAR_EXISTS:
                    rationalPart = a*(test->bPart)*(test->bPart) +
                            + b * (test->bPart) + c;
                    if(isEqualToZero(&rationalPart))
                    {
                        printf("success test\n");
                    }
                    else
                    {
                        printf("error test\n"
                               "Expected: %lf * %lf + %lf = 0", b, test->bPart, c);
                        printf("Get: %lf", rationalPart);
                    }
    }
}

void testSys(double* testArr, size_t testsCount)
{
    struct Equation tests;
    for (size_t i = 0; i < testsCount; i +=3)
    {
        Solve(&testArr[i], &testArr[i+1], &testArr[i+2], &tests);
        checkTest(&tests, testArr[i], testArr[i+1], testArr[i+2]);
    }
}

void inputOutput(double *a, double *b, double *c)
{
    getCoefficients(a, b, c);

    struct Equation Equation;
    Solve(a, b, c, (&Equation));

    switch (Equation.condition) {
        case RATIONAL:
            printf("Roots are rational.\n"
                   "x1 = %lf and x2 = %lf", Equation.bPart - Equation.dPart,
                   Equation.bPart + Equation.dPart);
            break;
        case LINEAR_EXISTS:
            printf("Root is rational.\n"
                   "x = %lf", Equation.bPart);
                break;
        case COMPLEX:
            printf("Roots are complex.\n"
                   "x1 = %lf - %lf""i and x2 = %lf + %lf""i",
                   Equation.bPart, Equation.dPart, Equation.bPart, Equation.dPart);
            break;
        case INF:
            printf("x belongs R");
            break;
        case NON_EXISTENT:
            printf("There's no solution.");
            break;
    }
}


