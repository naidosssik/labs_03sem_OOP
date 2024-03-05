#include "list.hpp"

int Factorial(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return n * Factorial(n - 1);
}

int main() {
    std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>, 10> > map;
    for (int i = 0; i < 10; ++i) {
        map[i] = Factorial(i);
    }
    std::cout << "Map with allocator:" << std::endl;
    for (const auto& pair : map) {
        std::cout << "key: " << pair.first << " - " << "value: " << pair.second << std::endl;
    }

    List<int, Allocator<std::pair<const int, int>, 10> > list;
    for (int i = 0; i < 10; ++i) {
        list.PushBack(i * 5);
    }
    std::cout << "List with allocator:" << std::endl;
    for (const auto& value : list) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}