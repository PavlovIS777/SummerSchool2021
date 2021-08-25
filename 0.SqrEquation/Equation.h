#ifndef EQUATION_H
#define EQUATION_H
#endif //EQUATION_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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
