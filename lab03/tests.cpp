#include <gtest/gtest.h>
#include "rectangle.hpp"
#include "rectangle.cpp"
#include "square.hpp"
#include "square.cpp"

using namespace figures;

TEST(constructor_test, without_exception_test_1) {
    ASSERT_NO_THROW(Rectangle(Point(0, 0), Point(1, 0), Point(0,1), Point(1, 1)));
}

TEST(assigment_operator_test, move_assigment_test) {
    Rectangle test_1 (Point(1, 1), Point(10, 1), Point(1, 5), Point(10, 5));
    Rectangle test_2 = std::move(test_1);

    EXPECT_TRUE(test_1 == test_2);
    EXPECT_DOUBLE_EQ(test_1.get_length(), test_2.get_length());
    EXPECT_DOUBLE_EQ(test_1.get_width(), test_2.get_width());
}

TEST(calculate_geometric_center_test, calculate_geometric_center_test_1) {
    Rectangle test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));
    Point center_test = test_1.calculate_geometric_center();

    EXPECT_DOUBLE_EQ(center_test.get_x_cord(), 1);
    EXPECT_DOUBLE_EQ(center_test.get_y_cord(), 1);
}

TEST(calculate_geometric_center_test, calculate_geometric_center_test_2) {
    Rectangle test_1 (Point(1, 1), Point(10, 1), Point(1, 5), Point(10, 5));
    Point center_test = test_1.calculate_geometric_center();

    EXPECT_DOUBLE_EQ(center_test.get_x_cord(), 5.5);
    EXPECT_DOUBLE_EQ(center_test.get_y_cord(), 3);
}

TEST(calculate_perimeter_test, calculate_perimeter_test_1) {
    Rectangle test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));

    EXPECT_DOUBLE_EQ(test_1.calculate_perimeter(), 8);
}

TEST(calculate_perimeter_test, calculate_perimeter_test_2) {
    Rectangle test_1 (5, 10);

    EXPECT_DOUBLE_EQ(test_1.calculate_perimeter(), 30);
}

TEST(calculate_area_test, calculate_area_test_1) {
    Rectangle test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));

    EXPECT_DOUBLE_EQ(test_1.calculate_area(), 4);
}

TEST(calculate_area_test, calculate_area_test_2) {
    Rectangle test_1 (5, 10);

    EXPECT_DOUBLE_EQ(test_1.calculate_area(), 50);
}

TEST(get_lenth_test, get_length_test_1) {
    Rectangle test_1 (Point(1, 1), Point(10, 1), Point(1, 5), Point(10, 5));

    EXPECT_DOUBLE_EQ(test_1.get_length(), 9);
}

TEST(get_lenth_test, get_length_test_2) {
    Rectangle test_1 (4.57, 2.28);

    EXPECT_DOUBLE_EQ(test_1.get_length(), 4.57);
}


TEST(constructor_test, without_exception_test_1) {
    ASSERT_NO_THROW(Square(Point(0, 0), Point(1, 0), Point(0,1), Point(1, 1)));
}

TEST(constructor_test, without_exception_test_2) {
    ASSERT_NO_THROW(Square(Point(1.5, 1.5), Point(5.5, 1.5), Point(1.5, 5.5), Point(5.5, 5.5)));
}

TEST(constructor_test, with_exception_test_1) {
    ASSERT_THROW(Square(Point(0, 1), Point(-1, 1), Point(41.431, 5), Point(0, -45)), std::invalid_argument);
}

TEST(constructor_test, with_exception_test_2) {
    ASSERT_THROW(Square(Point(3.4, 43), Point(2, 78), Point(-31, 5), Point(34, 49)), std::invalid_argument);
}

TEST(side_constructor_test, without_exception_test_1) {
    ASSERT_NO_THROW(Square(5));
}

TEST(side_constructor_test, without_exception_test_2) {
    ASSERT_NO_THROW(Square(4.65));
}

TEST(side_constructor_test, with_exception_test_1) {
    ASSERT_THROW(Square(0), std::invalid_argument);
}

TEST(side_constructor_test, with_exception_test_2) {
    ASSERT_THROW(Square(-43.685), std::invalid_argument);
}

TEST(copy_constructor_test, other_square_copy_test) {
    Square test_1 (Point(0, 0), Point(1, 0), Point(0,1), Point(1, 1));
    Square test_2 (test_1);

    EXPECT_TRUE(test_1 == test_2);
    EXPECT_DOUBLE_EQ(test_1.get_side(), test_2.get_side());
}

TEST(move_constructor_test, other_square_move_test) {
    Square test_1 (Point(0, 0), Point(1, 0), Point(0,1), Point(1, 1));
    Square test_2 (std::move(test_1));

    EXPECT_TRUE(test_1 == test_2);
    EXPECT_DOUBLE_EQ(test_1.get_side(), test_2.get_side());
}

TEST(assigment_operator_test, copy_assigment_test) {
    Square test_1 (Point(0, 0), Point(1, 0), Point(0,1), Point(1, 1));
    Square test_2 = test_1;

    EXPECT_TRUE(test_1 == test_2);
    EXPECT_DOUBLE_EQ(test_1.get_side(), test_2.get_side());
}

TEST(assigment_operator_test, move_assigment_test) {
    Square test_1 (Point(0, 0), Point(1, 0), Point(0,1), Point(1, 1));
    Square test_2 = std::move(test_1);

    EXPECT_TRUE(test_1 == test_2);
    EXPECT_DOUBLE_EQ(test_1.get_side(), test_2.get_side());
}

TEST(calculate_geometric_center_test, calculate_geometric_center_test_1) {
    Square test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));
    Point center_test = test_1.calculate_geometric_center();

    EXPECT_DOUBLE_EQ(center_test.get_x_cord(), 1);
    EXPECT_DOUBLE_EQ(center_test.get_y_cord(), 1);
}

TEST(calculate_geometric_center_test, calculate_geometric_center_test_2) {
    Square test_1 (Point(0, 0), Point(9, 0), Point(0,9), Point(9, 9));
    Point center_test = test_1.calculate_geometric_center();

    EXPECT_DOUBLE_EQ(center_test.get_x_cord(), 4.5);
    EXPECT_DOUBLE_EQ(center_test.get_y_cord(), 4.5);
}


TEST(calculate_area_test, calculate_area_test_2) {
    Square test_1 (5.65);

    EXPECT_DOUBLE_EQ(test_1.calculate_area(), 31.9225);
}

TEST(get_side_test, get_side_test_1) {
    Square test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));

    EXPECT_DOUBLE_EQ(test_1.get_side(), 2);
}

TEST(get_side_test, get_side_test_2) {
    Square test_1 (5.678);

    EXPECT_DOUBLE_EQ(test_1.get_side(), 5.678);
}

TEST(operator_double_test, operator_double_test_1) {
    Square test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));
    double operator_double_test_val = double(test_1);

    EXPECT_DOUBLE_EQ(operator_double_test_val, 4);
}

TEST(operator_double_test, operator_double_test_2) {
    Square test_1 (5.65);
    double operator_double_test_val = double(test_1);

    EXPECT_DOUBLE_EQ(operator_double_test_val, 31.9225);
}

TEST(equal_operator_test, true_return_1) {
    Square test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));
    Square test_2 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));

    EXPECT_TRUE(test_1 == test_2);
}

TEST(equal_operator_test, true_return_2) {
    Square test_1 (5.68);
    Square test_2 (5.68);

    EXPECT_TRUE(test_1 == test_2);
}

TEST(equal_operator_test, false_return_1) {
    Square test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));
    Square test_2 (Point(0, 0), Point(4, 0), Point(0,4), Point(4, 4));

    EXPECT_FALSE(test_1 == test_2);
}

TEST(equal_operator_test, false_return_2) {
    Square test_1 (6.568);
    Square test_2 (7.4254);

    EXPECT_FALSE(test_1 == test_2);
}


TEST(non_equal_operator_test, false_return_1) {
    Square test_1 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));
    Square test_2 (Point(0, 0), Point(2, 0), Point(0,2), Point(2, 2));

    EXPECT_FALSE(test_1 != test_2);
}

TEST(non_equal_operator_test, false_return_2) {
    Square test_1 (5.68);
    Square test_2 (5.68);

    EXPECT_FALSE(test_1 != test_2);
}

TEST(rotated_square_tests, constructor_test_without_exception) {
    ASSERT_NO_THROW(Square(Point(2, 2), Point(4, 1), Point(3, 4), Point(5, 3)));
}

TEST(rotated_square_tests, copy_constructor_test) {
    Square test_1 (Point(2, 2), Point(4, 1), Point(3, 4), Point(5, 3));
    Square test_2 (test_1);

    EXPECT_TRUE(test_1 == test_2);
    EXPECT_DOUBLE_EQ(test_1.get_side(), test_2.get_side());
}

TEST(rotated_square_tests, move_constructor_test) {
    Square test_1 (Point(2, 2), Point(4, 1), Point(3, 4), Point(5, 3));
    Square test_2 (std::move(test_1));

    EXPECT_TRUE(test_1 == test_2);
    EXPECT_DOUBLE_EQ(test_1.get_side(), test_2.get_side());
}

TEST(rotated_square_tests, assigment_operator_copy_test) {
    Square test_1 (Point(2, 2), Point(4, 1), Point(3, 4), Point(5, 3));
    Square test_2 = test_1;

    EXPECT_TRUE(test_1 == test_2);
    EXPECT_DOUBLE_EQ(test_1.get_side(), test_2.get_side());
}


TEST(rotated_square_tests, operator_double_test) {
    Square test_1 (Point(2, 2), Point(4, 1), Point(3, 4), Point(5, 3));
    double operator_double_test_val = double(test_1);

    EXPECT_DOUBLE_EQ(operator_double_test_val, 5);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}