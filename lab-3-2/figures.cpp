#include "figures.hpp"

namespace lab3 {

Rectangle::Rectangle(const Point& point1, const Point& point2) {
    if (abs(point1.x - point2.x) <= EPS && abs(point1.y - point2.y) <= EPS ) {
        throw std::invalid_argument("Bad points.");
    }
    this->point1 = point1;
    this->point2 = point2;
}

Rectangle::Rectangle(const Rectangle &rect) {
    point1 = rect.point1;
    point2 = rect.point2;
}

Rectangle::Rectangle(Rectangle &&rect) {
    point1 = rect.point1;
    point2 = rect.point2;
}
    
Rectangle& Rectangle::operator=(const Rectangle &rect) {
    point1 = rect.point1;
    point2 = rect.point2;
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle &&rect) {
    point1 = rect.point1;
    point2 = rect.point2;
    return *this;
}

bool Rectangle::operator==(const Rectangle &other) {
    return point1 == other.point1 && point2 == other.point2;
}

Rectangle::operator double () const {
    return abs(point1.y - point2.y) * abs(point1.x - point2.x);
}

Point Rectangle::geometricCenter() const {
    return Point::mid(point1, point2);
}

std::ostream& operator<<(std::ostream &stream, const Rectangle &rect) {
    double deltaX = rect.point2.x - rect.point1.x, deltaY = rect.point2.y - rect.point1.y;
    stream << "Rectangle[ " << rect.point1 << " " << rect.point1 + Point{deltaX, 0} << " " <<
              rect.point1 + Point{0, deltaY} << " " << rect.point2 << " ]";
    return stream;
}

std::istream& operator>>(std::istream &stream, Rectangle &rect) {
    Point p1, p2;
    stream >> p1 >> p2;
    rect = Rectangle(p1, p2);
    return stream;
}



// треугольник

Triangle::Triangle(const Point& point1, const Point& point2, int orientation) {
    this->point1 = point1;
    this->point2 = point2;
    this->orientation = orientation;
}

Triangle::Triangle(const Triangle &tr) {
    point1 = tr.point1;
    point2 = tr.point2;
    orientation = tr.orientation;
}

Triangle::Triangle(Triangle &&tr) {
    point1 = tr.point1;
    point2 = tr.point2;
    orientation = tr.orientation;
}

Triangle& Triangle::operator=(const Triangle &tr) {
    point1 = tr.point1;
    point2 = tr.point2;
    orientation = tr.orientation;
    return *this;
}

Triangle& Triangle::operator=(Triangle &&tr) {
    point1 = tr.point1;
    point2 = tr.point2;
    orientation = tr.orientation;
    return *this;
}
    
bool Triangle::operator==(const Triangle &other) {
    return point1 == other.point1 && point2 == other.point2 && orientation == other.orientation;
}

Triangle::operator double () const {
    return sqrt(3) / 4 * std::pow(Point::distance(point1, point2), 2);
}

Point Triangle::geometricCenter() const {
    Point point3 = point2 + Point::rotate(point2 - point1, 2 * PI / 3 * orientation);
    return Point::mid(point1, point2) + (1. / 3.) * (point3 - Point::mid(point1, point2));
}

std::ostream& operator<<(std::ostream &stream, const Triangle &tr) {
    Point point3 = tr.point2 + Point::rotate(tr.point2 - tr.point1, 2 * PI / 3 * tr.orientation);
    stream << "Triangle[ " << tr.point1 << " " << tr.point2 << " " << point3 << " ]";
    return stream;
}

std::istream& operator>>(std::istream &stream, Triangle &tr) {
    Point p1, p2;
    int orientation;
    stream >> p1 >> p2 >> orientation;
    tr = Triangle(p1, p2, orientation);
    return stream;
}


// квадрат

Square::Square(const Point& point1, const Point& point2) {
    if (abs(abs(point1.x - point2.x) - abs(point1.y - point2.y)) >= EPS) {
        throw std::invalid_argument("Bad points.");
    }
    this->point1 = point1;
    this->point2 = point2;
}

Square::Square(const Square &sq) {
    point1 = sq.point1;
    point2 = sq.point2;
}

Square::Square(Square &&sq) {
    point1 = sq.point1;
    point2 = sq.point2;
}
    
Square& Square::operator=(const Square &sq) {
    point1 = sq.point1;
    point2 = sq.point2;
    return *this;
}

Square& Square::operator=(Square &&sq) {
    point1 = sq.point1;
    point2 = sq.point2;
    return *this;
}

bool Square::operator==(const Square &other) {
    return point1 == other.point1 && point2 == other.point2;
}

Square::operator double () const {
    return std::pow(Point::distance(point1, point2), 2) / 2;
}

Point Square::geometricCenter() const {
    return Point::mid(point1, point2);
}

std::ostream& operator<<(std::ostream &stream, const Square &sq) {
    double deltaX = sq.point2.x - sq.point1.x, deltaY = sq.point2.y - sq.point1.y;
    stream << "Square[ " << sq.point1 << " " << sq.point1 + Point{deltaX, 0} << " " <<
              sq.point1 + Point{0, deltaY} << " " << sq.point2 << " ]";
    return stream;
}

std::istream& operator>>(std::istream &stream, Square &sq) {
    Point p1, p2;
    stream >> p1 >> p2;
    sq = Square(p1, p2);
    return stream;
}

}
