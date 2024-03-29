#include "Eleven.hpp"

bool isElevenDigit(const char &c) {
    return (('0' <= c && c <= '9') || (c == 'A'));
}

Eleven::Eleven() : size(0), number{nullptr} {
}

size_t Eleven::getSize() const {
    return size;
}

unsigned char *Eleven::getNumber() const {
    return number;
}

Eleven::Eleven(const size_t &n, unsigned char t) {
    // std::cout << "Fill constructor" << std::endl;
    number = new unsigned char[n];
    for (size_t i = 0; i < n; i++)
        number[i] = t;
    size = n;
}

Eleven::Eleven(const std::initializer_list<unsigned char> &t) {
   
    number = new unsigned char[t.size()];
    size = t.size();
    size_t i{size};
    for (unsigned char c : t) {
        if (!isElevenDigit(c))
        {
            throw std::logic_error("Eleven digit can't be negative and must be undenary digit");
        }
        number[--i] = c;
    }
}

Eleven::Eleven(const std::string t) {
    // std::cout << "Copy string constructor" << std::endl;
    size = t.size();
    number = new unsigned char[size];
    for (size_t i = size - 1, j = 0; j < size; i--, j++) {
        if (!isElevenDigit(t[i])) {
            throw std::logic_error("Eleven digit can't be negative and must be undenary digit");
        }
        number[i] = t[j];
    }
}

Eleven::Eleven(const Eleven &other) {

    size = other.size;
    number = new unsigned char[size];
    for (size_t i = 0; i < size; i++) {
        number[i] = other.number[i];
    }
}

Eleven::Eleven(Eleven &&other) noexcept {
    size = other.size;
    number = other.number;  

    other.size = 0;
    other.number = nullptr;
}


Eleven Eleven::operator=(const Eleven &other) {
    if (&other != this) {
        delete[] number;
        size = other.size;
        number = new unsigned char[size];
        for (size_t i = 0; i < size; i++) {
            number[i] = other.number[i];
        }
    }
    return *this;
}

Eleven Eleven::operator+(const Eleven &other) const {
    size_t resultSize = std::max(other.size, size) + 1;
    std::string result(resultSize, '0');
    int carry = 0;
    for (size_t i = 0; i < resultSize; i++) {
        int d1 = (i < size) ? (number[i] != 'A' ? (number[i] - '0') : 10) : 0;
        int d2 = (i < other.size) ? (other.number[i] != 'A' ? (other.number[i] - '0') : 10) : 0;

        int sum = d1 + d2 + carry;
        result[i] = ((sum % 11) != 10) ? (sum % 11) + '0' : 'A';
        carry = sum / 11;
    }
    if (carry > 0) {
        result[resultSize - 1] = (carry != 10) ? carry + '0' : 'A';
    }
    if (result[resultSize - 1] == '0') {
        result.erase(resultSize - 1, 1);
    }
    std::reverse(result.begin(), result.end());
    return Eleven(result);
}

Eleven Eleven::operator-(const Eleven &other) const {
    if (*this < other) {
        throw std::logic_error("Difference can't be negative");
    }
    size_t resultSize = std::max(other.size, size) + 1;
    std::string result(resultSize, '0');
    int carry = 0;
    for (size_t i = 0; i < resultSize; i++) {
        int d1 = (i < size) ? (number[i] != 'A' ? (number[i] - '0') : 10) : 0;
        int d2 = (i < other.size) ? (other.number[i] != 'A' ? (other.number[i] - '0') : 10) : 0;

        int diff = d1 - d2 - carry;
        if (diff < 0) {
            diff += 11;
            carry = 1;
        }
        else {
            carry = 0;
        }
        result[i] = (diff != 10) ? diff + '0' : 'A';
    }
    if (result[resultSize - 1] == '0') {
        result.erase(resultSize - 1, 1);
    }
    std::reverse(result.begin(), result.end());
    return Eleven(result);
}

bool Eleven::operator==(const Eleven &other) const {
    if (&other == this)
    {
        return true;
    }
    if (size != other.size)
    {
        return false;
    }
    for (size_t i = 0; i < size; i++)
    {
        if (number[i] != other.number[i])
        {
            return false;
        }
    }
    return true;
}

bool Eleven::operator!=(const Eleven &other) const {
    if (*this == other)
    {
        return false;
    }
    return true;
}

bool Eleven::operator<(const Eleven &other) const {
    if (&other == this)
    {
        return false;
    }

    if (size < other.size)
    {
        return true;
    }
    else if (size > other.size)
    {
        return false;
    }
    else
    {
        for (size_t i = size; i--;)
        {
            if (number[i] < other.number[i]) {
                return true;
            }
            else if (number[i] > other.number[i]) {
                return false;
            }
            else {
                continue;
            }
        }
        return false;
    }
}

bool Eleven::operator<=(const Eleven &other) const {
    if (*this > other)
    {
        return false;
    }
    return true;
}

bool Eleven::operator>(const Eleven other) const {
    if (*this < other || *this == other)
    {
        return false;
    }
    return true;
}

bool Eleven::operator>=(const Eleven other) const {
    if (*this < other)
    {
        return false;
    }
    return true;
}

std::ostream &Eleven::print(std::ostream &os) {
    for (size_t i = size; i--;)
    {
        os << number[i];
    }
    os << std::endl;
    return os;
}

Eleven::~Eleven() noexcept {
    if (size > 0)
    {
        size = 0;
        delete[] number;
        number = nullptr;
    }
}
