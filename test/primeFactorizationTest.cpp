#include <gtest/gtest.h>
#include <primeFactorization.h>
#include <vector>
#include <algorithm>

using namespace std;

TEST(PrimeFactorizationTest, HandlesOne) {
    vector<int> expected = {};
    EXPECT_EQ(primeFactorization(1), expected);
}

TEST(PrimeFactorizationTest, HandlesPrimeNumbers) {
    EXPECT_EQ(primeFactorization(2), vector<int>({2}));
    EXPECT_EQ(primeFactorization(13), vector<int>({13}));
    EXPECT_EQ(primeFactorization(29), vector<int>({29}));
}

TEST(PrimeFactorizationTest, HandlesCompositeNumbers) {
    EXPECT_EQ(primeFactorization(4), vector<int>({2, 2}));
    EXPECT_EQ(primeFactorization(6), vector<int>({2, 3}));
    EXPECT_EQ(primeFactorization(8), vector<int>({2, 2, 2}));
    EXPECT_EQ(primeFactorization(9), vector<int>({3, 3}));
    EXPECT_EQ(primeFactorization(60), vector<int>({2, 2, 3, 5}));
    EXPECT_EQ(primeFactorization(315), vector<int>({3, 3, 5, 7}));
}

TEST(PrimeFactorizationTest, HandlesNegativeInput) {
    vector<int> expected = {};
    EXPECT_EQ(primeFactorization(-1), expected);
    EXPECT_EQ(primeFactorization(-10), expected);
    EXPECT_EQ(primeFactorization(-100), expected);
}

TEST(PrimeFactorizationTest, HandlesZero) {
    vector<int> expected = {};
    EXPECT_EQ(primeFactorization(0), expected);
}

TEST(PrimeFactorizationTest, HandlesLargeNumber) {
    vector<int> expected = {2, 2, 2, 3, 3, 5, 7, 11, 13};
    EXPECT_EQ(primeFactorization(2*2*2*3*3*5*7*11*13), expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}