/*!
 * \file
 */

#include "Equation.h"

/*!
 * \brief Double compare function.
 *        Comparison of numbers of the double type.
 * \returns the enum value from DOUBLE_COMPARE_STATUS.
 * \example compareDouble(3.4, 4.1)
*/
int compareDouble(double lhs, double rhs)
{
    if (fabs(lhs - rhs)  < EPS) {
        return EQUAL;
    } else if (lhs < rhs) {
        return LESS;
    } else {
        return GREATER;
    }
}

/*!
 * \brief A Quadratic case function.
 *        A function that records the solutions of equations and the state of the roots
 *       the QuadraticEquationSolutionStatus structure in the linear case.
 * \returns struct with Quadratic Equation statement and parts of values.
 * \example solveQuadCase(3.4, 4.1, 5.8)
*/
struct QuadraticEquationSolutionStatus solveQuadCase(double a, double b, double c)
{
    struct QuadraticEquationSolutionStatus Equation = {NAN, NAN, UNDEF};

    if (isnan(a) || isnan(b) || isnan(c)) {
        Equation.condition = UNDEF;
        return Equation;
    }

    if (compareDouble(a, 0.0) == EQUAL) {
        return solveLinearCase(b, c);
    }

    double disc = b * b - 4 * a * c;
    Equation.bCoefficientPart = -(b)/ (2 * a);

    if (compareDouble(disc, 0.0) == EQUAL) {
        Equation.condition = LINEAR_EXISTS;
        Equation.discriminantPart = 0;

        return Equation;
    }

    double disc_sqrt = NAN;

    if (disc < 0) {
        disc *= -1;
        Equation.condition = COMPLEX;
    } else {
        Equation.condition = RATIONAL;
    }

    disc_sqrt = sqrt(disc);
    Equation.discriminantPart = disc_sqrt/(2 * a);

    return Equation;
}
/*!
 * \brief Функция решения квадратного уравнения.
 *        Function that clears the scanf() buffer.
 * \returns void
 * \example clearBuffer()
*/
void clearBuffer()
{
    char temp = 0;
    while((temp = fgetc(stdin)) != '\n');
}

/*!
 * \brief A Linear case function.
 *        A function that records the solutions of equations and the state of the roots
 *       the QuadraticEquationSolutionStatus structure in the linear case.
 * \returns struct with Linear Equation statement and value.
 * \example solveLinearCase(3.4, 4.1)
*/
struct QuadraticEquationSolutionStatus solveLinearCase(double a, double b)
{
    struct QuadraticEquationSolutionStatus Equation = {NAN, NAN, UNDEF};
    Equation.discriminantPart = 0;
    if ((compareDouble(a, 0.0) == EQUAL) &&
        (compareDouble(b, 0.0) == EQUAL)) {
        Equation.condition = INF;
        Equation.bCoefficientPart = 0;

        return Equation;
    }

    if (compareDouble(a, 0.0) == EQUAL) {
        Equation.bCoefficientPart = 0;
        Equation.condition = NON_EXISTENT;

        return Equation;
    } else {
        Equation.condition = LINEAR_EXISTS;
        Equation.bCoefficientPart = -b / a;

        return Equation;
    }
}

/*!
 * \brief Getting coefficients of the equation function.
 *        Function records the coefficients entered by the user, according to the pointer.
 * \returns void
 * \example getCoefficients(a, b, c)
*/
void getCoefficients(double* a, double* b, double* c)
{
    printf("\tPlease, enter the coefficients.\n"
           "\tExample: For equation x^2 + 2.1x + 1 = 0\n"
           "\tWrite: 1 2.1 1\n");
    int attemptsCount = MAX_ATTEMPTS_COUNT;
    while(scanf("%lf %lf %lf", a, b, c) != 3) {
        --attemptsCount;
        if (attemptsCount == 0) {
            printf("\tMaximum number of attempts WASTED.");

            return;
        }

        clearBuffer();
        printf ("\tWrong input, try again.\n");
    }
}

/*!
 * \brief struct Function of Quadratic Equation coefficients.
         The function creates variables and a structure in which the coefficients
 *       of the equation, the solution and the state of the roots are written, respectively.
 * \returns struct with Quadratic or Linear Equation coefficients
 * \example QuadEquationSolution()
*/
struct QuadraticEquationSolutionStatus  quadEquationSolution()
{
    double a = NAN, b = NAN, c = NAN;
    getCoefficients(&a, &b, &c);

    struct QuadraticEquationSolutionStatus Equation = {NAN, NAN, UNDEF};
    Equation = solveQuadCase(a, b, c);
    return Equation;
}

/*!
 * \brief Test result output into file.
 *        A function of the console interface that provides
 *        outputs the result test proving to the file.
 * \returns void
 * \example fileTestOutput()
*/
void fileTestOutput(struct QuadraticEquationSolutionStatus test, double bPart, double dPart,
                    FILE* output,enum QUADRATIC_EQUATION_SOLUTION_CONDITION condition,int testNumber)
{
    if (!((compareDouble(test.bCoefficientPart, bPart) == EQUAL) &&
          (compareDouble(test.discriminantPart, dPart) == EQUAL) &&
          test.condition == condition)) {
        fprintf(output, "\t*===Test %d====*\n"
                        "\tWrong answer.\n"
                        "\tExpected: bPart = %lf, dPart = %lf, condition = %d\n"
                        "\tResult: bPart = %lf, dPart = %lf, condition = %d\n"
                        "\t*=============*\n\n",
                testNumber, bPart, dPart, condition,
                test.bCoefficientPart, test.discriminantPart, test.condition);
        return;
    } else {
        fprintf(output, "\t*===Test %d====*\n"
                        "\t  Test passed!\n"
                        "\t*=============*\n\n", testNumber);
    }
}

/*!
 * \brief Test result output into console.
 *        A function of the console interface that provides
 *        outputs the result test proving to the console.
 * \returns void
 * \example consoleTestOutput()
*/
void consoleTestOutput(struct QuadraticEquationSolutionStatus test, double bPart, double dPart,
                       enum QUADRATIC_EQUATION_SOLUTION_CONDITION condition, int testNumber) {
    if (!((compareDouble(test.bCoefficientPart, bPart) == EQUAL) &&
          (compareDouble(test.discriminantPart, dPart) == EQUAL) &&
          test.condition == condition)) {
        printf("\t*===Test %d====*\n"
               "\tWrong answer.\n"
               "\tExpected: bPart = %lf, dPart = %lf, condition = %d\n"
               "\tResult: bPart = %lf, dPart = %lf, condition = %d\n"
               "\t*=============*\n\n",
               testNumber, bPart, dPart, condition,
               test.bCoefficientPart, test.discriminantPart, test.condition);
        return;
    } else {
        printf("\t*===Test %d====*\n"
               "\t  Test passed! \n"
               "\t*=============*\n\n", testNumber);
    }
}

/*!
 * \brief unitTest function.
 *        A function of the console interface that provides interaction with the user
 *       and outputs the result of the program execution to the console.
 * \returns void
 * \example uniTest()
*/
void unitTest()
{
    FILE *input, *output = NULL;

    input = fopen("testInput.txt", "r");
    output = fopen("Log.txt", "w");

    if (input == NULL) {
        printf("\tError reading input file.");
        return;
    }

    if (output == NULL) {
        printf("\tError writing output file.");
        return;
    }

    double a = NAN, b = NAN, c = NAN, bPart = NAN, dPart = NAN;
    enum QUADRATIC_EQUATION_SOLUTION_CONDITION condition = UNDEF;
    enum MODE_OF_QUADRATIC_EQUATION_PROGRAM_TESTS testMode = -1;
    int testsCount = 0, attemptCounts = MAX_ATTEMPTS_COUNT;;
    struct QuadraticEquationSolutionStatus test = {NAN, NAN, UNDEF};

    fscanf(input, "%d", &testsCount);
    printf("\tChoose tests output\n"
           "\tType \"1\" for console output mod or \"2\" for writing Log.txt file.\n");

    clearBuffer();

    do {
        scanf("%d", &testMode);
        if (testMode != CONSOLE && testMode != LOG) {
            fgetc(stdin);
            if (attemptCounts > 0)
                printf("\tType \"1\" or \"2\"\n");
            else {
                printf("\tMaximum number of attempts WASTED.");
                return;
            }
            --attemptCounts;
        }
    } while (testMode != CONSOLE && testMode != LOG);

    for (int i = 0; i < testsCount; ++i) {
        fscanf(input, "%lf %lf %lf %d %lf %lf", &a, &b, &c, &condition, &bPart, &dPart);

        if (isnan(a) || isnan(b) || isnan(c) || isnan(bPart) || isnan(dPart) || condition == UNDEF) {
            printf("\t**Wrong test format. Test #%d""**", i + 1);
            continue;
        }

        test = solveQuadCase(a, b, c);

        switch (testMode) {
            case LOG:
                fileTestOutput(test, bPart, dPart, output, condition, i + 1);
                break;
            case CONSOLE:
                consoleTestOutput(test, bPart, dPart, condition, i + 1);
                break;
        }
    }
}
/*!
 * \brief print Roots function.
 *        Function prints roots in console.
 * \returns void
 * \example printRoots(struct QuadraticEquationSolutionStatus Equation)
*/
void printRoots(struct QuadraticEquationSolutionStatus Equation)
{
    switch (Equation.condition) {
        case UNDEF:
            printf("Wrong input.");
            break;
        case RATIONAL:
            printf("Roots are rational.\n"
                   "x1 = %lf and x2 = %lf", Equation.bCoefficientPart - Equation.discriminantPart,
                   Equation.bCoefficientPart + Equation.discriminantPart);
            break;
        case LINEAR_EXISTS:
            printf("Root is rational.\n"
                   "x = %lf", Equation.bCoefficientPart);
            break;
        case COMPLEX:
            printf("Roots are complex.\n"
                   "x1 = %lf - %lf""i and x2 = %lf + %lf""i",
                   Equation.bCoefficientPart, Equation.discriminantPart, Equation.bCoefficientPart,
                   Equation.discriminantPart);
            break;
        case INF:
            printf("x belongs R");
            break;
        case NON_EXISTENT:
            printf("There's no solution.");
            break;
    }
}

/*!
 * \brief Function of solving quadratic equation.
 * \author Ivan Pavlov
 * \date 26.08.2021
         A function of the console interface that provides interaction with the user
 *       and outputs the result of the program execution to the console.
 * \returns void
 * \example solveQuadEquation()
*/
void solveQuadEquationCLI() {
    printf("\tHello, user! Please, choose program mode.\n "
           "\tType \"1\" for testing and \"2\" "
           "for the program executing.\n");
    enum MODE_OF_QUADRATIC_EQUATION_PROGRAM mode = -1;
    int attemptCounts = MAX_ATTEMPTS_COUNT;
    do {
        scanf("%d", &mode);
        if (mode != TESTING_MODE && mode != EXECUTING_MODE) {
            fgetc(stdin);
            if (attemptCounts > 0)
                printf("Type \"1\" for Testing mod and \"2\" for Executing.\n");
            else {
                printf("Maximum number of attempts WASTED.");
                return;
            }
            --attemptCounts;
        }
    } while (mode != EXECUTING_MODE && mode != TESTING_MODE);

    if (mode == TESTING_MODE) {
        unitTest();
    } else {
        struct QuadraticEquationSolutionStatus Equation = quadEquationSolution();
        printRoots(Equation);
    }
}