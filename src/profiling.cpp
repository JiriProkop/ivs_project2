/**
 * @file profiling.cpp
 * @author Patrik Čerbák (xcerba00)
 * @brief  standard deviation to check the result of profiling
 */

#include <iostream>
#include <string>
#include "calc_funcs.h"

int main() {
	std::string line;
    double number;
    double sum = 0;
    double sum_squared = 0;
    double num_of_lines = 0;

    std::getline(std::cin, line);
    while(line != "") {
        num_of_lines += 1;
        number = std::stod(line);

        sum = plus(sum, number);
        sum_squared = plus(sum_squared, nth_power(number, 2));

        std::getline(std::cin, line);
    }

    double average = divide(sum, num_of_lines);
    double bracket = sub(sum_squared, mul(num_of_lines, nth_power(average, 2)));

    double fraction = divide(1, sub(num_of_lines, 1));

    double result = nth_root(mul(fraction, bracket), 2);

    printf("%lf\n", result);

	return 0;
}

/*** end of file profiling.cpp ***/
