#pragma once

#include <iostream>
#include <vector>
#include <string>

class Eleven
{
public:
    Eleven();
    Eleven(const std::string &hexadecimal);
    Eleven(unsigned char singleDigit);

    Eleven operator+(const Eleven &other) const;
    Eleven operator-(const Eleven &other) const;
    bool operator==(const Eleven &other) const;
    bool operator!=(const Eleven &other) const;

    std::string toHexadecimal() const;

private:
    std::vector<unsigned char> digits;
    void normalize();
    unsigned char charToHexDigit(char c) const;
    char hexDigitToChar(unsigned char digit) const;
};
