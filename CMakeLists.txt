cmake_minimum_required(VERSION 3.10)
project(MyProject C CXX)

# Enable testing
enable_testing()

# Add source files
add_library(bo_challenge src/bo_challenge_code.cpp)

# Add Google Test
add_subdirectory(googletest)

# Add subdirectory for tests
add_subdirectory(test)
