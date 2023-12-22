#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>


class Eleven {
    public:

        Eleven();
        Eleven(const size_t &n, unsigned char t = 0);
        Eleven(const std::initializer_list<unsigned char> &t);
        Eleven(const std::string t);
 
        Eleven(const Eleven& other);
        Eleven(Eleven&& other) noexcept;
        virtual ~Eleven() noexcept;

        std::ostream &print(std::ostream &os);

        Eleven operator+ (const Eleven &other) const;
        Eleven operator- (const Eleven &other) const;
        Eleven operator= (const Eleven &other);
        bool operator< (const Eleven &other) const;
        bool operator> (const Eleven &other) const;
        bool operator<= (const Eleven &other) const;
        bool operator>= (const Eleven &other) const;
        bool operator != (const Eleven &other) const;
        bool operator== (const Eleven &other) const;

    private:
        size_t size;
        unsigned char *number;
        


};

bool isElevenDigit(const char &c);