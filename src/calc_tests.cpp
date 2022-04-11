#include <gtest/gtest.h>
#include "calc_funcs.h"

/**
 * A function for comparing two double values with the accuracy of 0.000001.
 *
 * @param a First value.
 * @param b Second value.
 * @return Returns true if the numbers are equal.
 */
bool compare_double(double a, double b) {
    return fabs(a - b) < 0.000001;
}

TEST(plus, normal_values)
{
    EXPECT_EQ(add(10, 22), 32);
}

TEST(minus, neco) {
    EXPECT_TRUE(compare_double(sub(4.6, 0.2), 4.4));
}

TEST(odmocnina, randomtest) {
    EXPECT_EQ(nth_root(4, 2), 2);
}