#ifndef _CALC_FUNCS_H
#define _CALC_FUNCS_H

#include <cmath>
#include <float.h>

#define ACCURACY 0.000001

/**
 * A function for calculating the subtraction of two numbers.
 * a - b
 *
 * @param a First number.
 * @param b Second number.
 * @return Returns the value of expression a - b.
 */
double sub(double a, double b) {
    return a - b;
}

/**
 * A function for calculating the nth root of a number.
 * x ^ (1/n)
 *
 * @param x The base number.
 * @param n The exponent.
 * @return Returns the nth root of x.
 */
double nth_root(double x, long n)
{
    if(n % 2 == 0 && x < 0)
    {
        throw std::invalid_argument("The number cannot be negative for this n.");
    }

    return std::pow(x, 1.0/n);
}

/**
 * A function for adding two numbers.
 * a + b
 *
 * @param a First number.
 * @param b Second number.
 * @return Returns the value of expression a + b.
 */
double plus(double a, double b){
    return a + b;
}

/**
 * A function for division of two numbers.
 * a / b
 *
 * @param a dividend.
 * @param b divisor.
 * @return Returns the value of expression a / b.
 */
double div(double a, double b){
    return a / b;
}

/**
 * A function for calculating the nth_power of number .
 * a^b
 *
 * @param a base number.
 * @param b exponent.
 * @return Returns the value of expression a^b.
 */
double nth_power(double a, double b){
    return pow(a, b);
}

#endif