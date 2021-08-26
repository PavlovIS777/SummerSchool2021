#ifndef EQUATION_H
#define EQUATION_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct QuadraticEquationSolutionStatus
{
    double bPart, dPart;
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
    TESTING_MODE = 'T'  ,
    EXECUTING_MODE = 'E'
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

struct QuadraticEquationSolutionStatus QuadEquationSolution();

int compareDouble(double one, double two);

void unitTest();

void commandLineInterface();

#endif //EQUATION_H`