#include <stdio.h>

double binRoot(double d){
    double start = 0;
    double end = d;
    double mid = (end + start) / 2;
    const double precision = 1e-9;

    while (end - start > precision){
        if (mid * mid > d){
            end = mid;
            mid = (end + start) / 2;
        } else {
            start = mid;
            mid = (end + start) / 2;
        }
    }
    return mid;
}
int main() {
    double a = 0, b = 0, c = 0, d;
    _Bool real = 1;
    printf("Hello, user! Please, enter the coef\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    //printf("%lf %lf %lf", a, b, c);
    d = b*b - 4*a*c;
    if (d < 0){
        real = 0;
        printf("Roots are complex!\n");
        d = -d;
    } else {
        printf("Roots are real!\n");
    }
    d = binRoot(d);
    if (real){
        double x1 = (-b - d)/(2 * a);
        double x2 = (-b + d)/(2 * a);
        if (x1 != x2)
            printf("Real Roots: x1 = %lf and x2 = %lf", x1, x2);
        else
            printf("Real Root: x = %lf", x1);
    } else {
        printf("Complex Roots: x1 = %lf - %lf" "i and x2 = %lf + %lf" "i", -b/(2 * a), d/(2 * a), -b/(2 * a), d/(2 * a));
    }
    getchar();
    return 0;
}
