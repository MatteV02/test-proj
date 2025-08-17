# ======================================
#  GoogleTest Dependency (FetchContent)
# ======================================
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

# ======================================
#  Test Targets Configuration
# ======================================
# Helper function for test targets
function(add_math_test TEST_NAME SOURCE_FILE)
    add_executable(${TEST_NAME} ${SOURCE_FILE})
    target_link_libraries(${TEST_NAME}
        PRIVATE
            math_utils
            GTest::gtest_main
    )
    target_include_directories(${TEST_NAME}
        PRIVATE
            ${CMAKE_SOURCE_DIR}/include
    )
    gtest_discover_tests(${TEST_NAME})
endfunction()

# Define tests
add_math_test(FibonacciTest fibonacciTest.cpp)
add_math_test(GCDTest gcdTest.cpp)
add_math_test(PrimeFactorizationTest primeFactorizationTest.cpp)

# Add code coverage if enabled
option(ENABLE_COVERAGE "Enable code coverage" OFF)
if(ENABLE_COVERAGE)
    target_compile_options(math_utils PRIVATE --coverage -fprofile-arcs -ftest-coverage)
    target_link_libraries(math_utils PRIVATE --coverage)
endif()