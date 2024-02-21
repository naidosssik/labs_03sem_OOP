#include "figures.hpp"
#include "array.hpp"

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

using namespace lab3;

TEST(test1, TriangleTest) {
    double expectedArea = 1.7320508075688772;
    Point expectedCenter = Point{1.57735, 0};
    Triangle a = Triangle({1, 1}, {1, -1}, 1);
    EXPECT_LE(abs(static_cast<double>(a) - expectedArea), EPS);
    EXPECT_EQ(a.geometricCenter(), expectedCenter);
}

TEST(test2, RectangleTest) {
    double expectedArea = 2;
    Point expectedCenter = Point{2.5, 3};
    Rectangle a = Rectangle({2, 2}, {3, 4});
    EXPECT_LE(abs(static_cast<double>(a) - expectedArea), EPS);
    EXPECT_EQ(a.geometricCenter(), expectedCenter);
}

TEST(test3, SquareTest) {
    double expectedArea = 9;
    Point expectedCenter = Point{1.5, 1.5};
    Square a = Square({0, 0}, {3, 3});
    EXPECT_LE(abs(static_cast<double>(a) - expectedArea), EPS);
    EXPECT_EQ(a.geometricCenter(), expectedCenter);
}

TEST(test4, PointTest) {
    Point a{1, 1}, b{4, 5};
    EXPECT_TRUE(Point::distance(a, b) - 5 < EPS);
    Point expd = Point{2.5, 3};
    EXPECT_EQ(Point::mid(a, b), expd);
    Point c{3, 4};
    expd = Point{3. / 5, 4. / 5};
    EXPECT_EQ(Point::normalize(c), expd);
    expd = Point{0, 1};
    a = Point{1, 0};
    EXPECT_EQ(Point::rotate(a, PI/2), expd);
}

TEST(test5, ArrayTest) {
    Array array;
    Rectangle a = Rectangle({2, 2}, {3, 2});
    Triangle b = Triangle({1, 1}, {1, -1}, 1);
    Square c = Square({0, 0}, {3, 3});
    Figure *f1 = &a,
           *f2 = &b,
           *f3 = &c;
    array.pushBack(f1);
    array.pushBack(f2);
    array.pushBack(f3);
    EXPECT_EQ(array.size(), 3);
    array.resize(1000);
    EXPECT_EQ(array.size(), 1000);
    array.erase(1);
    EXPECT_EQ(array.size(), 999);
    EXPECT_EQ(array[1], f3);
}
