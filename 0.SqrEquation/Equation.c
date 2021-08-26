#include "Equation.h"
#include <assert.h>

int isEqualDouble(double one, double two)
{
    double eps = 1e-12;
    if (fabs(one - two)  < eps)
        return EQUAL;
    else
        return NON_EQUAL;
}

struct EquationSolutionStatus solveQuadCase(double a, double b, double c)
{

    if (isEqualDouble(a, 0.0))
    {
        return solveLinearCase(b, c);
    }
    struct EquationSolutionStatus Equation = {NAN, NAN, UNDEF};
    double disc = b * b - 4 * a * c;
    Equation.bPart = -(b)/(2 * a);
    if (isEqualDouble(disc, 0.0))
    {
        Equation.condition = LINEAR_EXISTS;
        Equation.dPart = 0;
        return Equation;
    }
    if (disc < 0)
    {
        disc *= -1;
        disc = sqrt(disc);
        Equation.condition = COMPLEX;
    }
    else
    {
        disc = sqrt(disc);
        Equation.condition = RATIONAL;
    }
    Equation.dPart = disc/(2 *a );
    return Equation;
}

struct EquationSolutionStatus solveLinearCase(double a, double b)
{
    struct EquationSolutionStatus Equation = {NAN, NAN, UNDEF};
    Equation.dPart = 0;
    if (isEqualDouble(a, 0.0) && isEqualDouble(b, 0.0))
    {
        Equation.condition = INF;
        Equation.bPart = 0;
        return Equation;
    }

    if (isEqualDouble(a, 0.0))
    {
        Equation.bPart = 0;
        Equation.condition = NON_EXISTENT;
        return Equation;
    }
    else
    {
        Equation.condition = LINEAR_EXISTS;
        Equation.bPart = -(b)/(a);
        return Equation;
    }
}

void getCoefficients(double* a, double* b, double* c)
{
    printf("Please, enter the coefficients.\nExample: For equation x^2 + 2.1x + 1 = 0\n"
           "Write: 1 2.1 1\n");
    int attemptsCount = 5;
    while(scanf("%lf %lf %lf", a, b, c) != 3)
    {
        --attemptsCount;
        if (attemptsCount == 0)
        {
            printf("Maximum number of attempts WASTED.");
            return;
        }

        while(fgetc(stdin) != '\n');
        printf ("Wrong input, try again.\n");

    }
}

void QuadEquationSolution()
{
    double a = NAN, b = NAN, c = NAN;
    getCoefficients(&a, &b, &c);
    assert(a == NAN); assert(b == NAN); assert(c == NAN);

    struct EquationSolutionStatus Equation = {NAN, NAN, UNDEF};
    Equation = solveQuadCase(a, b, c);
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

void unitTest()
{
    FILE* input;
    FILE* output;

    input = fopen("testInput.txt", "r");
    output = fopen("Log.txt", "w");

    if (input == NULL)
    {
        printf("Error reading input file.");
        return;
    }
    if (output == NULL)
    {
        printf("Error writing output file.");
        return;
    }

    double a = NAN, b = NAN, c = NAN, bPart = NAN, dPart = NAN;
    int condition = UNDEF;
    int testsCount = 0;

    fscanf(input, "%d", &testsCount);

//    double** testsArr = malloc(sizeof (double*)*testsCount);
//    for (size_t i = 0; i < testsCount; ++i)
//        testsArr[i] = malloc(sizeof (double) * 3);

    for (size_t i = 0; i < testsCount; ++i)
    {
        fscanf(input, "%lf %lf %lf %d %lf %lf", &a, &b, &c, &condition, &bPart, &dPart);
        if (a == NAN || b == NAN || c == NAN || bPart == NAN || dPart == NAN || condition == UNDEF)
        {
            printf("Wrong test format.");
            return;
        }

        struct EquationSolutionStatus test = {NAN, NAN, UNDEF};
        test = solveQuadCase(a, b, c);
        if (!(isEqualDouble(test.bPart, bPart) && isEqualDouble(test.dPart, dPart) && test.condition == condition))
        {
            fprintf(output,"*===Test %d====*\n"
                           "Wrong answer.\n"
                           "Expected: bPart = %lf, dPart = %lf, condition = %d\n"
                           "Get: bPart = %lf, dPart = %lf, condition = %d\n"
                           "*============*\n\n",
                           i + 1, bPart, dPart, condition,
                           test.bPart, test.dPart,test.condition);
            return;
        }
        else
        {
            fprintf(output,"*===Test %d====*\n"
                           "Test passed!\n"
                           "*============*\n\n", i+1);
        }
    }
}

void commandLineInterface(){
    printf("Hello, user! Please, choose program mode.\n "
           "Type \"T\" for testing and \"E\" "
           "for the program executing.\n");
    char mode = ' ';
    int attemptCounts = 5;
    do
    {
        scanf("%c", &mode);
        if (mode != (char)TESTING_MODE && mode != (char)EXECUTING_MODE)
        {
            fgetc(stdin);
            if (attemptCounts > 0)
                printf("Type \"T\" for Testing mod and \"E\" for Executing.\n");
            else
            {
                printf("Maximum number of attempts WASTED.");
                return;
            }
            --attemptCounts;
        }
    } while (mode != (char)EXECUTING_MODE && mode != (char)TESTING_MODE);

    if (mode == (char)TESTING_MODE)
        unitTest();
    else
        QuadEquationSolution();
}