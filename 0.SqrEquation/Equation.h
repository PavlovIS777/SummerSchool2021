/*!
 * \file
 */
#ifndef EQUATION_H
#define EQUATION_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EPS 2e-16
#define MAX_ATTEMPTS_COUNT 5
#define TEST_PASSED "\t*===Test %d====*\n"\
                    "\t  Test passed!\n"\
                    "\t*=============*\n\n", testNumber
#define WRONG_TEST_ANSWER_LINEAR "\t*===Test %d====*\n"                          \
                               "\tWrong answer.\n"                             \
                               "\tExpected: root = %lf, condition = %d\n"      \
                               "\tResult: rational = %lf, condition = %d\n"    \
                               "\t*=============*\n\n", testNumber, root, condition, test.root, test.condition
#define WRONG_TEST_ANSWER_QUAD  "\t*===Test %d====*\n" \
                                "\tWrong answer.\n"                                                          \
                                "\tExpected: firstRootRe = %lf, firstRootIm = %lf, secondRootRe = %lf,"      \
                                "seconRootIm = %lf condition = %d\n"                                         \
                                "\tResult: firstRootRe = %lf, firstRootIm = %lf, secondRootRe = %lf,"        \
                                "seconRootIm = %lf condition = %d\n"                                         \
                                "\t*=============*\n\n",                                                     \
                                testNumber, firstRootRe, firstRootIm, secondRootRe, secondRootIm,  condition,\
                                test.firstRoot.Re, test.firstRoot.Im, test.secondRoot.Re,                    \
                                test.secondRoot.Im, test.condition

/*!
 * \brief struct for saving roots in general.
*/
struct ComplexRoots
{
    double Re, Im;
};

/*!
 * \brief Equation mod.
 *        Roots condition.
*/
enum EQUATION_SOLUTION_CONDITION
{
    UNDEF_ROOTS = -1    ,
    COMPLEX             ,
    RATIONAL            ,
    LINEAR_EXISTS       ,
    INF                 ,
    NON_EXISTENT
};

/*!
 * \brief struct for solving linear case.
*/
struct LinearEquationSolutionStatus
{
    double root = NAN;
    EQUATION_SOLUTION_CONDITION condition;
};

/*!
 * \brief struct for solving quadratic case.
*/
struct QuadraticEquationSolutionStatus
{
    struct ComplexRoots firstRoot = {NAN, NAN}, secondRoot = {NAN, NAN};
    EQUATION_SOLUTION_CONDITION condition;
};

/*!
 * \brief Equation mod.
 *        Status of the mod, that's executing solution of the equation or providing tests.
*/
enum MODE_OF_QUADRATIC_EQUATION_PROGRAM
{
    UNDEF_MODE      ,
    TESTING_MODE    ,
    EXECUTING_MODE
};

/*!
 * \brief output mod.
 *        Status of output mod.
*/
enum MODE_OF_QUADRATIC_EQUATION_PROGRAM_TESTS
{
    UNDEF_MODE_TESTS    ,
    CONSOLE             ,
    LOG
};

/*!
 * \brief input mode.
 *        Status of input file for test-system.
*/
enum TESTING_DATA_INPUT_MODE{
    UNDEF_INPUT_DATA    ,
    LINEAR              ,
    QUAD
};

/*!
 * \brief compare status.
 *        Status of comparing two double numbers.
*/
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
struct LinearEquationSolutionStatus solveLinearCase(const double a,const double b);

/*!
 * \brief A Quadratic case function.
 *        A function that records the solutions of equations and the state of the roots
 *       the QuadraticEquationSolutionStatus structure in the linear case.
 * \returns struct with Quadratic Equation statement and parts of values.
 * \example solveQuadCase(3.4, 4.1, 5.8)
*/
struct QuadraticEquationSolutionStatus solveQuadCase(const double a, const double b, const double c);

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
 * \brief Test result of quadratic case outputs into the file.
 *        A function of the console interface that provides
 *        outputs the result of quadratic case test proving to the file.
 * \returns void
 * \example fileQuadTestOutput()
*/
void fileQuadTestOutput(struct QuadraticEquationSolutionStatus test, double firstRootRe, double firstRootIm,
                    double secondRootRe, double secondRootIm,
                    FILE* output, EQUATION_SOLUTION_CONDITION condition,int testNumber);

/*!
 * \brief Test result of quadratic case outputs into console.
 *        A function of the console interface that provides
 *        outputs the result of quadratic case test proving to the console.
 * \returns void
 * \example consoleQuadTestOutput()
*/
void consoleQuadTestOutput (struct QuadraticEquationSolutionStatus test, double firstRootRe, double firstRootIm,
                    double secondRootRe, double secondRootIm,
                    EQUATION_SOLUTION_CONDITION condition,int testNumber);

/*!
 * \brief Function of solving quadratic equation.
 * \author Ivan Pavlov
 * \date 26.08.2021
         A function of the console interface that provides interaction with the user
 *       and outputs the result of the program execution to the console.
 * \returns void
 * \example solveQuadEquationCLI()
*/
void solveQuadEquationCLI();

/*!
 * \brief print Roots function.
 *        Function prints roots in console.
 * \returns void
 * \example printRoots(struct QuadraticEquationSolutionStatus Equation)
*/
void printRoots(struct QuadraticEquationSolutionStatus Equations,
                struct LinearEquationSolutionStatus LinEquation);

/*!
 * \brief Test result of linear case outputs into the file.
 *        A function of the console interface that provides
 *        outputs the result of linear case test proving to the file.
 * \returns void
 * \example fileLinearTestOutput()
*/
void fileLinearTestOutput(struct LinearEquationSolutionStatus test, FILE* output,
                          enum EQUATION_SOLUTION_CONDITION condition, double root, int testNumber);

/*!
 * \brief Test result of linear case outputs into console.
 *        A function of the console interface that provides
 *        outputs the result of linear case test proving to the console.
 * \returns void
 * \example consoleLinearTestOutput()
*/
void consoleLinearTestOutput(struct LinearEquationSolutionStatus test,
                             enum EQUATION_SOLUTION_CONDITION condition, double root, int testNumber);

#endif //EQUATION_H`