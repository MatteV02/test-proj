#include <iostream>
#include "primeFactorization.h"
using namespace std;

int main() {
    vector<int> factors = primeFactorization(42);

    cout << "Prime factors of 42:" << endl;
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}