# Add test executable
add_executable(bo_challenge_test bo_challenge_test.cpp)

# Link test executable against gtest & gtest_main
target_link_libraries(bo_challenge_test gtest gtest_main bo_challenge)

# Add tests
add_test(NAME MyCodeTest COMMAND bo_challenge_test)
