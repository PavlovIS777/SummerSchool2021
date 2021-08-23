#include "test_system.h"
enum condition {complex, rational, linearExist, infinite, nonExistent};
struct EqRoots{
    double bPart, dPart;
    int condition;
};

void testingFu(void)
{
    double a, b, c;
    FILE* input = NULL;
    FILE* output;
    input = fopen("testInput.txt", "r");
    output = fopen("Log.txt", "w");

    while (fscanf(input, "%lf%lf%lf", &a, &b, &c) != EOF)
    {
        struct EqRoots* tests = malloc(sizeof(struct EqRoots));
        sqrSolution(&a, &b, &c, tests);
        double rationalPart;
        double rationalPartMinus;
        double complexPartPlus;
        double complexPartMinus;
        switch (tests->condition) {
            case complex:
                rationalPart = (a)*(tests->bPart*tests->bPart - tests->dPart*tests->dPart)+(b)*(tests->bPart)+(c);
                complexPartPlus = (a)*(tests->bPart*tests->dPart*2)+(b)*(tests->dPart);
                complexPartMinus = (a)*(-tests->bPart*tests->dPart*2)+(b)*(-tests->dPart);
                if (equalToZero(&rationalPart) && equalToZero(&complexPartMinus) && equalToZero(&complexPartPlus))
                {
                    fprintf(output, "success test\n");
                }
                else
                {
                    fprintf(output, "error test\n");
                }
                break;
            case rational:
                 rationalPart = a*(tests->dPart+tests->bPart)*(tests->bPart+tests->dPart) + b*(tests->bPart+tests->dPart) + c;
                 rationalPartMinus = a*(tests->bPart - tests->dPart)*(tests->bPart - tests->dPart) + b*(tests->bPart - tests->dPart) + c;
                 if (equalToZero(&rationalPart) && equalToZero(&rationalPartMinus))
                 {
                     fprintf(output, "success test\n");
                 }
                 else
                 {
                     fprintf(output, "error test\n");
                 }
                break;
            case linearExist:
                rationalPart = a*(tests->bPart)*(tests->bPart) + b * (tests->bPart) + c;
                if(equalToZero(&rationalPart))
                {
                    fprintf(output, "success test\n");
                }
                else
                {
                    fprintf(output, "error test\n");
                }
        }
    }
}