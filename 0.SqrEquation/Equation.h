#ifndef MAIN_C_EQUATION_H
#define MAIN_C_EQUATION_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#endif //MAIN_C_EQUATION_H
struct Equation;

enum condition;

void getCoefficients(double* a, double* b, double* c);

void Solve(double *a, double *b, double *c, struct Equation* Equation);

struct Equation solveLin(double *a, double *b, struct Equation* Equation);

struct Equation solveSqr(double* a, double* b, double* c, struct Equation* Equation);

void inputOutput(double *a, double *b, double *c);

int isEqualToZero(double *d);

void checkTest(struct Equation* test, double a, double b, double c);

void testSys(double* testArr, size_t testsCount);