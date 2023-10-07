#pragma once

#include <iostream>
#include <string>

class Eleven
{
public:
    Eleven();

    Eleven(const size_t & n, unsigned char t = 0);
    Eleven(const std::initializer_list<unsigned char> &t);
    Eleven(const std::string &t);
    Eleven(const Eleven &other);
    Eleven(Eleven &&other) noexcept;

    size_t size() const noexcept;
    unsigned char* array() const noexcept;

    //methods
    bool operator>(const Eleven &t) const;
    bool operator>=(const Eleven &t) const;
    bool operator<(const Eleven &t) const;
    bool operator<=(const Eleven &t) const;
    bool operator==(const Eleven &t) const; //с 11 с/с
    bool operator==(const std::string &t) const; //с любой строкой
    bool operator!=(const Eleven &t) const;
    bool operator!=(const std::string &t) const; //переполнение

    Eleven operator+(const Eleven &t) const;
    Eleven operator-(const Eleven &t) const;

    std::ostream& print(std::ostream& os);

    virtual ~Eleven() noexcept;

private:
    size_t _size;
    unsigned char *_array;
};
