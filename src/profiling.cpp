/**
 * @file profiling.cpp
 * @author Patrik Čerbák (xcerba00)
 * @brief  standard deviation to check the result of profiling
 */

#include <iostream>
#include <string>
#include "calc_funcs.h"

int main()
{
	char number_str[30] = {0}; // string to save the number from stdin
    int character = getchar(); // character variable

    double number; // number (converted from number_str)
    double sum = 0; // sum of the numbers
    double sum_squared = 0; // sum of the numbers squared
    double num_of_numbers = 0; // number of values (numbers)

    // go through all the characters until EOF
    while(character != EOF)
    {
        // save each number into number_str
        int i = 0;
        while(character != ' ' && character != '\n' && character != '\t' && character != EOF)
        {
            number_str[i++] = character;
            character = getchar();
        }
        if (i != 0)
        {
            number_str[i] = '\0';
        }

        num_of_numbers += 1;
        number = std::stod(number_str); // convert

        // calculate sums
        sum = plus(sum, number);
        sum_squared = plus(sum_squared, nth_power(number, 2));

        if(character == EOF)
        {
            break;
        }
        else
        {
            character = getchar();
        }
    }

    // calculate the standard deviation operation by operation
    double average = divide(sum, num_of_numbers);

    double bracket = nth_power(average, 2);
    bracket = mul(num_of_numbers, bracket);
    bracket = sub(sum_squared, bracket);

    double fraction = sub(num_of_numbers, 1);
    fraction =  divide(1, fraction);

    double result = mul(fraction, bracket);
    result = nth_root(result, 2);

    printf("%lf\n", result);

	return 0;
}

/*** end of file profiling.cpp ***/
