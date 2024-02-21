#pragma once

#include "point.hpp"

#include <algorithm>

namespace lab3 {

class Figure {
public:
    virtual Point geometricCenter() const = 0;
    virtual operator double () const = 0; 
};

class Rectangle : public Figure {

private:
    Point point1, point2;
    
public:
    Rectangle() = default;
    Rectangle(const Point& point1, const Point& point2);
    Rectangle(const Rectangle &rect);
    Rectangle(Rectangle &&rect);
    
    Rectangle& operator=(const Rectangle &rect);
    Rectangle& operator=(Rectangle &&rect);

    bool operator==(const Rectangle &other);

    operator double () const override;
    Point geometricCenter() const override;

    friend std::ostream& operator<<(std::ostream &stream, const Rectangle &rect);
    friend std::istream& operator>>(std::istream &stream, Rectangle &rect);
};


class Triangle : public Figure {
private:
    Point point1, point2;
    int orientation; // Either 1 or -1
public:
    Triangle() = default;
    Triangle(const Point& point1, const Point& point2, int orientation);
    Triangle(const Triangle &tr);
    Triangle(Triangle &&tr);
    
    Triangle& operator=(const Triangle &tr);
    Triangle& operator=(Triangle &&tr);

    bool operator==(const Triangle &other);

    operator double () const override;
    Point geometricCenter() const override;

    friend std::ostream& operator<<(std::ostream &stream, const Triangle &sq);
    friend std::istream& operator>>(std::istream &stream, Triangle &sq);   
};

class Square : public Figure {
private:
    // Two opposite points
    Point point1, point2;
public:
    Square() = default;
    Square(const Point& point1, const Point& point2);
    Square(const Square &sq);
    Square(Square &&sq);
    
    Square& operator=(const Square &sq);
    Square& operator=(Square &&sq);

    bool operator==(const Square &other);

    operator double () const override;
    Point geometricCenter() const override;

    friend std::ostream& operator<<(std::ostream &stream, const Square &sq);
    friend std::istream& operator>>(std::istream &stream, Square &sq);
};

} 
