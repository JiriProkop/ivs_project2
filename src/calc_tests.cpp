#include <gtest/gtest.h>
#include "calc_funcs.h"


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


TEST(nth_root, even_roots){
    EXPECT_TRUE(compare_double(nth_root(4, 2), 2));
    EXPECT_TRUE(compare_double(nth_root(256, 2), 16));
    EXPECT_TRUE(compare_double(nth_root(117649, 6), 7));
    EXPECT_TRUE(compare_double(nth_root(1048576, 20), 2));
    EXPECT_TRUE(compare_double(nth_root(1.0/5.0, 2), 0.44721359));
    EXPECT_TRUE(compare_double(nth_root(1.0/3.0, 16), 0.93364101));
    EXPECT_ANY_THROW(nth_root(-2,2));
    EXPECT_ANY_THROW(nth_root(-8,4));
    EXPECT_ANY_THROW(nth_root(-1.0/3.0,2));
    EXPECT_ANY_THROW(nth_root(-26.0/7.0,12));
    EXPECT_TRUE(compare_double(nth_root(7, 4), 1.62657656));
    EXPECT_TRUE(compare_double(nth_root(2698, 6), 3.73112951));
}

TEST(nth_root, odd_roots){
    EXPECT_TRUE(compare_double(nth_root(8, 3), 2));
    EXPECT_TRUE(compare_double(nth_root(-8, 3), -2));
    EXPECT_TRUE(compare_double(nth_root(-3125, 5), -5));
    EXPECT_TRUE(compare_double(nth_root(12, 7), 1.42616163));
    EXPECT_TRUE(compare_double(nth_root(-12, 7), -1.42616163));
    EXPECT_TRUE(compare_double(nth_root(29.0/19.0, 7), 1.06226999));
    EXPECT_TRUE(compare_double(nth_root(-1.0/3.0, 11), -0.90495157));
}

TEST(nth_root, invalid_root){
    EXPECT_ANY_THROW(nth_root(2,0));
    EXPECT_ANY_THROW(nth_root(2,-1));
    EXPECT_ANY_THROW(nth_root(2,-2));
    EXPECT_ANY_THROW(nth_root(2,1.0/2.0));
}
 
TEST(plus, integers)
{
   EXPECT_TRUE(compare_double(plus(2, 8), 10));
   EXPECT_TRUE(compare_double(plus(0, 0), 0));
   EXPECT_TRUE(compare_double(plus(-25, -1), -26));
   EXPECT_TRUE(compare_double(plus(-12, 0), -12));
   EXPECT_TRUE(compare_double(plus(-1239, 1239), 0));
   EXPECT_TRUE(compare_double(plus(123435, 659486), 782921));
   EXPECT_TRUE(compare_double(plus(-42434, -192018), -234452));
}
 
TEST(plus, doubles)
{
   EXPECT_TRUE(compare_double(plus(21.0, 56.0), 77.0));
   EXPECT_TRUE(compare_double(plus(0.1, 0.1), 0.2));
   EXPECT_TRUE(compare_double(plus(42.69, 42.69), 85.38));
   EXPECT_TRUE(compare_double(plus(1231.32131, 1231.31414), 2462.63545));
   EXPECT_TRUE(compare_double(plus(10 * ACCURACY, 10 * ACCURACY), 20 * ACCURACY));
   EXPECT_TRUE(compare_double(plus(234.3564025, 234.3564025), 2 * 234.3564025));
}

TEST(plus, spicy_values)
{
    EXPECT_ANY_THROW(plus(DBL_MAX, 2));
    EXPECT_ANY_THROW(plus(DBL_MAX/2.0, DBL_MAX/2.0 + 1));
    EXPECT_TRUE(compare_double(plus(DBL_MAX/2.0, DBL_MAX/2.0), DBL_MAX));
    EXPECT_TRUE(compare_double(plus(DBL_MAX -2, 2), DBL_MAX));

    EXPECT_ANY_THROW(plus(DBL_MAX, DBL_MIN));

    EXPECT_ANY_THROW(plus(DBL_MIN, -1));
    EXPECT_ANY_THROW(plus(DBL_MIN*2.0, -DBL_MIN*2.0 - 1));
    EXPECT_TRUE(compare_double(plus(DBL_MIN*2.0, DBL_MIN*2.0), 2.0 * DBL_MIN));
}

TEST(divide, integers_whole_results)
{
    EXPECT_TRUE(compare_double(divide(120, 6), 20));
    EXPECT_TRUE(compare_double(divide(30, 15), 2));
    EXPECT_TRUE(compare_double(divide(0, 1500), 0));
    EXPECT_TRUE(compare_double(divide(-1500, -1), 1500));
    EXPECT_TRUE(compare_double(divide(128, -2), -64));
    EXPECT_TRUE(compare_double(divide(-12100, 110), -110));
}

TEST(divide, integers_not_whole_results)
{
    EXPECT_TRUE(compare_double(divide(69, 42), 1.6428571429));
    EXPECT_TRUE(compare_double(divide(13, 2), 6.5));
    EXPECT_TRUE(compare_double(divide(21, -42), -0.5));
    EXPECT_TRUE(compare_double(divide(121, 13), 9.3076923077));
    EXPECT_TRUE(compare_double(divide(-25, 3), -8.3333333333));
    EXPECT_TRUE(compare_double(divide(14879, -79466), -0.187237309));
    EXPECT_TRUE(compare_double(divide(1, 5), 1.0/5.0));
    EXPECT_TRUE(compare_double(divide(27, 23), 1.1739130435));
}

TEST(divide, doubles_whole_results)
{
    EXPECT_TRUE(compare_double(divide(125.0 ,5.0), 25.0));
    EXPECT_TRUE(compare_double(divide(3.1415926536, 3.1415926536), 1));
    EXPECT_TRUE(compare_double(divide(49.0/6.0, 7.0/42.0), 49.0));
    EXPECT_TRUE(compare_double(divide(2171.0574 ,31.4646), 69.0));
    EXPECT_TRUE(compare_double(divide(6.9006, 0.1643), 42.0));
    EXPECT_TRUE(compare_double(divide(84.266711, 2.718281), 31.0));
}

TEST(divide, doubles_not_whole_results)
{
    EXPECT_TRUE(compare_double(divide(12.646, 1.465), 8.6320819113));
    EXPECT_TRUE(compare_double(divide(-1.21, -1.1), 1.1));
    EXPECT_TRUE(compare_double(divide(20.48, -6.4), -3.2));
    EXPECT_TRUE(compare_double(divide(115.311, 61.1316), 1.8862748562));
    EXPECT_TRUE(compare_double(divide(5362.00709808, 1.2345), 4343.46464));
}

TEST(divide, spicy_values)
{
    EXPECT_ANY_THROW(divide(234424, 0));
    EXPECT_ANY_THROW(divide(0, 0));
    EXPECT_ANY_THROW(divide(DBL_MAX, 0.1));
    EXPECT_ANY_THROW(divide(2, DBL_MIN));
    EXPECT_ANY_THROW(divide(1.0001, DBL_MIN));
    EXPECT_ANY_THROW(divide(DBL_MIN, DBL_MAX));
    EXPECT_ANY_THROW(divide(DBL_MIN, 2));
}

TEST(nth_power, integer_base)
{
    EXPECT_TRUE(compare_double(nth_power(4, 2), 16));
    EXPECT_TRUE(compare_double(nth_power(-1, 2), 1));
    EXPECT_TRUE(compare_double(nth_power(5, 2), 25));
    EXPECT_TRUE(compare_double(nth_power(-3, 9), -19683));
    EXPECT_TRUE(compare_double(nth_power(1, 6363577774745887868), 1));
    EXPECT_TRUE(compare_double(nth_power(0, 3664654734776737377), 0));
}

TEST(nth_power, double_base)
{
    EXPECT_TRUE(compare_double(nth_power(0.5, 8), 0.00390625));
    EXPECT_TRUE(compare_double(nth_power(0.01, 25), 0));
    EXPECT_TRUE(compare_double(nth_power(-0.42, 2), 0.1764));
    EXPECT_TRUE(compare_double(nth_power(1.12, 3), 1.404928));
    EXPECT_TRUE(compare_double(nth_power(1.28, 5), 3.4359738368));
    EXPECT_TRUE(compare_double(nth_power(5853583336626626, 0), 1));
}

TEST(nth_power, spicy_values)
{
    EXPECT_ANY_THROW(nth_power(3545, -1));
    EXPECT_ANY_THROW(nth_power(55353, 3.14));
    /*EXPECT_ANY_THROW(nth_power(2, DBL_MAX));*/

    EXPECT_TRUE(compare_double(nth_power(2, 1.0), 2));
}

TEST(mul, integers)
{
    EXPECT_TRUE(compare_double(mul(2, 3), 6));
    EXPECT_TRUE(compare_double(mul(-2, 3), -6));
    EXPECT_TRUE(compare_double(mul(23, -345), -7935));
    EXPECT_TRUE(compare_double(mul(0, 999999), 0));
    EXPECT_TRUE(compare_double(mul(24523452, 0), 0));
    EXPECT_TRUE(compare_double(mul(420, 69), 28980));
}

TEST(mul, doubles)
{
    EXPECT_TRUE(compare_double(mul(2.0, 3.0), 6.0));
    EXPECT_TRUE(compare_double(mul(-0.1, 0.1), -0.01));
    EXPECT_TRUE(compare_double(mul(23.342523, -0.124341234), -2.902438114));
    EXPECT_TRUE(compare_double(mul(0.0, 999.999), 0.0));
    EXPECT_TRUE(compare_double(mul(12341.132, 0.00000000), 0.0));
    EXPECT_TRUE(compare_double(mul(1234.5678, 69432), 85718511.4896));
    EXPECT_TRUE(compare_double(mul(563456.5678, 0.01), 5634.565678));
}

TEST(fac, factorial)
{
    EXPECT_EQ(fac(10), 3628800);
    EXPECT_ANY_THROW(fac(-10));
    EXPECT_EQ(fac(13), 6227020800);
    EXPECT_EQ(fac(20), 2.432902008176640000e+18);
    EXPECT_ANY_THROW(fac(30));
}