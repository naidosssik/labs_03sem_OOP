#include "figures.hpp"
#include "array.hpp"

#include <iostream>

using namespace lab4;

template<Number T>
class MainRoutine final {
private:
    void eraseFigure() {
        size_t n;
        std::cin >> n;
        n--;
        if (n >= data.size()) {
            std::cout << "There's no figure with index " << n + 1 << ".\n";
            return ;
        }
        data.erase(n);
    }

    void pushFigure() {
        std::string type;
        std::cin >> type;
        try {
            if (type == "square") {
                Square<T> sq;
                std::cin >> sq;
                data.pushBack(std::make_shared<Square<T>>(sq));
            } else if (type == "triangle") {
                Triangle<T> tr;
                std::cin >> tr;
                data.pushBack(std::make_shared<Triangle<T>>(tr));
            } else if (type == "rectangle") {
                Rectangle<T> rect;
                std::cin >> rect;
                data.pushBack(std::make_shared<Rectangle<T>>(rect));
            } else {
                std::cout << "Unknown figure name.\n";
                return;
            }
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
            return ;
        }
        std::cout << "Success.\n";
    }

    void wholeArea() {
        double area = 0;
        for (size_t i = 0; i < data.size(); i++) {
            area += static_cast<double>(*data[i]); 
        }
        std::cout << area << std::endl;
    }

    void info() {
        std::cout << "Info: \n";
        for (size_t i = 0; i < data.size(); i++) {
            std::cout << (i + 1) << ":\n";
            std::cout << "  area : " << static_cast<double>(*data[i]) << "\n" <<
                         "  geometric_center : " << data[i]->geometricCenter() << "\n"; 
        }
    }

    Array<std::shared_ptr<Figure<T> > > data;
public:
    void start() {
        std::string command;
        std::cout << "> ";
        std::cin >> command;
        while (command != "exit") {
            if (command == "push") {
                pushFigure();
            } else if (command == "info") {
                info();
            } else if (command == "erase") {
                eraseFigure();
            } else if (command == "area") {
                wholeArea();
            } else {
                std::cout << "Unknown command.\n";
            }
            std::cout << "> ";
            std::cin >> command;
        }
    }
};

int main() {
    MainRoutine<double> r;
    r.start();
}
