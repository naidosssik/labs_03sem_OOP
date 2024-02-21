#include <gtest/gtest.h>
#include "Eleven.hpp"

TEST(Test1, CopyConstructorTest) {
    Eleven num1("101A");
    Eleven num2(num1);
    ASSERT_TRUE(num1 == num2);
}

TEST(Test2, AssignmentTest) {
    Eleven num1({'2', '6', 'A'});
    Eleven num2 = num1;
    ASSERT_TRUE(num1 == num2);
}

TEST(Test3, InitListConstructorTest) {
    Eleven num1("2A3A");
    Eleven num2({'2', 'A', '3', 'A'});
    ASSERT_TRUE(num1 == num2);
}


TEST(Test3, EqualTest) {
    Eleven num1("AA34");
    Eleven num2({'A', '3', '3', '4'});
    ASSERT_FALSE(num1 == num2);
}

TEST(Test4, UnequalTest1) {
    Eleven num1("AA34");
    Eleven num2({'2', '4', '6', '4'});
    ASSERT_TRUE(num1 != num2);
}

TEST(Test5, UnequalTest2) {
    Eleven num1("A220");
    Eleven num2({'A', '2', '2', '0'});
    ASSERT_FALSE(num1 != num2);
}

TEST(Test6, LessTest) {
    Eleven num1("123");
    Eleven num2({'1', '2', 'A'});
    ASSERT_TRUE(num1 < num2);
}

TEST(Test7, LessEqualTest) {
    Eleven num1("5A4");
    Eleven num2({'A', '5', 'A'});
    ASSERT_TRUE(num1 <= num2);
}

TEST(Test8, MoreTest) {
    Eleven num1("156");
    Eleven num2({'A','2'});
    ASSERT_TRUE(num1 > num2);
}

TEST(Test9, MoreEqualTest) {
    Eleven num1("24567A9");
    Eleven num2({'2','4', '5', '6', '7', 'A', '9'});
    ASSERT_TRUE(num1 >= num2);
}

TEST(Test10, AddittionTest) {
    Eleven num1("5A");
    Eleven num2({'1', '6'});
    ASSERT_TRUE((num1 + num2) == Eleven("75"));
}

TEST(Test11, SubstractionTest1) {
    Eleven num1("76");
    Eleven num2({'7'});
    ASSERT_TRUE((num1 - num2) == Eleven("6A"));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
