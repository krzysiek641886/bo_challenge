#include <gtest/gtest.h>
extern "C" {
#include "my_code.h"
}

// Example test case
TEST(MyCodeTest, ExampleTest) {
    ASSERT_EQ(3, 5); // Replace with appropriate expected value
}

// main function for running tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
