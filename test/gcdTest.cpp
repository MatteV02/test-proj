#include <gtest/gtest.h>
#include "gcd.h"

TEST(GCDTest, PositiveNumbers) {
    EXPECT_EQ(gcd(1, 1), 1);
    EXPECT_EQ(gcd(2, 4), 2);
    EXPECT_EQ(gcd(4, 2), 2);
    EXPECT_EQ(gcd(12, 18), 6);
    EXPECT_EQ(gcd(18, 12), 6);
    EXPECT_EQ(gcd(17, 23), 1);  // Coprime numbers
    EXPECT_EQ(gcd(1071, 462), 21);
    EXPECT_EQ(gcd(462, 1071), 21);
}

TEST(GCDTest, ZeroCases) {
    EXPECT_EQ(gcd(0, 5), 5);
    EXPECT_EQ(gcd(5, 0), 5);
    EXPECT_EQ(gcd(0, 0), 0);  // Special case
}

TEST(GCDTest, EqualNumbers) {
    EXPECT_EQ(gcd(5, 5), 5);
    EXPECT_EQ(gcd(100, 100), 100);
    EXPECT_EQ(gcd(0, 0), 0);
}

TEST(GCDTest, LargeNumbers) {
    EXPECT_EQ(gcd(123456, 7890), 6);
    EXPECT_EQ(gcd(987654321, 123456789), 9);
    EXPECT_EQ(gcd(1'000'000'000, 500'000'000), 500000000);
}

TEST(GCDTest, NegativeNumbers) {
    EXPECT_THROW(gcd(-1, 5), std::invalid_argument);
    EXPECT_THROW(gcd(5, -1), std::invalid_argument);
    EXPECT_THROW(gcd(-5, -10), std::invalid_argument);
}

TEST(GCDTest, OneIsMultipleOfOther) {
    EXPECT_EQ(gcd(3, 9), 3);
    EXPECT_EQ(gcd(9, 3), 3);
    EXPECT_EQ(gcd(50, 100), 50);
    EXPECT_EQ(gcd(100, 50), 50);
}

TEST(GCDTest, CoPrimeNumbers) {
    EXPECT_EQ(gcd(8, 15), 1);
    EXPECT_EQ(gcd(15, 8), 1);
    EXPECT_EQ(gcd(13, 17), 1);
    EXPECT_EQ(gcd(17, 13), 1);
}