#include <eleven.h>


Eleven::Eleven()
{
    digits.push_back(0);
}

Eleven::Eleven(const std::string &hexadecimal)
{
    for (char c : hexadecimal)
    {
        digits.push_back(charToHexDigit(c));
    }
    normalize();
}

Eleven::Eleven(unsigned char singleDigit)
{
    digits.push_back(singleDigit);
}

Eleven Eleven::operator+(const Eleven &other) const
{
    Eleven result;
    size_t maxSize = std::max(digits.size(), other.digits.size());
    unsigned char carry = 0;

    for (size_t i = 0; i < maxSize || carry > 0; ++i)
    {
        unsigned char sum = carry;
        if (i < digits.size())
            sum += digits[i];
        if (i < other.digits.size())
            sum += other.digits[i];

        carry = sum / 11;
        sum %= 11;

        result.digits.push_back(sum);
    }

    return result;
}

Eleven Eleven::operator-(const Eleven &other) const
{
    Eleven result;
    size_t maxSize = std::max(digits.size(), other.digits.size());
    int carry = 0;

    for (size_t i = 0; i < maxSize; ++i)
    {
        int diff = carry;
        if (i < digits.size())
            diff += digits[i];
        if (i < other.digits.size())
            diff -= other.digits[i];

        if (diff < 0)
        {
            diff += 11;
            carry = -1;
        }
        else
        {
            carry = 0;
        }

        result.digits.push_back(static_cast<unsigned char>(diff));
    }

    result.normalize();
    return result;
}

bool Eleven::operator==(const Eleven &other) const
{
    return digits == other.digits;
}

bool Eleven::operator!=(const Eleven &other) const
{
    return !(*this == other);
}

std::string Eleven::toHexadecimal() const
{
    std::string hex;
    for (unsigned char digit : digits)
    {
        hex += hexDigitToChar(digit);
    }
    return hex;
}

void Eleven::normalize()
{
    while (digits.size() > 1 && digits.back() == 0)
    {
        digits.pop_back();
    }
}

unsigned char Eleven::charToHexDigit(char c) const
{
    if (c >= '0' && c <= '9')
        return static_cast<unsigned char>(c - '0');
    else if (c >= 'A' && c <= 'A' + 10)
        return static_cast<unsigned char>(c - 'A' + 10);
    else if (c >= 'a' && c <= 'a' + 10)
        return static_cast<unsigned char>(c - 'a' + 10);
    else
        throw std::invalid_argument("Invalid hexadecimal character");
}

char Eleven::hexDigitToChar(unsigned char digit) const
{
    if (digit >= 0 && digit <= 9)
        return static_cast<char>(digit + '0');
    else if (digit >= 10 && digit <= 20)
        return static_cast<char>(digit + 'A' - 10);
    else
        throw std::invalid_argument("Invalid hexadecimal digit");
}

int main()
{
    Eleven num1("A12");
    Eleven num2("3B");

    Eleven sum = num1 + num2;
    Eleven diff = num1 - num2;

    std::cout << "num1 + num2 = " << sum.toHexadecimal() << std::endl;
    std::cout << "num1 - num2 = " << diff.toHexadecimal() << std::endl;

    if (num1 == num2)
    {
        std::cout << "num1 is equal to num2" << std::endl;
    }
    else
    {
        std::cout << "num1 is not equal to num2" << std::endl;
    }

    return 0;
}
