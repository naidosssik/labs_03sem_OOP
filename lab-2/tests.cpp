#include <gtest/gtest.h>
#include "eleven.hpp"


TEST(test01, eleven) {
    Eleven num1("A4");
    Eleven num2(num1);
    ASSERT_TRUE(num1 == num2);
}

TEST(test02, eleven) {
    Eleven num1({'1', 'A', '2'});
    Eleven num2 = num1;
    ASSERT_TRUE(num1 == num2);
}

TEST(test03, eleven) {
    Eleven num1("5A"); //65
    Eleven num2({'1', '6'}); //17
    ASSERT_TRUE((num1 + num2) == Eleven("75")); //82
}

TEST(test04, Eleven) {
    Eleven num1(2,'B');
    Eleven num2({'1'});
    ASSERT_TRUE((num1 - num2) == Eleven("BA")); //142
}

TEST(test05, Eleven) {
    Eleven num1("3A");
    Eleven num2({'1'});
    ASSERT_TRUE(num1 != num2);
}

TEST(test06, Eleven) {
    Eleven num1(3,'A');
    Eleven num2("AA1");
    ASSERT_TRUE(num1 > num2);
}

TEST(test07, Eleven) {
    Eleven num1({'1', '1'});
    Eleven num2({'A', '2'});
    ASSERT_TRUE(num1 < num2);
}


TEST(test08, Eleven) {
    Eleven num1({'A','8', '5'});
    Eleven num2("A85");
    ASSERT_TRUE(num1 <= num2);
}

TEST(test09, Eleven) {
    Eleven num1({'1','A','7'});
    Eleven num2({'1'});
    ASSERT_FALSE(num2 >= num1);
}

TEST(test10, Eleven) {
    Eleven num1({'1'});
    Eleven num2({'1'});
    ASSERT_TRUE((num1 + num2) == Eleven({'2'}));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

