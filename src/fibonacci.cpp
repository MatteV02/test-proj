#include "fibonacci.h"
#include <cmath>
using namespace std;

// Function to check if a number is an integer
bool isInteger(float k) {
    float frac;
    modf(k, &frac);
    return (fabs(frac - k) < 0.0001);  // Check if fractional part of the number is zero with a tolerance level
}

vector<int> fibonacci(float n) {
    if (n <= 0 || !isInteger(n)) {
        throw invalid_argument("Input must be a positive integer.");
    }
    
    vector<int> fib(static_cast<int>(n));
    fib[0] = 1;
    if(n > 1) { // If n is 1, there's no need for the loop
        fib[1] = 1;
        for (int i = 2; i < static_cast<int>(n); i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }
    return fib;
}
