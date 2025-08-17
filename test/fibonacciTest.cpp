#include "fibonacci.h"
#include "gtest/gtest.h"

using namespace std;

TEST(FibonacciTest, BaseCase1) {
  vector<int> expected = {1};
  vector<int> actual = fibonacci(1);
  EXPECT_EQ(expected, actual);
}

TEST(FibonacciTest, BaseCase2) {
  vector<int> expected = {1, 1};
  vector<int> actual = fibonacci(2);
  EXPECT_EQ(expected, actual);
}

TEST(FibonacciTest, FirstTenNumbers) {
  vector<int> expected = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
  vector<int> actual = fibonacci(10);
  EXPECT_EQ(expected, actual);
}

TEST(FibonacciTest, NegativeInput) {
  EXPECT_THROW(fibonacci(-5), invalid_argument);
}

TEST(FibonacciTest, NonIntegerInput) {
  EXPECT_THROW(fibonacci(2.5), invalid_argument);
}
