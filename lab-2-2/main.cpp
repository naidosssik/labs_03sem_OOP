#include "Eleven.hpp"

int main() {
    std::string one;
    std::cin >> one;
    Eleven num1(one);

    Eleven num2(num1);
    num2.print(std::cout);

    return 0;
}
