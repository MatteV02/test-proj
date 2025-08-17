# ======================================
#  Project Configuration
# ======================================
cmake_minimum_required(VERSION 3.15)
project(
    test-proj
    VERSION 0.1.0
    LANGUAGES CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ======================================
#  Main Library Configuration
# ======================================
# Create library target
add_library(math_utils
    src/fibonacci.cpp
    src/gcd.cpp
    src/primeFactorization.cpp
)

# Include directories
target_include_directories(math_utils 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ======================================
#  Main Executable
# ======================================
add_executable(test-proj src/main.cpp)
target_link_libraries(test-proj PRIVATE math_utils)

# ======================================
#  Testing Configuration (delegated)
# ======================================
enable_testing()
add_subdirectory(test)

# ======================================
#  Documentation Configuration
# ======================================
find_package(Doxygen REQUIRED dot)

# Configure Doxyfile
configure_file(Doxyfile.in Doxyfile @ONLY)

# Add documentation target
add_custom_target(docs
    COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM
)