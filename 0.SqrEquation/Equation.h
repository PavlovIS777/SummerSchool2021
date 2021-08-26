/*!
 * \file
 */
#ifndef EQUATION_H
#define EQUATION_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EPS 1e-12
#define MAX_ATTEMPTS_COUNT 5
struct QuadraticEquationSolutionStatus
{
    double bCoefficientPart, discriminantPart,
    firstRationalRoot, secondRationalRoot;
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

/*!
 * \brief Getting coefficients of the equation function.
 *        Function records the coefficients entered by the user, according to the pointer.
 * \returns void
 * \example getCoefficients(a, b, c)
*/
void getCoefficients(double* a, double* b, double* c);

/*!
 * \brief A Linear case function.
 *        A function that records the solutions of equations and the state of the roots
 *       the QuadraticEquationSolutionStatus structure in the linear case.
 * \returns struct with Linear Equation statement and value.
 * \example solveLinearCase(3.4, 4.1)
*/
struct QuadraticEquationSolutionStatus solveLinearCase(const double a,const double b);

/*!
 * \brief A Quadratic case function.
 *        A function that records the solutions of equations and the state of the roots
 *       the QuadraticEquationSolutionStatus structure in the linear case.
 * \returns struct with Quadratic Equation statement and parts of values.
 * \example solveQuadCase(3.4, 4.1, 5.8)
*/
struct QuadraticEquationSolutionStatus solveQuadCase(const double a, const double b, const double c);

/*!
 * \brief struct Function of Quadratic Equation coefficients.
         The function creates variables and a structure in which the coefficients
 *       of the equation, the solution and the state of the roots are written, respectively.
 * \returns struct with Quadratic or Linear Equation coefficients
 * \example QuadEquationSolution()
*/
struct QuadraticEquationSolutionStatus quadEquationSolution();

/*!
 * \brief Double compare function.
 *        Comparison of numbers of the double type.
 * \returns the enum value from DOUBLE_COMPARE_STATUS.
 * \example compareDouble(3.4, 4.1)
*/
int compareDouble(const double lhs, const double rhs);

/*!
 * \brief unitTest function.
 *        A function of the console interface that provides interaction with the user
 *       and outputs the result of the program execution to the console.
 * \returns void
 * \example uniTest()
*/
void unitTest();

/*!
 * \brief Cleaning scanf() buffer.
 *        Function that clears the scanf() buffer.
 * \returns void
 * \example clearBuffer()
*/
void clearBuffer();

/*!
 * \brief Test result output into file.
 *        A function of the console interface that provides
 *        outputs the result test proving to the file.
 * \returns void
 * \example fileTestOutput()
*/
void fileTestOutput(struct QuadraticEquationSolutionStatus test, double bPart, double dPart,
                    double firstRational, double secondRational,
                    FILE* output,enum QUADRATIC_EQUATION_SOLUTION_CONDITION condition,int testNumber);

/*!
 * \brief Test result output into console.
 *        A function of the console interface that provides
 *        outputs the result test proving to the console.
 * \returns void
 * \example consoleTestOutput()
*/
void consoleTestOutput (struct QuadraticEquationSolutionStatus test, double bPart, double dPart,
                        double firstRational, double secondRational,
                        enum QUADRATIC_EQUATION_SOLUTION_CONDITION condition, int testNumber);

/*!
 * \brief Function of solving quadratic equation.
 * \author Ivan Pavlov
 * \date 26.08.2021
         A function of the console interface that provides interaction with the user
 *       and outputs the result of the program execution to the console.
 * \returns void
 * \example solveQuadEquation()
*/
void solveQuadEquationCLI();

/*!
 * \brief print Roots function.
 *        Function prints roots in console.
 * \returns void
 * \example printRoots(struct QuadraticEquationSolutionStatus Equation)
*/
void printRoots(struct QuadraticEquationSolutionStatus Equations);
#endif //EQUATION_H`