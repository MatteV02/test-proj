#ifndef PRIME_FACTORIZATION_H_
#define PRIME_FACTORIZATION_H_

#include <vector>

/**
 * @brief Perform prime factorization of a number
 * @param n Number to factorize. n < 2 returns empty vector
 * @return A vector of prime factors (empty if n < 2)
 */
std::vector<int> primeFactorization(int n);

#endif
