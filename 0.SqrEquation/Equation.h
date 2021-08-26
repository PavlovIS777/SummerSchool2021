#ifndef EQUATION_H
#define EQUATION_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct EquationSolutionStatus
{
    double bPart, dPart;
    int condition;
};

enum CONDITION
{
    UNDEF = -1    ,
    COMPLEX       ,
    RATIONAL      ,
    LINEAR_EXISTS ,
    INF           ,
    NON_EXISTENT
};

enum MODE
{
    TESTING_MODE = 'T'  ,
    EXECUTING_MODE = 'E'
};

enum DOUBLE_COMPARE
{
    NON_EQUAL = 0 ,
    EQUAL = 1
};

void getCoefficients(double* a, double* b, double* c);

struct EquationSolutionStatus solveLinearCase(double a, double b);

struct EquationSolutionStatus solveQuadCase(double a, double b, double c);

void QuadEquationSolution();

int isEqualDouble(double one, double two);

void unitTest();

void commandLineInterface();

#endif //EQUATION_H`