#ifndef MAIN_C_EQUATION_H
#define MAIN_C_EQUATION_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#endif //MAIN_C_EQUATION_H
struct Equation;

enum condition;

void getCoefficients(double* a, double* b, double* c);

void Solve(double a, double b, double c, struct Equation* Equation);

void solveLin(double a, double b, struct Equation* Equation);

void solveSqr(double a, double b, double c, struct Equation* Equation);

void QuadEquationCLI(double* a, double* b, double* c);

int isEqualDouble(double one, double two);

void testSys();

void greeting(double* a, double* b, double* c);