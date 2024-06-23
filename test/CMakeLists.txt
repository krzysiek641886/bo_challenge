# Add test executable
add_executable(test_my_code test_my_code.cpp)

# Link test executable against gtest & gtest_main
target_link_libraries(test_my_code gtest gtest_main my_code)

# Add tests
add_test(NAME MyCodeTest COMMAND test_my_code)
