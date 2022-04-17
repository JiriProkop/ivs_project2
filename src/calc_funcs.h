#ifndef _CALC_FUNCS_H
#define _CALC_FUNCS_H

#include <cmath>

#define ACCURACY 0.000001

/**
 * A function for comparing two double values with the accuracy of 0.000001.
 *
 * @param a First value.
 * @param b Second value.
 * @return Returns true if the numbers are equal.
 */
bool compare_double(double a, double b) {
    return fabs(a - b) < ACCURACY;
}

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
double divide(double a, double b){
    if (b == 0){
        throw std::invalid_argument("cannot divide by 0");
    }
    return a / b;
}

/**
 * A function for calculating the nth_power of number .
 * a^b
 *
 * @param a base number.
 * @param b natural exponent.
 * @return Returns the value of expression a^b.
 */
double nth_power(double a, double b){
    return pow(a, b);
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
    if((n % 2 == 0 && x < 0) || n == 0)
    {
        throw std::invalid_argument("Invalid root!");
    }

    if(x < 0)
    {
        return - std::pow(fabs(x), 1.0/n);
    }
    else
    {
        return std::pow(x, 1.0/n);
    }
}

/**
 * A function for multiplying two numbers.
 * a*b
 *
 * @param a multiplier
 * @param b multiplied number
 * @return Returns the value of expression a*b.
 */
double mul(double a, double b)
{
    return a * b;
}

/**
 * A function for calculating a factorial of a number.
 * m!
 *
 * @param m factorial argument
 * @return Returns the value of expression m! .
 */
unsigned long fac_value(unsigned long m)
{
    if(m == 1)
    {
        return 1;
    }
    return m * fac_value(m - 1);
}

/**
 * A function for checking argument for calculating a factorial.
 * 
 *
 * @param n factorial argument, must be a natural number lesser than 21
 * @return Returns the value of expression n!.
 */
double fac(double n)
{
    if(n < 0)
    {
        throw std::invalid_argument("The number has to be positive or zero!");
    }
    if(!(compare_double(n, round(n))))
    {
        throw std::invalid_argument("The number has to be a natural number!");
    }
    if(n > 20)
    {
        throw std::invalid_argument("Math error: the result is too big!");
    }
    unsigned long m = round(n);

    return fac_value(m);
}


#endif