#ifndef EQUATION_H
#define EQUATION_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EPS 1e-12
#define MAX_ATTEMPTS_COUNT 5
struct QuadraticEquationSolutionStatus
{
    double bCoefficientPart, discriminantPart;
    int condition;
};

enum QUADRATIC_EQUATION_SOLUTION_CONDITION
{
    UNDEF = -1    ,
    COMPLEX       ,
    RATIONAL      ,
    LINEAR_EXISTS ,
    INF           ,
    NON_EXISTENT
};

enum MODE_OF_QUADRATIC_EQUATION_PROGRAM
{
    TESTING_MODE = 1  ,
    EXECUTING_MODE
};

enum MODE_OF_QUADRATIC_EQUATION_PROGRAM_TESTS
{
    CONSOLE = 1 ,
    LOG
};

enum DOUBLE_COMPARE_STATUS
{
    EQUAL = 0   ,
    GREATER     ,
    LESS

};

void getCoefficients(double* a, double* b, double* c);

struct QuadraticEquationSolutionStatus solveLinearCase(double a, double b);

struct QuadraticEquationSolutionStatus solveQuadCase(double a, double b, double c);

struct QuadraticEquationSolutionStatus quadEquationSolution();

int compareDouble(double one, double two);

void unitTest();

void clearBuffer();

void fileTestOutput(struct QuadraticEquationSolutionStatus test, double bPart, double dPart,
                    FILE* output,enum QUADRATIC_EQUATION_SOLUTION_CONDITION condition,int testNumber);

void consoleTestOutput (struct QuadraticEquationSolutionStatus test, double bPart, double dPart,
                        enum QUADRATIC_EQUATION_SOLUTION_CONDITION condition, int testNumber);

void solveQuadEquation();
#endif //EQUATION_H`