# Math Utilities Library

[![CI Status](https://github.com/MatteV02/test-proj/actions/workflows/ci.yml/badge.svg)](https://github.com/MatteV02/test-proj/actions)
[![Coverage Status](https://coveralls.io/repos/github/MatteV02/test-proj/badge.svg?branch=main)](https://coveralls.io/github/MatteV02/test-proj?branch=main)

A collection of mathematical functions including:
- Prime factorization
- Fibonacci sequence generation
- Greatest Common Divisor (GCD)

## Building

### Requirements
- CMake ≥ 3.15
- C++17 compatible compiler

### Build Steps
```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release

# Run main executable
./test-proj

# Run tests
ctest -V