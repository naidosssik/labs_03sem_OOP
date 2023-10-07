#include <algorithm>
#include "eleven.h"

bool isEleven(const std::string &number)
{
    for(char digit : number) 
    {
        if(!isdigit(digit) && !(digit == 'A' || digit == 'a'))
            return false;
    }
    return true;
}

Eleven::Eleven(): _size(0), _array{nullptr} {}

Eleven::Eleven(const size_t &n, unsigned char t)
{
    std::cout << "Fill construction" << std::endl;
    _array = new unsigned char[n];
    for(size_t i = 0; i < n; ++i) 
    {
        _array[i] = t;
    }
    _size = n;
}

// "Initializer list construction"
Eleven::Eleven(const std::initializer_list<unsigned char> &t)
{
    _array = new unsigned char[t.size()];
    size_t i = 0;
    for(auto &c : t) 
    {
        if (!isEleven(std::string(1, c))) throw std::logic_error("not Eleven system");
        _array[i++] = c;
    }
    _size = t.size();
    
}

// "Copy string construction" 
Eleven::Eleven(const std::string &t)
{
    _array = new unsigned char[t.size()];
    _size = t.size();

    for(size_t i = 0; i < _size; ++i) 
    {
        _array[i] = t[i];
    }
}

// "Copy construction" 
Eleven::Eleven(const Eleven &other) 
{
    _size = other._size;
    _array = new unsigned char[_size];

    for(size_t i = 0; i < _size; ++i)
    {
        _array[i] = other._array[i];
    }
}

// "Move construction"
Eleven::Eleven(Eleven &&other) noexcept 
{
    _size = other._size;
    _array = other._array;
    
    other._size = 0;
    other._array = nullptr;
}

size_t Eleven::size() const noexcept 
{
    return _size;
}

unsigned char* Eleven::array() const noexcept 
{
    return _array;
}

bool Eleven::operator==(const Eleven &t) const 
{
    if (_size != t._size) 
    {
        return false;
    }
    for (size_t i = 0; i < _size; ++i) 
    {
        if (_array[i] != t._array[i])
        {
            return false;
        }
    }
    return true;
}

bool Eleven::operator==(const std::string &t) const 
{
    if (_size != t.size()) 
    {
        return false;
    }
    size_t i = _size - 1;
    for (char c : t)
    {
        if (c != _array[i])
        {
            return false;
        }
        --i;
    }
    return true;
}

bool Eleven::operator!=(const Eleven &t) const 
{
    return !(*this == t);
}

bool Eleven::operator!=(const std::string &t) const
{
    return !(*this == t);
}

bool Eleven::operator>(const Eleven &t) const 
{
    if (_size != t.size())
    {
        return _size > t.size();
    }
    for (size_t i = _size - 1; i >= 0; ++i)
    {
        if (_array[i] < t.array()[i])
        {
            return false;
        }
        return true;
    }
}

bool Eleven::operator>=(const Eleven &t) const 
{
    return (*this > t) || (*this == t);
}

bool Eleven::operator<(const Eleven &t) const 
{
    return !(*this >= t);
}

bool Eleven::operator<=(const Eleven &t) const 
{
    return !(*this > t);
}

void del_nul(std::string &s) 
{
    int count_zero = 0;
    size_t i = 0;
    while(s[i] == '0') {
        ++count_zero;
        ++i;
    }
    s.erase(0, count_zero);
    std::reverse(s.begin(), s.end());
}

Eleven Eleven::operator+(const Eleven &t) const
{
    size_t len = std::max(_size, t._size) + 1;
    std::string summ(len, '0');
    for (size_t i = 0; i < len - 1; ++i)
    {
        int summa = (((i < _size) ? _array[i] - '0' : 0) + ((i < t._size) ? t._array[i] - '0' : 0));
        summ[i + 1] = (summa / 11) + '0';
        summ[i] = (summ[i] - '0' + summa) % 11 + '0';
    }
    std::reverse(summ.begin(), summ.end());
    del_nul(summ);
    return Eleven(summ);
}

Eleven Eleven::operator-(const Eleven &t) const
{
    if (*this < t)
    {
        throw std::logic_error("Can't be negative");
    }
    if (*this == t)
    {
        return Eleven("0");
    }
    size_t len = std::max(_size, t._size);
    std::string raz(len, '0');
    for (size_t i = 0; i < len - 1; i++)
    {
        raz[i] += _array[i] - '0' - ((i < t._size) ? t._array[i] - '0' : 0);
        if (raz[i] - '0' < 0)
        {
            raz[i] += 11;
            raz[i + 1] -= 1;
        }
    }
    raz[len - 1] += _array[len - 1] - '0' - ((len == t._size) ? t._array[len - 1] - '0' : 0);
    std::reverse(raz.begin(), raz.end());
    del_nul(raz);
    return Eleven(raz);
}

std::ostream &Eleven::print(std::ostream &os)
{
    for(size_t i = 0; i < _size; ++i)
    {
        os << _array[i];
    }
    return os;
}

Eleven::~Eleven() noexcept
{
    if(_size > 0)
    {
        _size = 0;
        delete [] _array;
        _array = nullptr;
    }
}
