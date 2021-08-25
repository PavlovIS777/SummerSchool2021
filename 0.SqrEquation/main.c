#include "Equation.h"

int main() {
    double a = NAN, b = NAN, c = NAN;
    //inputOutput(&a, &b, &c);
    double* arr = malloc(sizeof(double) * 3);
    arr[0] = 1;
    arr[1] = 2;
    arr[2]  = 1;
    testSys(arr, 3);
    return 0;
}
