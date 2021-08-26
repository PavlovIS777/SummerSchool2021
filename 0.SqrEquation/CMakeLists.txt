cmake_minimum_required(VERSION 3.20)
project(SqrEquation C)

set(CMAKE_C_STANDARD 11)

add_executable(SqrEquation main.c Equation.h Equation.c)
