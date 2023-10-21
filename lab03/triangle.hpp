#pragma once

#include "figure.hpp"
#include <iostream>

namespace figures {

class Triangle final : public Figure {
private:
    Point _vertex1;
    Point _vertex2;
    Point _vertex3;

public:
    Triangle() = default;
    Triangle(const Point&, const Point&, const Point&);
    Triangle(const double, const double, const double);
    Triangle(const Triangle&) noexcept;
    Triangle(Triangle&&) noexcept;

    Triangle& operator=(const Triangle&) noexcept;
    Triangle& operator=(Triangle&&) noexcept;

    virtual ~Triangle() = default;

    virtual figures::Point calculate_geometric_center() const noexcept override;
    virtual double calculate_perimeter() const noexcept override;
    virtual double calculate_area() const noexcept override;

    bool operator==(const Triangle&) const;
    bool operator!=(const Triangle&) const;

    friend std::istream& operator>>(std::istream&, Triangle&);
    friend std::ostream& operator<<(std::ostream&, const Triangle&);
};
};
