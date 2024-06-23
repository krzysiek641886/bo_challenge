#ifndef __BO_CHALLENGE_CODE__
#define __BO_CHALLENGE_CODE__

#include <string>
#include <iostream>

int MakeChange(int change);

class StrShift
{
private:
    std::string text = "";

public:
    StrShift() = default;
    StrShift(std::string inputText);
    ~StrShift() = default;

    std::string getText() const;

    // Supported operators
    StrShift &operator=(const StrShift &other);
    StrShift &operator=(const std::string &inputStr);
    bool operator==(const StrShift &other) const;
    StrShift &operator<<(const int shift);
    StrShift &operator>>(const int shift);
    friend std::ostream &operator<<(std::ostream &os, const StrShift &obj);

    // Unsupported operators
    StrShift operator+(const StrShift &other) const = delete;
    StrShift operator-(const StrShift &other) const = delete;
    StrShift operator*(const StrShift &other) const = delete;
    StrShift operator/(const StrShift &other) const = delete;
};

#endif // __BO_CHALLENGE_CODE__