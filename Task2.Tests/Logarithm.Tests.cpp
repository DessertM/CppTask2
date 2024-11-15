#include "pch.h"
#include "../Task2/Logarithm.h"

TEST(TestLogarifm, ExNumberOne)
{
    EXPECT_EQ(-2, Logarithm(-1));
}
TEST(TestLogarifm, ExNumberTwo)
{
    EXPECT_EQ(3, Logarithm(8));
}
TEST(TestLogarifm, ExNumberFree)
{
    EXPECT_EQ(-1, Logarithm(7));
}
TEST(TestLogarifm, ExNumberFour)
{
    EXPECT_EQ(10, Logarithm(1024));
}