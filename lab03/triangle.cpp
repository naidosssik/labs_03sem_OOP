#include "triangle.hpp"

namespace figures {

Triangle::Triangle(const Point& vertex1, const Point& vertex2, const Point& vertex3)
    : _vertex1(vertex1), _vertex2(vertex2), _vertex3(vertex3) {
    
}

Triangle::Triangle(const double side1, const double side2, const double side3) {
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        throw std::invalid_argument("Sides of the triangle must be more than zero");
    }

    

    
}

Triangle::Triangle(const Triangle& other) noexcept
    : _vertex1(other._vertex1), _vertex2(other._vertex2), _vertex3(other._vertex3) {
    
}

Triangle::Triangle(Triangle&& other) noexcept {
    
}

Triangle& Triangle::operator=(const Triangle& other) noexcept {
    if (this == &other) return *this;
    
    // Здесь нужно добавить код для копирования данных из other в this
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    // Здесь нужно добавить код для перемещения ресурсов из other в this
    return *this;
}

figures::Point Triangle::calculate_geometric_center() const noexcept {
    // Реализация вычисления геометрического центра треугольника
}

double Triangle::calculate_perimeter() const noexcept {
    // Реализация вычисления периметра треугольника
}

double Triangle::calculate_area() const noexcept {
    // Реализация вычисления площади треугольника
}

bool Triangle::operator==(const Triangle& other) const {
    // Реализация оператора сравнения
}

bool Triangle::operator!=(const Triangle& other) const {
    // Реализация оператора неравенства
}

std::istream& operator>>(std::istream& is, Triangle& triangle) {
    Point vertex1, vertex2, vertex3;
    is >> vertex1 >> vertex2 >> vertex3;
    triangle = Triangle(vertex1, vertex2, vertex3);
    return is; 
}

std::ostream& operator<<(std::ostream& os, const Triangle& triangle) {
    os << "Vertex 1 coordinates: " << triangle._vertex1 << std::endl;
    os << "Vertex 2 coordinates: " << triangle._vertex2 << std::endl;
    os << "Vertex 3 coordinates: " << triangle._vertex3 << std::endl;
    // Добавьте вывод других характеристик треугольника
    return os;
}

}  // namespace figures
