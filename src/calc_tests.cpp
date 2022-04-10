#include <gtest/gtest.h>
#include "calc_funcs.h"

TEST(plus, normal_values)
{
    EXPECT_EQ(add(10, 22), 32);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// vice na: 
// https://stackoverflow.com/questions/62910867/how-to-run-tests-and-debug-google-test-project-in-vs-code