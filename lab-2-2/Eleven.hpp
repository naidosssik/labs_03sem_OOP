#include <iostream>
#include <cstring>
#include <algorithm>

bool isElevenDigit(const char &c);

class Eleven {
public:
    Eleven();                                              
    size_t getSize() const;
    unsigned char *getNumber() const;

    Eleven(const size_t &n, unsigned char t = 0);          
    Eleven(const std::initializer_list<unsigned char> &t); 
    Eleven(const std::string t);                           
    Eleven(const Eleven &other);                           
    Eleven(Eleven &&other) noexcept;                       //* Move constructor
    std::ostream &print(std::ostream &os);

    Eleven operator=(const Eleven &other);                 
    Eleven operator+(const Eleven &other) const;           
    Eleven operator-(const Eleven &other) const;           
    bool operator==(const Eleven &other) const;            
    bool operator!=(const Eleven &other) const;            
    bool operator<(const Eleven &other) const;             
    bool operator<=(const Eleven &other) const;            
    bool operator>(const Eleven other) const;             
    bool operator>=(const Eleven other) const;             

    ~Eleven() noexcept; 

private:
    size_t size;
    unsigned char *number;
};
