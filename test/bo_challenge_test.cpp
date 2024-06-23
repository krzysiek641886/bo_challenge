#include <gtest/gtest.h>
#include "../src/bo_challenge_code.h"

TEST(MakeChange, NegativeInput)
{
    int res = MakeChange(-10);
    // It is expected that function returns -1 when wrong inputs provided
    ASSERT_EQ(res, -1);
}

TEST(MakeChange, InputZero)
{
    int res = MakeChange(0);
    // It is expected that function returns -1 when wrong inputs provided
    ASSERT_EQ(res, -1);
}

TEST(MakeChange, VariousNumbers)
{
    int res = MakeChange(1);
    ASSERT_EQ(res, 1);
    res = MakeChange(135); // Example for assignment
    ASSERT_EQ(res, 4);
    res = MakeChange(12345678);
    ASSERT_EQ(res, 123462);
}

TEST(StrShift, TestDefaultConstructor)
{
    StrShift example;
    ASSERT_TRUE("" == example.getText());
}

TEST(StrShift, TestConstructorWithParameter)
{
    StrShift example("Foobar");
    ASSERT_TRUE("Foobar" == example.getText());
}

TEST(StrShift, TestAssignmentConstructor)
{
    StrShift example1("Foobar");
    StrShift example2 = example1;
    ASSERT_TRUE("Foobar" == example2.getText());
}

TEST(StrShift, TestStringAssignment)
{
    StrShift example;
    example = "Foobar";
    ASSERT_TRUE("Foobar" == example.getText());
    example = "Barfoo";
    ASSERT_TRUE("Barfoo" == example.getText());
}

TEST(StrShift, TestEqualOperator)
{
    StrShift example1;
    StrShift example2;
    ASSERT_TRUE(example1 == example2);
    example1 = "foo";
    ASSERT_FALSE(example1 == example2);
    example2 = "foo";
    ASSERT_TRUE(example1 == example2);
}

TEST(StrShift, TestShiftRight)
{
    StrShift example;
    example = "Bang&Olufsen";
    ASSERT_TRUE("Bang&Olufsen" == example.getText());
    example << 0;
    ASSERT_TRUE("Bang&Olufsen" == example.getText());
    example << 2;
    ASSERT_TRUE("enBang&Olufs" == example.getText());
    example << -2;
    ASSERT_TRUE("Bang&Olufsen" == example.getText());
    example << example.getText().length() * 10;
    ASSERT_TRUE("Bang&Olufsen" == example.getText());
    example << example.getText().length() * 10 + 5;
    ASSERT_TRUE("ufsenBang&Ol" == example.getText());
}

TEST(StrShift, TestShiftLeft)
{
    StrShift example;
    example = "Bang&Olufsen";
    ASSERT_TRUE("Bang&Olufsen" == example.getText());
    example >> 0;
    ASSERT_TRUE("Bang&Olufsen" == example.getText());
    example >> 2;
    ASSERT_TRUE("ng&OlufsenBa" == example.getText());
    example >> -2;
    ASSERT_TRUE("Bang&Olufsen" == example.getText());
    example >> example.getText().length() * 10;
    ASSERT_TRUE("Bang&Olufsen" == example.getText());
    example >> example.getText().length() * 10 + 5;
    ASSERT_TRUE("OlufsenBang&" == example.getText());
}

TEST(StrShift, PrintExample)
{
    StrShift example;
    example = "Bang&Olufsen";
    std::cout << "\"example << 2\" results in " << (example << 2) << "\n\n";
    ASSERT_TRUE(true);
    /*
    I tried to follow the Task 2 down to the line and use C style printf. For that I overloaded a conversion operator as follows:
        operator char*() const;

    Unfortunately since printf is a C function the compiler does not perform an implicit conversion to 'char *'.
    Thus to use printf it would be necessary to use explicit casting:
        printf("\"example << 2\" results in %s\n", (char *)(example << 2));

    In the end I decided, that the more practical approach is to use C++-style std::cout and removed the conversion operator.
    That is why it isn't possible to call with correct result:
        printf("\"example << 2\" results in %s\n", example << 2);
    */
}

// main function for running tests
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
