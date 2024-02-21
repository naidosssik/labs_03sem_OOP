#include "foo.hpp"

int main() {
    std::string str;
    while(std::getline(std::cin, str)) {
        std::cout << digitsFromStr(str) << std::endl;
    }

    return 0;
}
