#include "pch.h"
#include "../Task2/GCD.h"

TEST(TestRecursiveGCD, ExNumberOne)
{
    EXPECT_EQ(8, RecursiveGCD(8, 16));
}
TEST(TestRecursiveGCD, ExNumberTwo)
{
    EXPECT_EQ(3, RecursiveGCD(15, 9));
}
TEST(TestRecursiveGCD, ExNumberFree)
{
    EXPECT_EQ(7, RecursiveGCD(21, 14));
}
TEST(TestGCD, ExNumberOne)
{
    EXPECT_EQ(12, GCD(48, 36));
}
TEST(TestGCD, ExNumberTwo)
{
    EXPECT_EQ(5, GCD(90, 35));
}
TEST(TestGCD, ExNumberFree)
{
    EXPECT_EQ(11, GCD(77, 55));
}