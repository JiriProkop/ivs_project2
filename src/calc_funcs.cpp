/**
 * @file calc_funcs.cpp
 * @author Jiří Prokop (xproko47), Patrik Čerbák (xcerba00), Štěpán Czajkowski (xczajk01)
 * @brief  matematická knihovna
 */

#include "calc_funcs.h"
#include <cmath>
#include <stdexcept>
#include <string>

bool compare_double(double a, double b)
{
    return fabs(a - b) < ACCURACY;
}

int get_number_length(double a)
{
    std::string str = std::to_string(a);
    int i = 0;
    int j = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '.')
        {
            return i - j;
        }
        else if(str[i] == '-')
        {
            j++;
        }
        i++;
    }
    return i - j;
}

bool is_int(double a)
{
    return compare_double(a, round(a));
}

double modulo(double a, double b)
{
    if(b == 0){
        throw std::invalid_argument("divisor cannot be 0");
    }
    if(!(is_int(a)) || !(is_int(b)))
    {
        throw std::invalid_argument("only natural numbers");
    }
    return (double)((long)a % (long)b);
}

double sub(double a, double b)
{
    return a - b;
}


double plus(double a, double b)
{
    return a + b;
}

double divide(double a, double b)
{
    if (b == 0){
        throw std::invalid_argument("cannot divide by 0");
    }
    return a / b;
}

double nth_power(double a, double b){
    double result = a;
    if(!(is_int(b)))
    {
        throw std::invalid_argument("exponent has to be a natural number");
    }
    if(b < 0){
        throw std::invalid_argument("exponent has to be a natural number");
    }
    if(compare_double(b, 0) || compare_double(a, 1)){
        return 1;
    }
    else if(compare_double(a, 0))
    {
        return 0;
    }
    double max = 99999999999999999999.0;
    for(double i = 1; i < b; i++){
        result = result * 100000000.0;
        result = round(result);
        result = result / 100000000.0;
        result = result * a;
        if(result > max  || result < -max){
            throw std::invalid_argument("result too big");
        }
    }
    return result;
}

double nth_root(double x, double n)
{
    if(!(is_int(n)))
    {
        throw std::invalid_argument("The root has to be a natural number!");
    }
    if(((long long)round(n) % 2 == 0 && x < 0) || n == 0 || n < 0)
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

double mul(double a, double b)
{
    return a * b;
}

unsigned long fac_value(unsigned long m)
{
    if(m == 0)
    {
        return 1;
    }
    return m * fac_value(m - 1);
}

double fac(double n)
{
    if(n < 0)
    {
        throw std::invalid_argument("The number has to be positive or zero!");
    }
    if(!(is_int(n)))
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
