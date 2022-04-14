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

TEST(minus, decimals) {
    EXPECT_TRUE(compare_double(sub(4.6, 4.6), 0));
    EXPECT_TRUE(compare_double(sub(4.6, 0.2), 4.4));
    EXPECT_TRUE(compare_double(sub(4.6, 5), -0.4));
    EXPECT_TRUE(compare_double(sub(-4.5, -2.3), -2.2));
    EXPECT_TRUE(compare_double(sub(-2.4, -4.5), 2.1));
    EXPECT_TRUE(compare_double(sub(4.5, -2.3), 6.8));
    EXPECT_TRUE(compare_double(sub(-4.5, 2.3), -6.8));
}

TEST(minus, integers) {
    EXPECT_TRUE(compare_double(sub(4, 4), 0));
    EXPECT_TRUE(compare_double(sub(4, 2), 2));
    EXPECT_TRUE(compare_double(sub(4, 5), -1));
    EXPECT_TRUE(compare_double(sub(-4, -2), -2));
    EXPECT_TRUE(compare_double(sub(-1, -3), 2));
    EXPECT_TRUE(compare_double(sub(4, -2), 6));
    EXPECT_TRUE(compare_double(sub(-4, 2), -6));
}

TEST(minus, rationals) {
    EXPECT_TRUE(compare_double(sub(1.0/3.0, 1.0/3.0), 0));
    EXPECT_TRUE(compare_double(sub(0, 1.0/3.0), -0.33333333));
    EXPECT_TRUE(compare_double(sub(2.0/3.0, 0), 0.66666666));
    EXPECT_TRUE(compare_double(sub(-1.0/3.0, 1.0/3.0), -0.66666666));
    EXPECT_TRUE(compare_double(sub(1.0/3.0, -1.0/3.0), 0.66666666));
}


TEST(nth_root, positive_even_roots){
    EXPECT_EQ(nth_root(4, 2), 2);
    EXPECT_EQ(nth_root(256, 2), 16);
    EXPECT_EQ(nth_root(117649, 6), 7);
    EXPECT_EQ(nth_root(1048576, 20), 2);
    EXPECT_TRUE(nth_root(compare_double(1.0/5.0, 2), 0.44721359));
    EXPECT_TRUE(nth_root(compare_double(1.0/3.0, 16), 0.93364101));
    EXPECT_ANY_THROW(nth_root(-2,2));
    EXPECT_ANY_THROW(nth_root(-8,4));
    EXPECT_ANY_THROW(nth_root(-1.0/3.0,2));
    EXPECT_ANY_THROW(nth_root(-26.0/7.0,12));
    EXPECT_TRUE(compare_double(nth_root(7, 4), 1.62657656));
    EXPECT_TRUE(compare_double(nth_root(2698, 6), 3.73112951));
}
TEST(nth_root, negative_even_roots){
    EXPECT_TRUE(nth_root(compare_double(4, -2), 1/2));
    EXPECT_TRUE(nth_root(compare_double(117649, -6), 1/7));
    EXPECT_TRUE(nth_root(compare_double(1048576, -20), 1/2));
    EXPECT_TRUE(nth_root(compare_double(1.0/5.0, -2), 2.23606797));
    EXPECT_TRUE(nth_root(compare_double(1.0/3.0, -16), 1.07107548));
    EXPECT_ANY_THROW(nth_root(-2,-2));
    EXPECT_ANY_THROW(nth_root(-8,-4));
    EXPECT_ANY_THROW(nth_root(-1.0/3.0,-2));
    EXPECT_ANY_THROW(nth_root(-26.0/7.0,-12));
    EXPECT_TRUE(compare_double(nth_root(7, -4), 0.61478815));
    EXPECT_TRUE(compare_double(nth_root(2698, -6), 0.26801535));
}

TEST(nth_root, positive_odd_roots){
    EXPECT_EQ(nth_root(8, 3), 2);
    EXPECT_EQ(nth_root(-8, 3), -2);
    EXPECT_EQ(nth_root(-3125, 5), -5);
    EXPECT_TRUE(compare_double(nth_root(12, 7), 1.42616163));
    EXPECT_TRUE(compare_double(nth_root(-12, 7), -1.42616163));
    EXPECT_TRUE(compare_double(nth_root(29.0/19.0, 7), 1.06226999));
    EXPECT_TRUE(compare_double(nth_root(-1.0/3.0, 11), 0.90495157));
}

TEST(nth_root, neagtive_odd_roots){
    EXPECT_TRUE(compare_double(nth_root(8, -3), 1/2));
    EXPECT_TRUE(compare_double(nth_root(-8, -3), -1/2));
    EXPECT_TRUE(compare_double(nth_root(13, -11), 0.79201320));
    EXPECT_TRUE(compare_double(nth_root(-13, -11), -0.79201320));
    EXPECT_TRUE(compare_double(nth_root(29.0/19.0, -7), 0.94138025));
    EXPECT_TRUE(compare_double(nth_root(-29.0/19.0, -7), -0.941380259));
}

TEST(nth_root, positive_fractional_decimal_roots){
    EXPECT_TRUE(compare_double(nth_root(2, 1/2), 4));
    EXPECT_TRUE(compare_double(nth_root(-2, 1/2), 4));
    EXPECT_TRUE(compare_double(nth_root(2, 1/3), 8));
    EXPECT_TRUE(compare_double(nth_root(-2, 1/3), -8));
    EXPECT_TRUE(compare_double(nth_root(7, 1.1), 5.86503955));
    EXPECT_TRUE(compare_double(nth_root(-7, 1.1), 5.86503955));
    EXPECT_ANY_THROW(nth_root(-7,1.2));
    EXPECT_ANY_THROW(nth_root(-7,2.8));
    EXPECT_TRUE(compare_double(nth_root(1.0/4.0, 0.9), 0.21431099));
    EXPECT_TRUE(compare_double(nth_root(-1.0/4.0, 1.8), -0.46293735));
}

TEST(nth_root, negatative_fractional_decimal_roots){
    EXPECT_TRUE(compare_double(nth_root(2, -1/2), 1/4));
    EXPECT_TRUE(compare_double(nth_root(-2, -1/2), 1/4));
    EXPECT_TRUE(compare_double(nth_root(2, -1/3), 1/8));
    EXPECT_TRUE(compare_double(nth_root(-2, -1/3), -1/8));
    EXPECT_TRUE(compare_double(nth_root(7, -1.1), 0.17050183));
    EXPECT_TRUE(compare_double(nth_root(-7, -1.1), 0.17050183));
    EXPECT_ANY_THROW(nth_root(-7,-1.2));
    EXPECT_ANY_THROW(nth_root(-7,-2.8));
    EXPECT_TRUE(compare_double(nth_root(1.0/4.0, -0.9), 4.66611615));
    EXPECT_TRUE(compare_double(nth_root(-1.0/4.0, 1.8), -2.16011947));
}