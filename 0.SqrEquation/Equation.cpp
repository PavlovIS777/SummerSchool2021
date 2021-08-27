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
    struct QuadraticEquationSolutionStatus Equation = {NAN, NAN, NAN, NAN, UNDEF_ROOTS};

    if (isnan(a) || isnan(b) || isnan(c)) {
        Equation.condition = UNDEF_ROOTS;
        return Equation;
    }

    double disc = b * b - 4 * a * c;

    if (compareDouble(disc, 0.0) == EQUAL) {
        Equation.condition = LINEAR_EXISTS;
        Equation.firstRoot.Re = -b / (2.0 * a);
        Equation.firstRoot.Im = 0.0;
        Equation.secondRoot.Im = 0.0;
        Equation.secondRoot.Re = 0.0;
    } else if (compareDouble(disc, 0.0) == LESS) {
        disc *= -1;
        Equation.condition = COMPLEX;
        Equation.firstRoot.Im = sqrt(disc) / (2 * a);
        Equation.secondRoot.Im = sqrt(disc) / (2 * a);
        Equation.secondRoot.Re = Equation.firstRoot.Re = -(b) / (2 * a);
    } else {
        Equation.condition = RATIONAL;
        Equation.firstRoot.Re = ((-b) - sqrt(disc)) / (2 * a);
        Equation.firstRoot.Im = 0.0;
        Equation.secondRoot.Re = ((-b) + sqrt(disc)) / (2 * a);
        Equation.secondRoot.Im = 0.0;
    }

    return Equation;
}

void clearBuffer()
{
    char temp = 0;
    while((temp = fgetc(stdin)) != '\n');
}

struct LinearEquationSolutionStatus solveLinearCase(double a, double b)
{
    struct LinearEquationSolutionStatus Equation = {NAN, UNDEF_ROOTS};
    if ((compareDouble(a, 0.0) == EQUAL) &&
        (compareDouble(b, 0.0) == EQUAL)) {
        Equation.condition = INF;
        Equation.root = 0;

        return Equation;
    }

    if (compareDouble(a, 0.0) == EQUAL) {
        Equation.root = 0;
        Equation.condition = NON_EXISTENT;

        return Equation;
    } else {
        Equation.condition = LINEAR_EXISTS;
        Equation.root = -b / a;

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

void fileQuadTestOutput(struct QuadraticEquationSolutionStatus test, double firstRootRe, double firstRootIm,
                    double secondRootRe, double secondRootIm,
                    FILE* output, EQUATION_SOLUTION_CONDITION condition,int testNumber)
{
    if (!((compareDouble(test.firstRoot.Re, firstRootRe) == EQUAL)   &&
          (compareDouble(test.firstRoot.Im, firstRootIm) == EQUAL)   &&
          (compareDouble(test.secondRoot.Re, secondRootRe) == EQUAL) &&
          (compareDouble(test.secondRoot.Im, secondRootIm) == EQUAL) &&
          test.condition == condition)) {
        fprintf(output, "\t*===Test %d====*\n"
                        "\tWrong answer.\n"
                        "\tExpected: firstRootRe = %lf, firstRootIm = %lf, secondRootRe = %lf,"
                        "seconRootIm = %lf condition = %d\n"
                        "\tResult: firstRootRe = %lf, firstRootIm = %lf, secondRootRe = %lf,"
                        "seconRootIm = %lf condition = %d\n"
                        "\t*=============*\n\n",
                testNumber, firstRootRe, firstRootIm, secondRootRe, secondRootIm,  condition,
                test.firstRoot.Re, test.firstRoot.Im, test.secondRoot.Re,
                test.secondRoot.Im, test.condition);
        return;
    } else {
        fprintf(output, "\t*===Test %d====*\n"
                        "\t  Test passed!\n"
                        "\t*=============*\n\n", testNumber);
    }
}

void consoleQuadTestOutput(struct QuadraticEquationSolutionStatus test, double firstRootRe, double firstRootIm,
                    double secondRootRe, double secondRootIm,
                    EQUATION_SOLUTION_CONDITION condition,int testNumber)
{
    if (!((compareDouble(test.firstRoot.Re, firstRootRe) == EQUAL)   &&
          (compareDouble(test.firstRoot.Im, firstRootIm) == EQUAL)   &&
          (compareDouble(test.secondRoot.Re, secondRootRe) == EQUAL) &&
          (compareDouble(test.secondRoot.Im, secondRootIm) == EQUAL) &&
          test.condition == condition)) {
        printf("\t*===Test %d====*\n"
                "\tWrong answer.\n"
                "\tExpected: firstRootRe = %lf, firstRootIm = %lf, secondRootRe = %lf,"
                "seconRootIm = %lf condition = %d\n"
                "\tResult: firstRootRe = %lf, firstRootIm = %lf, secondRootRe = %lf,"
                "seconRootIm = %lf condition = %d\n"
                "\t*=============*\n\n",
                testNumber, firstRootRe, firstRootIm, secondRootRe, secondRootIm,  condition,
                test.firstRoot.Re, test.firstRoot.Im, test.secondRoot.Re,
                test.secondRoot.Im, test.condition);
        return;
    } else {
        printf("\t*===Test %d====*\n"
                "\t  Test passed!\n"
                "\t*=============*\n\n", testNumber);
    }
}
void fileLinearTestOutput(struct LinearEquationSolutionStatus test, FILE* output,
                          enum EQUATION_SOLUTION_CONDITION condition, double root, int testNumber)
{
    if(!(compareDouble(test.root, root) == EQUAL && test.condition == condition)) {
        fprintf(output, "\t*===Test %d====*\n"
                        "\tWrong answer.\n"
                        "\tExpected: root = %lf, condition = %d\n"
                        "\tResult: rational = %lf, condition = %d\n"
                        "\t*=============*\n\n", testNumber, root, condition, test.root, test.condition);
    } else {
        fprintf(output, "\t*===Test %d====*\n"
                        "\t  Test passed!\n"
                        "\t*=============*\n\n", testNumber);
    }
}

void consoleLinearTestOutput(struct LinearEquationSolutionStatus test,
                                EQUATION_SOLUTION_CONDITION condition, double root, int testNumber)
{
    if(!(compareDouble(test.root, root) == EQUAL && test.condition == condition)) {
        printf("\t*===Test %d====*\n"
               "\tWrong answer.\n"
               "\tExpected: root = %lf, condition = %d\n"
               "\tResult: rational = %lf, condition = %d\n"
               "\t*=============*\n\n", testNumber, root, condition, test.root, test.condition);
    } else {
        printf("\t*===Test %d====*\n"
               "\t  Test passed!\n"
               "\t*=============*\n\n", testNumber);
    }
}
void unitTest() {
    FILE *linearInput = NULL, *quadInput = NULL, *output = NULL;

    quadInput = fopen("quadInput.txt", "r");
    output = fopen("Log.txt", "a+");
    linearInput = fopen("linInput.txt", "r");

    if (linearInput == NULL) {
        printf("\tError reading linear input file.\n");
    }

    if (quadInput == NULL) {
        printf("\tError reading quad input file.\n");
    }

    if (output == NULL) {
        printf("\tError writing output file.\n");
    }

    double a = NAN, b = NAN, c = NAN;

    EQUATION_SOLUTION_CONDITION condition = UNDEF_ROOTS;
    MODE_OF_QUADRATIC_EQUATION_PROGRAM_TESTS testMode = UNDEF_MODE_TESTS;
    TESTING_DATA_INPUT_MODE inputMode = UNDEF_INPUT_DATA;

    int testsCount = 0, attemptCounts = MAX_ATTEMPTS_COUNT;

    struct QuadraticEquationSolutionStatus quadTest = {{NAN, NAN}, {NAN, NAN}, UNDEF_ROOTS};
    struct LinearEquationSolutionStatus linearTest = {NAN, UNDEF_ROOTS};
    printf("\tChoose tests output\n"
           "\tType \"1\" for console output mod or \"2\" for writing Log.txt file.\n");

    clearBuffer();

    do {
        scanf("%d", &testMode);
        if (testMode == UNDEF_MODE_TESTS) {
            fgetc(stdin);
            if (attemptCounts > 0)
                printf("\tType \"1\" or \"2\"\n");
            else {
                printf("\tMaximum number of attempts WASTED.");
                return;
            }
            --attemptCounts;
        }
    } while (testMode == UNDEF_MODE_TESTS);

    printf("\tChoose tests input\n"
           "\tType \"1\" for linear input mod or \"2\" for quad input mod.\n");

    clearBuffer();

    do {
        scanf("%d", &inputMode);
        if (inputMode == UNDEF_INPUT_DATA) {
            fgetc(stdin);
            if (attemptCounts > 0)
                printf("\tType \"1\" or \"2\"\n");
            else {
                printf("\tMaximum number of attempts WASTED.");
                return;
            }
            --attemptCounts;
        }
    } while (inputMode != LINEAR && inputMode != QUAD);
    
    clearBuffer();


    if (inputMode == QUAD) {
        fscanf(quadInput, "%d", &testsCount);
        double firsftRootRe = NAN, firsftRootIm = NAN, secondRootRe = NAN, secondRootIm = NAN;
        for (int i = 0; i < testsCount; ++i) {
            fscanf(quadInput, "%lf %lf %lf %d %lf %lf %lf %lf", &a, &b, &c, &condition, &firsftRootRe, &firsftRootIm,
                   &secondRootRe, &secondRootIm);

            if (isnan(a) || isnan(b) || isnan(c) || isnan(firsftRootRe) || isnan(firsftRootIm) || condition == UNDEF_ROOTS
                || isnan(secondRootRe) || isnan(secondRootIm)) {
                printf("\t**Wrong test format. Test #%d""**", i + 1);
                continue;
            }

            quadTest = solveQuadCase(a, b, c);

            switch (testMode) {
                case LOG:
                    fileQuadTestOutput(quadTest, firsftRootRe, firsftRootIm, secondRootRe, secondRootIm, output, 
                                        condition, i+1);
                    break;
                case CONSOLE:
                    consoleQuadTestOutput(quadTest, firsftRootRe, firsftRootIm, secondRootRe, secondRootIm, 
                                            condition, i+1);
                    break;
            }
        }
    } else {
        double root = NAN;
        a = 0;
        fscanf(linearInput, "%d", &testsCount);
        for (int k = 0; k < testsCount; ++k) {
            fscanf(linearInput, "%lf %lf %d %lf", &b, &c, &condition, &root);
            linearTest = solveLinearCase(b, c);
            switch (testMode) {
                case LOG:
                    fileLinearTestOutput(linearTest, output, condition, root, k + 1);
                    break;
                case CONSOLE:
                    consoleLinearTestOutput(linearTest, condition, root, k + 1);
                    break;
            }
        }
    }
}

void printRoots(struct QuadraticEquationSolutionStatus QuadEquation, struct LinearEquationSolutionStatus LinEquation)
{
    switch (QuadEquation.condition) {
        case UNDEF_ROOTS:
            break;
        case RATIONAL:
            printf("Roots are rational.\n"
                   "x1 = %lf and x2 = %lf""\n", QuadEquation.firstRoot.Re, QuadEquation.secondRoot.Re);
            break;
        case LINEAR_EXISTS:
            printf("Root is rational.\n"
                   "x = %lf""\n", QuadEquation.firstRoot.Re);
            break;
        case COMPLEX:
            printf("Roots are complex.\n"
                   "x1 = %lf - %lf""i and x2 = %lf + %lf""i""\n", QuadEquation.firstRoot.Re, QuadEquation.firstRoot.Im,
                   QuadEquation.secondRoot.Im, QuadEquation.secondRoot.Im);
            break;
    }
    switch (LinEquation.condition) {
        case INF:
            printf("x belongs R\n");
            break;
        case NON_EXISTENT:
            printf("There's no solution.\n");
            break;
        case LINEAR_EXISTS:
            printf("Root is rational.\n"
                   "x = %lf""\n", LinEquation.root);
    }
}

void solveQuadEquationCLI() {
    printf("\tHello, user! Please, choose program mode.\n "
           "\tType \"1\" for testing and \"2\" "
           "for the program executing.\n");
    enum MODE_OF_QUADRATIC_EQUATION_PROGRAM mode = UNDEF_MODE;
    int attemptCounts = MAX_ATTEMPTS_COUNT;
    do {
        scanf("%d", &mode);
        if (mode == UNDEF_MODE) {
            fgetc(stdin);
            if (attemptCounts > 0)
                printf("Type \"1\" for Testing mod and \"2\" for Executing.\n");
            else {
                printf("Maximum number of attempts WASTED.");
                return;
            }
            --attemptCounts;
        }
    } while (mode == UNDEF_MODE);

    if (mode == TESTING_MODE) {
        unitTest();
    } else {
        double a = NAN, b = NAN, c = NAN;
        getCoefficients(&a, &b, &c);
        struct QuadraticEquationSolutionStatus QuadEquation = {{NAN, NAN}, {NAN, NAN}, UNDEF_ROOTS};
        struct LinearEquationSolutionStatus LinEquation = {NAN, UNDEF_ROOTS};
        if (compareDouble(a, 0.0) == EQUAL){
            LinEquation = solveLinearCase(b, c);

        } else{
            QuadEquation = solveQuadCase(a, b, c);
        }
        printRoots(QuadEquation, LinEquation);
    }
}