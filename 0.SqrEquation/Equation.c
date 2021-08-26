/*!
 * \file Equation.c
 */
#include "Equation.h"
/*!
 * \brief Функция сравнения.
 * \author Ivan Pavlov
 * \date 26.08.2021
 * \todo Comparison of numbers of the double type.
 *       Returns the enum value from DOUBLE_COMPARE_STATUS.
 * \example compareDouble(3.4, 4.1)
*/
int compareDouble(double lhs, double rhs)
{
    if (fabs(lhs - rhs)  < EPS)
        return EQUAL;
    else if (lhs < rhs)
        return LESS;
    else
        return GREATER;
}

/*!
 * \brief Функция решения квадратного уравнения.
 * \author Ivan Pavlov
 * \date 26.08.2021
 * A function that records the solutions of equations
 *       and the state of the roots in the QuadraticEquationSolutionStatus
 *       structure. Returns a structure containing the solution and their states.
 * \example solveQuadCase(3.4, 4.1, 5.8)
*/
struct QuadraticEquationSolutionStatus solveQuadCase(double a, double b, double c)
{
    struct QuadraticEquationSolutionStatus Equation = {NAN, NAN, UNDEF};

    if (isnan(a) || isnan(b) || isnan(c)) {
        Equation.condition = UNDEF;
        return Equation;
    }

    if (compareDouble(a, 0.0) == EQUAL)
        return solveLinearCase(b, c);

    double disc = b * b - 4 * a * c;
    Equation.bPart = -(b)/(2 * a);

    if (compareDouble(disc, 0.0) == EQUAL)
    {
        Equation.condition = LINEAR_EXISTS;
        Equation.dPart = 0;
        return Equation;
    }
    double disc_sqrt = NAN;
    if (disc < 0)
    {
        disc *= -1;
        Equation.condition = COMPLEX;
    }

    else
    {
        Equation.condition = RATIONAL;
    }
    disc_sqrt = sqrt(disc);
    Equation.dPart = disc_sqrt/(2 * a);
    return Equation;
}
/*!
 * \brief Функция решения квадратного уравнения.
 * \author Ivan Pavlov
 * \date 26.08.2021
    Function that clears the scanf() buffer.
 * \example clearBuffer()
*/
void clearBuffer()
{
    char temp;
    while((temp = fgetc(stdin)) != '\n');
}

/*!
 * \brief Функция решения линейного уравнения.
 * \author Ivan Pavlov
 * \date 26.08.2021
         A function that records the solutions of equations and the state of the roots
 *       the QuadraticEquationSolutionStatus structure in the linear case.
 *       Returns a structure containing the solution and their states.
 * \example solveLinearCase(3.4, 4.1)
*/
struct QuadraticEquationSolutionStatus solveLinearCase(double a, double b)
{
    struct QuadraticEquationSolutionStatus Equation = {NAN, NAN, UNDEF};
    Equation.dPart = 0;
    if ((compareDouble(a, 0.0) == EQUAL) &&
    (compareDouble(b, 0.0) == EQUAL))
    {
        Equation.condition = INF;
        Equation.bPart = 0;
        return Equation;
    }

    if (compareDouble(a, 0.0) == EQUAL)
    {
        Equation.bPart = 0;
        Equation.condition = NON_EXISTENT;
        return Equation;
    }
    else
    {
        Equation.condition = LINEAR_EXISTS;
        Equation.bPart = -b / a;
        return Equation;
    }
}

/*!
 * \brief Функция решения квадратного уравнения.
 * \author Ivan Pavlov
 * \date 26.08.2021
    Function records the coefficients entered by the user, according to the pointer.
 * \example solveQuadCase(a, b, c)
*/
void getCoefficients(double* a, double* b, double* c)
{
    printf("\tPlease, enter the coefficients.\n"
           "\tExample: For equation x^2 + 2.1x + 1 = 0\n"
           "\tWrite: 1 2.1 1\n");
    int attemptsCount = 5;
    while(scanf("%lf %lf %lf", a, b, c) != 3)
    {
        --attemptsCount;
        if (attemptsCount == 0)
        {
            printf("\tMaximum number of attempts WASTED.");
            return;
        }

        clearBuffer();
        printf ("\tWrong input, try again.\n");
    }
}

/*!
 * \brief Функция решения квадратного уравнения.
 * \author Ivan Pavlov
 * \date 26.08.2021
         The function creates variables and a structure in which the coefficients
 *       of the equation, the solution and the state of the roots are written, respectively.
 * \example QuadEquationSolution()
*/
struct QuadraticEquationSolutionStatus  QuadEquationSolution()
{
    double a = NAN, b = NAN, c = NAN;
    getCoefficients(&a, &b, &c);

    struct QuadraticEquationSolutionStatus Equation = {NAN, NAN, UNDEF};
    Equation = solveQuadCase(a, b, c);
    return Equation;
}

/*!
 * \brief Функция решения квадратного уравнения.
 * \author Ivan Pavlov
 * \date 26.08.2021
         The function provides unit tests by reading them from a file
 *       and writing the result to a file Log.txt.
 * \example unitTest()
*/
void unitTest()
{
    FILE* input;
    FILE* output;

    input = fopen("testInput.txt", "r");
    output = fopen("Log.txt", "w");

    if (input == NULL)
    {
        printf("\tError reading input file.");
        return;
    }
    if (output == NULL)
    {
        printf("\tError writing output file.");
        return;
    }

    double a = NAN, b = NAN, c = NAN, bPart = NAN, dPart = NAN;
    int condition = UNDEF;
    int testsCount = 0;

    fscanf(input, "%d", &testsCount);
    printf("\tChoose test output\n"
           "\tType \"C\" for console output mod or \"L\" for writing Log.txt file.\n");
    char testMode = ' ';
    int attemptCounts = 5;
    clearBuffer();
    do
    {
        scanf("%c", &testMode);
        if (testMode != (char)CONSOLE && testMode != (char)LOG)
        {
            fgetc(stdin);
            if (attemptCounts > 0)
                printf("\tType \"L\" or \"C\"\n");
            else
            {
                printf("\tMaximum number of attempts WASTED.");
                return;
            }
            --attemptCounts;
        }
    } while (testMode != (char)CONSOLE && testMode != (char)LOG);

    for (int i = 0; i < testsCount; ++i) {

        fscanf(input, "%lf %lf %lf %d %lf %lf", &a, &b, &c, &condition, &bPart, &dPart);
        if (isnan(a) || isnan(b) || isnan(c) || isnan(bPart) || isnan(dPart) || condition == UNDEF) {
            printf("Wrong test format.");
            return;
        }

        struct QuadraticEquationSolutionStatus test = {NAN, NAN, UNDEF};
        test = solveQuadCase(a, b, c);
        if (testMode == (char)LOG) {

            if (!((compareDouble(test.bPart, bPart) == EQUAL) &&
                  (compareDouble(test.dPart, dPart) == EQUAL) &&
                  test.condition == condition)) {
                fprintf(output, "\t*===Test %d====*\n"
                                "\tWrong answer.\n"
                                "\tExpected: bPart = %lf, dPart = %lf, condition = %d\n"
                                "\tResult: bPart = %lf, dPart = %lf, condition = %d\n"
                                "\t*=============*\n\n",
                        i + 1, bPart, dPart, condition,
                        test.bPart, test.dPart, test.condition);
                return;
            }

            else {
                printf("\t*===Test %d====*\n"
                       "\t  Test passed!\n"
                       "\t*=============*\n\n", i + 1);
            }
        }
        else
        {
            if (!((compareDouble(test.bPart, bPart) == EQUAL) &&
                  (compareDouble(test.dPart, dPart) == EQUAL) &&
                  test.condition == condition)) {
                printf("\t*===Test %d====*\n"
                       "\tWrong answer.\n"
                       "\tExpected: bPart = %lf, dPart = %lf, condition = %d\n"
                       "\tResult: bPart = %lf, dPart = %lf, condition = %d\n"
                       "\t*=============*\n\n",
                        i + 1, bPart, dPart, condition,
                        test.bPart, test.dPart, test.condition);
                return;
            }

            else {
                printf("\t*===Test %d====*\n"
                       "\t  Test passed! \n"
                       "\t*=============*\n\n", i + 1);
            }
        }
    }
}

/*!
 * \brief Функция решения квадратного уравнения.
 * \author Ivan Pavlov
 * \date 26.08.2021
         A function of the console interface that provides interaction with the user
 *       and outputs the result of the program execution to the console.
 * \example commandLineInterface
*/
void solveQuadEquationInterface(){
    printf("\tHello, user! Please, choose program mode.\n "
           "\tType \"T\" for testing and \"E\" "
           "\tfor the program executing.\n");
    char mode = ' ';
    int attemptCounts = 5;
    do
    {
        scanf("%c", &mode);
        if (mode != (char)TESTING_MODE && mode != (char)EXECUTING_MODE) // char enum
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
    {
        struct QuadraticEquationSolutionStatus Equation = QuadEquationSolution();
        switch (Equation.condition) {
            case UNDEF:
                printf("Wrong input.");
                break;
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
}