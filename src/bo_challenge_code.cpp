#include "bo_challenge_code.h"
#include <vector>
#include <algorithm>
/*
TASK 1

Given a currency with denominations of 100, 50, 20, 10, 5 and 1 write a method MakeChange that takes
an integer amount representing the total change to make and return an integer representing
    the smallest possible number of bills to return.  For example, a call of MakeChange(135) would result in a return value of 4
    (1 one hundred bill, 1 twenty bill, 1 ten bill and 1 five bill).
*/
int MakeChange(int change)
{
    std::vector<int> denominations = {100, 50, 20, 10, 5, 1};
    int numOfBills = 0;

    // Make sure denominations are in a descending order
    std::sort(denominations.begin(), denominations.end(), [](int a, int b)
              { return a > b; });

    if (denominations.back() <= 0)
    {
        throw std::invalid_argument("Provided set of denominations is incorrect, has non-positive numbers");
    }

    if (change < denominations.back())
    {
        // Change is smaller than the lowest denomination
        return -1;
    }

    for (int den : denominations)
    {
        // Divide the leftover change by the highest available denomination
        // and add result to the numOfBills
        numOfBills += change / den;
        change %= den;
    }

    if (change != 0)
    {
        // It is not possible to give change in available denominations
        return -1;
    }
    return numOfBills;
}

/*
TASK 2

Implement a class that does string manipulation by overloading the following operators: <<, >>, = and ==.  For example, consider the following code:
StrShift example;
example = “Bang&Olufsen”;
printf(“\”example << 2\” results in %s\n“, example << 2);
In the above code the output would be “enBang&Olufs” which shows the last two characters of the string “Bang&Olufsen” rotated to the left of the string.  Please note that state is maintained so two calls of example << 1 would give the same end result as calling example << 2 once.
Consideration will be given to correctness, design, code readability as well as any unit testing.
As part of a final solutions please submit test cases you used to verify correctness in addition to any unit tests done.
*/
StrShift::StrShift(std::string inputText) : text(inputText) {}

std::string StrShift::getText() const
{
    return text;
}

StrShift &StrShift::operator=(const StrShift &other)
{
    text = other.text;
    return *this;
}

StrShift &StrShift::operator=(const std::string &inputStr)
{
    text = inputStr;
    return *this;
}

bool StrShift::operator==(const StrShift &other) const
{
    return text == other.text;
}

static std::string shiftString(const std::string& str, int shiftCount)
{
    if (str.empty())
    {
        return str;
    }

    int len = str.length();
    shiftCount = shiftCount % len; // Normalize shift count

    if (shiftCount < 0)
    {
        shiftCount += len;
    }
    
    return str.substr(len - shiftCount) + str.substr(0, len - shiftCount);
}

StrShift &StrShift::operator<<(const int shift)
{
    text = shiftString(text, shift);
    return *this;
}

StrShift &StrShift::operator>>(const int shift)
{
    text = shiftString(text, -shift);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const StrShift &obj)
{
    os << obj.text;
    return os;
}