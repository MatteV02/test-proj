#include "gcd.h"

using namespace std;

int gcd(int a, int b) {
    if (a < 0 || b < 0) {
        throw std::invalid_argument("gcd: arguments must be non-negative");
    }
    if (a == 0) return b;  // gcd(0, b) = b
    if (b == 0) return a;  // gcd(a, 0) = a
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}