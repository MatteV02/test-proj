#include "primeFactorization.h"
#include <cmath>
using namespace std;

vector<int> primeFactorization(int n) {
    if (n < 2) return {};

    vector<int> factors;

    // Handle even factors
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Handle odd factors
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is still > 2, it's prime
    if (n > 1) factors.push_back(n);

    return factors;
}
