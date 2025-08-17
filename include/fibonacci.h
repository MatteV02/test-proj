#ifndef FIBONACCI_H_
#define FIBONACCI_H_

#include <vector>
#include <stdexcept>

/**
 * @brief Compute Fibonacci sequence up to n terms
 * @param n Number of terms to generate
 * @throw `invalid_argument` if `n` < 1
 */
std::vector<int> fibonacci(int n);

#endif