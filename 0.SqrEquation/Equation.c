#include "Equation.h"

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

    if (compareDouble(disc, 0.0) == EQUAL) {
        Equation.condition = LINEAR_EXISTS;
        Equation.discriminantPart = 0;
        Equation.bCoefficientPart = 0;
        Equation.firstRationalRoot = (-b) / (2 * a);
        Equation.secondRationalRoot = 0;
    } else if (compareDouble(disc, 0 ) == LESS) {
        disc *= -1;
        Equation.condition = COMPLEX;
        Equation.discriminantPart = sqrt(disc) / (2 * a);
        Equation.bCoefficientPart = -(b) / (2 * a);
        Equation.firstRationalRoot = 0;
        Equation.secondRationalRoot = 0;
    } else {
        Equation.condition = RATIONAL;
        Equation.firstRationalRoot = ((-b) - sqrt(disc)) / (2 * a);
        Equation.secondRationalRoot = ((-b) + sqrt(disc)) / (2 * a);
        Equation.discriminantPart = 0;
        Equation.bCoefficientPart = 0;
    }

    return Equation;
}

void clearBuffer()
{
    char temp = 0;
    while((temp = fgetc(stdin)) != '\n');
}

struct QuadraticEquationSolutionStatus solveLinearCase(double a, double b)
{
    struct QuadraticEquationSolutionStatus Equation = {NAN, NAN, UNDEF};
    Equation.discriminantPart = 0;
    Equation.bCoefficientPart = 0;
    if ((compareDouble(a, 0.0) == EQUAL) &&
        (compareDouble(b, 0.0) == EQUAL)) {
        Equation.condition = INF;
        Equation.firstRationalRoot = 0;
        Equation.secondRationalRoot = 0;

        return Equation;
    }

    if (compareDouble(a, 0.0) == EQUAL) {
        Equation.firstRationalRoot = 0;
        Equation.secondRationalRoot = 0;
        Equation.condition = NON_EXISTENT;

        return Equation;
    } else {
        Equation.condition = LINEAR_EXISTS;
        Equation.firstRationalRoot = -b / a;
        Equation.secondRationalRoot = 0;

        return Equation;
    }
}

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

struct QuadraticEquationSolutionStatus  quadEquationSolution()
{
    double a = NAN, b = NAN, c = NAN;
    getCoefficients(&a, &b, &c);

    struct QuadraticEquationSolutionStatus Equation = {NAN, NAN, UNDEF};
    Equation = solveQuadCase(a, b, c);
    return Equation;
}

void fileTestOutput(struct QuadraticEquationSolutionStatus test, double bPart, double dPart,
                    double firstRational, double secondRational,
                    FILE* output,enum QUADRATIC_EQUATION_SOLUTION_CONDITION condition,int testNumber)
{
    if (!((compareDouble(test.bCoefficientPart, bPart) == EQUAL) &&
          (compareDouble(test.discriminantPart, dPart) == EQUAL) &&
          test.condition == condition)) {
        fprintf(output, "\t*===Test %d====*\n"
                        "\tWrong answer.\n"
                        "\tExpected: rational(complex) = %lf, Complex disc = %lf, rationalRoot_1 = %lf,"
                        "rationalRoot_2 = %lf condition = %d\n"
                        "\tResult: rational(complex) = %lf, Complex disc = %lf, rationalRoot_1 = %lf,"
                        "rationalRoot_2 = %lf condition = %d\n"
                        "\t*=============*\n\n",
                testNumber, bPart, dPart, firstRational, secondRational,  condition,
                test.bCoefficientPart, test.discriminantPart, test.firstRationalRoot,
                test.secondRationalRoot, test.condition);
        return;
    } else {
        fprintf(output, "\t*===Test %d====*\n"
                        "\t  Test passed!\n"
                        "\t*=============*\n\n", testNumber);
    }
}

void consoleTestOutput(struct QuadraticEquationSolutionStatus test, double bPart, double dPart,
                       double firstRational, double secondRational,
                       enum QUADRATIC_EQUATION_SOLUTION_CONDITION condition, int testNumber) {
    if (!((compareDouble(test.bCoefficientPart, bPart) == EQUAL) &&
          (compareDouble(test.discriminantPart, dPart) == EQUAL) &&
          test.condition == condition && compareDouble(test.firstRationalRoot, firstRational)
           && compareDouble(test.secondRationalRoot, secondRational))) {
        printf("\t*===Test %d====*\n"
               "\tWrong answer.\n"
               "\tExpected: rational(complex) = %lf, Complex disc = %lf, rationalRoot_1 = %lf,"
               "rationalRoot_2 = %lf condition = %d\n"
               "\tResult: rational(complex) = %lf, Complex disc = %lf, rationalRoot_1 = %lf,"
               "rationalRoot_2 = %lf condition = %d\n"
               "\t*=============*\n\n",
               testNumber, bPart, dPart, firstRational, secondRational, condition,
               test.bCoefficientPart, test.discriminantPart, test.firstRationalRoot,
               test.secondRationalRoot, test.condition);
        return;
    } else {
        printf("\t*===Test %d====*\n"
               "\t  Test passed! \n"
               "\t*=============*\n\n", testNumber);
    }
}


void unitTest()
{
    FILE *input, *output = NULL;

    input = fopen("Input.txt", "r");
    output = fopen("Log.txt", "w");

    if (input == NULL) {
        printf("\tError reading input file.");
        return;
    }

    if (output == NULL) {
        printf("\tError writing output file.");
        return;
    }

    double a = NAN, b = NAN, c = NAN, bPart = NAN, dPart = NAN, firstRational = NAN, secondRational = NAN;
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
        fscanf(input, "%lf %lf %lf %d %lf %lf %lf %lf", &a, &b, &c, &condition, &bPart, &dPart,
               &firstRational, &secondRational);

        if (isnan(a) || isnan(b) || isnan(c) || isnan(bPart) || isnan(dPart) || condition == UNDEF
            || isnan(firstRational) || isnan(secondRational)) {
            printf("\t**Wrong test format. Test #%d""**", i + 1);
            continue;
        }

        test = solveQuadCase(a, b, c);

        switch (testMode) {
            case LOG:
                fileTestOutput(test, bPart, dPart, firstRational, secondRational, output, condition, i + 1);
                break;
            case CONSOLE:
                consoleTestOutput(test, bPart, dPart, firstRational, secondRational, condition, i + 1);
                break;
        }
    }
}

void printRoots(struct QuadraticEquationSolutionStatus Equation)
{
    switch (Equation.condition) {
        case UNDEF:
            printf("Wrong input.");
            break;
        case RATIONAL:
            printf("Roots are rational.\n"
                   "x1 = %lf and x2 = %lf", Equation.firstRationalRoot, Equation.secondRationalRoot);
            break;
        case LINEAR_EXISTS:
            printf("Root is rational.\n"
                   "x = %lf", Equation.firstRationalRoot);
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