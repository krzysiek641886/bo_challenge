#include <gtest/gtest.h>
#include "../src/bo_challenge_code.h"

TEST(MakeChange, NegativeInput) {
    int res = MakeChange(-10);
    // It is expected that function returns -1 when wrong inputs provided
    ASSERT_EQ(res, -1);
}

TEST(MakeChange, InputZero) {
    int res = MakeChange(0);
    // It is expected that function returns -1 when wrong inputs provided
    ASSERT_EQ(res, -1);
}

TEST(MakeChange, VariousNumbers) {
    int res = MakeChange(1);
    ASSERT_EQ(res, 1);
    res = MakeChange(135); // Example for assignment
    ASSERT_EQ(res, 4);
    res = MakeChange(12345678);
    ASSERT_EQ(res, 123462);
}

// main function for running tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
