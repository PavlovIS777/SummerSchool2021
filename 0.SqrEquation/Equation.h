#ifndef MAIN_C_EQUATION_H
#define MAIN_C_EQUATION_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#endif //MAIN_C_EQUATION_H
struct EqRoots;

int greeting(void);

int getNumbersSqr(double *a, double *b, double *c);

int getNumbersLin(double *a, double *b);

void sqrSolution(double *a, double *b, double *c, struct EqRoots* roots);

void LinSolution(double *a, double *b, struct EqRoots* roots);

void interface(double *a, double *b, double *c);

