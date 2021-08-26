#ifndef EQUATION_H
#define EQUATION_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EPS 1e-12 //машинный ноль
#define MAX_ATTEMPTS_COUNT 5
struct QuadraticEquationSolutionStatus
{
    double bCoefficientPart, discriminantPart;
    int condition;
};
//документация сюда, структура.
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

struct QuadraticEquationSolutionStatus solveLinearCase(const double a,const double b);

struct QuadraticEquationSolutionStatus solveQuadCase(const double a, const double b, const double c);

struct QuadraticEquationSolutionStatus quadEquationSolution();

int compareDouble(const double lhs, const double rhs);

void unitTest();

void clearBuffer();

void fileTestOutput(struct QuadraticEquationSolutionStatus test, double bPart, double dPart,
                    FILE* output,enum QUADRATIC_EQUATION_SOLUTION_CONDITION condition,int testNumber);

void consoleTestOutput (struct QuadraticEquationSolutionStatus test, double bPart, double dPart,
                        enum QUADRATIC_EQUATION_SOLUTION_CONDITION condition, int testNumber);

void solveQuadEquationCLI();

void printRoots(struct QuadraticEquationSolutionStatus Equations);
#endif //EQUATION_H`