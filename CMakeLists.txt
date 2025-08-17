# ======================================
#  Project Configuration
# ======================================
cmake_minimum_required(VERSION 3.10)
project(
    test-proj
    VERSION 0.1.0
    LANGUAGES C CXX
)

# ======================================
#  Source Files & Main Target
# ======================================
set(MAIN_SOURCES
    src/primeFactorization.cpp
    src/main.cpp
)

add_executable(test-proj ${MAIN_SOURCES})
target_include_directories(test-proj PRIVATE includes)

# ======================================
#  GoogleTest Dependency (FetchContent)
# ======================================
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# ======================================
#  Test Configuration
# ======================================
enable_testing()

# Define custom GoogleTest helper function
function(add_gtest TARGET_NAME)
    # Create executable with variable arguments as sources
    add_executable(${TARGET_NAME} ${ARGN})
    
    # Link against GTest main
    target_link_libraries(${TARGET_NAME} 
        PRIVATE 
            GTest::gtest_main
    )
    
    # Add include directories
    target_include_directories(${TARGET_NAME}
        PRIVATE 
            includes
    )
    
    # Automatically discover tests
    include(GoogleTest)
    gtest_discover_tests(${TARGET_NAME})
endfunction()

# Create test executable using custom function
add_gtest(primeFactorizationTest
    test/primeFactorizationTest.cpp
    src/primeFactorization.cpp 
)

add_gtest(fibonacciTest
    test/fibonacciTest.cpp
    src/fibonacci.cpp
)

add_gtest(gcdTest
    test/gcdTest.cpp
    src/gcd.cpp
)