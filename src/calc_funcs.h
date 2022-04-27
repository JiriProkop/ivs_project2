/**
 * @file calc_funcs.h
 * @author Jiří Prokop (xproko47), Patrik Čerbák (xcerba00), Štěpán Czajkowski (xczajk01)
 * @brief  matematická knihovna 
 */

#ifndef _CALC_FUNCS_H
#define _CALC_FUNCS_H

#include <cmath>
#include <stdexcept>
#include <string>


#define ACCURACY 0.00000001

/**
 * A function for comparing two double values with the accuracy given in ACCURACY macro.
 *
 * @param a First value.
 * @param b Second value.
 * @return Returns true if the numbers are equal.
 */
bool compare_double(double a, double b);

/**
 * A function for getting the length of the number before the decimal separator.
 *
 * @param a The number to check.
 * @return Returns the number of integers.
 */
int get_number_length(double a);

/**
 * A function for telling whether double is an integer or not.
 *
 * @param a A number.
 * @return Returns true if the number is an integer(with precision of macro ACCURACY).
 */
bool is_int(double a);

/**
 * A function for remainder after division.
 * a % b
 *
 * @param a dividend
 * @param b divisor
 * @return Returns the value of expression a*b.
 */
double modulo(double a, double b);

/**
 * A function for calculating the subtraction of two numbers.
 * a - b
 *
 * @param a First number.
 * @param b Second number.
 * @return Returns the value of expression a - b.
 */
double sub(double a, double b);

/**
 * A function for adding two numbers.
 * a + b
 *
 * @param a First number.
 * @param b Second number.
 * @return Returns the value of expression a + b.
 */
double plus(double a, double b);
/**
 * A function for division of two numbers.
 * a / b
 *
 * @param a dividend.
 * @param b divisor.
 * @return Returns the value of expression a / b.
 */
double divide(double a, double b);

/**
 * A function for calculating the nth_power of number .
 * a^b
 *
 * @param a base number.
 * @param b natural exponent.
 * @return Returns the value of expression a^b.
 */
double nth_power(double a, double b);

/**
 * A function for calculating the nth root of a number.
 * x ^ (1/n)
 *
 * @param x The base number.
 * @param n The exponent.
 * @return Returns the nth root of x.
 */
double nth_root(double x, double n);

/**
 * A function for multiplying two numbers.
 * a*b
 *
 * @param a multiplier
 * @param b multiplied number
 * @return Returns the value of expression a*b.
 */
double mul(double a, double b);

/**
 * A function for calculating a factorial of a number.
 * m!
 *
 * @param m factorial argument
 * @return Returns the value of expression m! .
 */
unsigned long fac_value(unsigned long m);

/**
 * A function for checking argument for calculating a factorial.
 * 
 *
 * @param n factorial argument, must be a natural number lesser than 21
 * @return Returns the value of expression n!.
 */
double fac(double n);

#endif
