#include "fibonacci.h"
using namespace std;

vector<int> fibonacci(int n) {
  if (n <= 0) {
    throw invalid_argument("Input must be a positive integer.");
  }

  vector<int> fib;
  if (n >= 1) fib.push_back(1);
  if (n >= 2) fib.push_back(1);
  for (int i = 2; i < n; i++) {
    fib.push_back(fib[i - 1] + fib[i - 2]);
  }
  return fib;
}
