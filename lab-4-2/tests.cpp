#include <gtest/gtest.h>

#include "figures.hpp"
#include "array.hpp"

#include <iostream>
#include <sstream>

using namespace lab4;

TEST(FiguresTest, SquareTest) {
    double expectedArea = 9;
    Point expectedCenter = Point{1.5, 1.5};
    Square<double> a = Square<double>({0, 0}, {3, 3});
    EXPECT_LE(abs(static_cast<double>(a) - expectedArea), EPS);
    EXPECT_EQ(a.geometricCenter(), expectedCenter);
}

TEST(FiguresTest, TriangleTest) {
    double expectedArea = 1.7320508075688772;
    Point<float> expectedCenter = Point<float>{1.57735, 0};
    Triangle<float> a = Triangle<float>({1, 1}, {1, -1}, 1);
    EXPECT_LE(abs(static_cast<double>(a) - expectedArea), EPS);
    EXPECT_EQ(a.geometricCenter(), expectedCenter);
}

TEST(FiguresTest, RectangleTest) {
    double expectedArea = 2;
    Point<long double> expectedCenter = Point<long double>{2.5, 3};
    Rectangle<long double> a = Rectangle<long double>({2, 2}, {3, 4});
    EXPECT_LE(abs(static_cast<double>(a) - expectedArea), EPS);
    EXPECT_EQ(a.geometricCenter(), expectedCenter);
}

TEST(FiguresTest, PointTest) {
    Point<double> a{1, 1}, b{4, 5};
    EXPECT_TRUE(Point<double>::distance(a, b) - 5 < EPS);
    Point<double> expd = Point<double>{2.5, 3};
    EXPECT_EQ(Point<double>::mid(a, b), expd);
    Point<double> c{3, 4};
    expd = Point<double>{3. / 5, 4. / 5};
    EXPECT_EQ(Point<double>::normalize(c), expd);
    expd = Point<double>{0, 1};
    a = Point<double>{1, 0};
    EXPECT_EQ(Point<double>::rotate(a, PI/2), expd);
}

TEST(FiguresTest, ArrayTest) {
    Array<std::shared_ptr<Figure<double>>> array;
    Rectangle<double> a = Rectangle<double>({2, 2}, {3, 4});
    Triangle<double> b = Triangle<double>({1, 1}, {1, -1}, 1);
    Square<double> c = Square<double>({0, 0}, {3, 3});
    array.pushBack(std::make_shared<Rectangle<double>>(a));
    array.pushBack(std::make_shared<Triangle<double>>(b));
    array.pushBack(std::make_shared<Square<double>>(c));
    EXPECT_EQ(array.size(), 3);
    array.resize(1000);
    EXPECT_EQ(array.size(), 1000);
    array.erase(1);
    EXPECT_EQ(array.size(), 999);
}
