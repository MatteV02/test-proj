#ifndef FIBONACCI_H_
#define FIBONACCI_H_

#include <vector>
#include <stdexcept>

/**
 * @brief Compute Fibonacci sequence up to a certain number
 * @throw `invalid_argument` exception if `n` < 0
 */
std::vector<int> fibonacci(float n);

#endif