#include <iostream>

#include "eleven.hpp"

Eleven::Eleven(): size{0}, number{nullptr}{}

bool isElevenDigit(const char &c) {
    return (('0' <= c && c <= '9') || (c == 'A'));
}
Eleven::Eleven(const size_t &n, unsigned char t) {
    
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
        if (!isElevenDigit(c)) {
            throw std::logic_error("Eleven digit can't be negative");
        }
        number[--i] = c;
    }
}


Eleven::Eleven(const std::string t) {
    size = t.size();
    number = new unsigned char[size];
    for (size_t i = size - 1, j = 0; j < size; i--, j++) {
        if (!isElevenDigit(t[i])) {
            throw std::logic_error("Eleven digit can't be negative");
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


Eleven Eleven::operator=(const Eleven &other)
{
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

Eleven Eleven::operator-(const Eleven &other) const {
    size_t resultSize = std::max(other.size, size)+1;
    std::string result (resultSize, '0');
    int carry = 0;
    for (size_t i = 0; i < resultSize; i++) {
        int d1, d2;
        if(i < size) {
            if(number[i] != 'A') {
                d1 = number[i] - '0';
            } 
            else {
                if(number[i] == 'A') {
                    d1 = 10;
                }
            }
        } 
        else {
            d1 = 0;
        }

        if(i < other.size) {
            if(other.number[i] != 'A') {
                d2 = other.number[i] - '0';
            } 
            else {
                if(other.number[i] == 'A') {
                    d2 = 10;
                }
            }
        } 
        else {
            d2 = 0;
        }
        int diff = d1 - d2 - carry;
        if(diff < 0) {
            diff += 11;
            carry = 1;

        } 
        else {
            carry = 0;
        }
        if(diff != 10) {
            result[i] = diff + '0';
        } 
        else {
            if(diff == 10) {
                result[i] = 'A';
            }
        }
        
    }
    if(result[resultSize - 1] == '0') {
        result.erase(resultSize - 1, 1);
    }
    std::reverse(result.begin(), result.end());
    return  Eleven(result);
}


 
Eleven Eleven::operator+(const Eleven &other) const {
    size_t resultSize = std::max(other.size, size)+1;
    std::string result (resultSize, '0');
    int carry = 0;
    for (size_t i = 0; i < resultSize; i++) {
        int d1, d2;
        if(i < size) {
            if(number[i] != 'A') {
                d1 = number[i] - '0';
            } 
            else {
                if(number[i] == 'A') {
                    d1 = 10;

                }
            }
        } 
        else {
            d1 = 0;
        }

        if(i < other.size) {
            if(other.number[i] != 'A') {
                d2 = other.number[i] - '0';
            } 
            else {
                if(other.number[i] == 'A') {
                    d2 = 10;

                }
            }
        } 
        else {
            d2 = 0;
        }
        int sum = d1 + d2 + carry;
        if(sum % 11 != 10) {
            result[i] = sum % 11 +'0';
        } 
        else {
            if(sum % 11 == 10) {
                result[i] = 'A';
            }
        }
        carry = sum / 11;
    }

    if(carry > 0) {
        if(carry != 10) {
            result[resultSize -1 ] = carry  + '0';
          
            
        } 
        else {
            if(carry == 10) {
                result[resultSize - 1] = 'A';
            }
        }
    }
    if(result[resultSize-1] == '0') {
        result.erase(resultSize - 1, 1);
    }

    std::reverse(result.begin(),result.end());
    return Eleven(result);

    
}

bool Eleven::operator==(const Eleven &other) const {
    if (&other == this) {
        return true;
    }
    if (size != other.size) {
        return false;
    }
    for (size_t i = 0; i < size; i++) {
        if (number[i] != other.number[i]) {
            return false;
        }
    }
    return true;
}

bool Eleven::operator!=(const Eleven &other) const {
    if (*this == other) {
        return false;
    }
    return true;
}

bool Eleven::operator<(const Eleven &other) const {
    if (&other == this) {
        return false;
    }
    if (size < other.size) {
        return true;
    }
    else if (size > other.size) {
        return false;
    }
    else {
        for (size_t i = size; i--;) {
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
    if (*this > other) {
        return false;
    }
    return true;
}

bool Eleven::operator>(const Eleven &other) const {
    if (*this < other || *this == other) {
        return false;
    }
    return true;
}

bool Eleven::operator>=(const Eleven &other) const {
    if (*this < other) {
        return false;
    }
    return true;
}

std::ostream &Eleven::print(std::ostream &os) {
    for (size_t i = size; i--;) {
        os << number[i];
    }
    os << std::endl;
    return os;
}

Eleven::~Eleven() noexcept {
    if (size > 0) {
        size = 0;
        delete[] number;
        number = nullptr;
    }
}