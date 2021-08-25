#include "Equation.h"
#include <assert.h>
enum condition
{
    COMPLEX = 0,
    RATIONAL,
    LINEAR_EXISTS,
    INF,
    NON_EXISTENT
};

struct Equation
{
    double bPart, dPart;
    int condition;
};

int isEqualDouble(double one, double two)
{
    double eps = 1e-12;
    if (fabs(one - two)  < eps)
        return 1;
    else
        return 0;
}
void solveSqr(double a, double b, double c, struct Equation* Equation)
{
    double disc = b * b - 4 * a * c;
    Equation->bPart = -(b)/(2 * a);
    if (isEqualDouble(disc, 0.0))
    {
        Equation->condition = LINEAR_EXISTS;
        return;
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
    Equation->dPart = disc/(2 *a );
    return;
}

void solveLin(double a, double b, struct Equation* Equation)
{
    if (isEqualDouble(a, 0.0) && isEqualDouble(b, 0.0))
    {
        Equation->condition = INF;
        return;
    }

    if (isEqualDouble(a, 0.0))
    {
        Equation->condition = NON_EXISTENT;
        return;
    }
    else
    {
        Equation->condition = LINEAR_EXISTS;
        Equation->bPart = -(b)/(a);
        return;
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

void Solve(double a, double b, double c,  struct Equation* Equation)
{
    if (isEqualDouble(a, 0.0))
    {
        solveLin(b, c, Equation);
        return;
    }
    else
    {
        solveSqr(a, b, c, Equation);
        return;
    }
}

void QuadEquationCLI(double* a, double* b, double* c)
{
    getCoefficients(a, b, c);

    struct Equation Equation = {0};
    Solve(*a, *b, *c, (&Equation));

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

void testSys()
{
    FILE* input;
    FILE* output;
    double a = NAN, b = NAN, c = NAN, bPart = NAN, dPart = NAN;
    int condition = -1, testsCount = 1;
    input = fopen("testInput.txt", "r");
    output = fopen("Log.txt", "w");
    assert(input);
    assert(output);
    for (size_t i = 0; i < 4; ++i)
    {
        fscanf(input, "%lf %lf %lf %d %lf %lf", &a, &b, &c, &condition, &bPart, &dPart);
        struct Equation test = {0};
        Solve(a, b, c, &test);
        if (!(isEqualDouble(test.bPart,bPart) && isEqualDouble(test.dPart, dPart) && isEqualDouble(test.condition, condition)))
        {
            fprintf(output,"*===Test %d====*\n"
                           "Wrong answer.\n"
                           "Expected: bPart = %lf, dPart = %lf, condition = %d\n"
                           "Get: bPart = %lf, dPart = %lf, condition = %d\n"
                           "*============*\n\n",
                           testsCount, bPart, dPart, condition,
                           test.bPart, test.dPart,test.condition);
        }
        else
        {
            fprintf(output,"*===Test %d====*\n"
                           "Test passed!\n"
                           "*============*\n\n", testsCount);
        }
        ++testsCount;
    }
}

void greeting(double* a, double* b, double* c){
    printf("Hello, user! Please, choose program mode.\n "
           "Type \"T\" for testing and \"E\" "
           "for the program executing.\n");
    char type = ' ';
    do
    {
        scanf("%c", &type);
        if (type != 'T' && type != 'E')
        {
            printf("Type \"T\" for Testing mod and \"E\" for Executing.\n");
        }
    } while (type != 'E' && type != 'T');
    if (type == 'T')
        testSys();
    else
        QuadEquationCLI(a, b, c);
}