#include "foo.hpp"

std::string digitsFromStr(std::string_view str) {
    std::string result;
    for (unsigned long i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            result += str[i];
        }
    }
    return result;
}
