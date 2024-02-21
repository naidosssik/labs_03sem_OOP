#include <gtest/gtest.h>

#include "foo.hpp"

TEST(test01, Empty) {
    ASSERT_TRUE(digitsFromStr("") == "");
    ASSERT_TRUE(digitsFromStr("     ") == "");
    ASSERT_TRUE(digitsFromStr("           ") == "");
    ASSERT_TRUE(digitsFromStr("                ") == "");
}

TEST(test02, DigitTest) {
    ASSERT_TRUE(digitsFromStr("11") == "11");
    ASSERT_TRUE(digitsFromStr("129012901291") == "129012901291");
    ASSERT_TRUE(digitsFromStr("11111111111111111111111111") == "11111111111111111111111111");
    ASSERT_TRUE(digitsFromStr("123456789101112") == "123456789101112");
}


TEST(test03, NumbersTest) {
    ASSERT_TRUE(digitsFromStr("5 66 777 8888 99999") == "566777888899999");
    ASSERT_TRUE(digitsFromStr("1 12 3 33 5 5 5 ") == "112333555");
    ASSERT_TRUE(digitsFromStr("543421 32323  12312   1 3   13") == "54342132323123121313");
    ASSERT_TRUE(digitsFromStr("49494 99  494    4 9 4499   49") == "494949949449449949");
}

TEST(test04, MixTest) {
    ASSERT_TRUE(digitsFromStr("with attention 2u 3 hundrends and 54 bucks  ") == "2354");
    ASSERT_TRUE(digitsFromStr(" a2 b2c 23 d35 e  ") == "222335");
    ASSERT_TRUE(digitsFromStr("!!!!wfn(78*27)uhrbe378ey2y") == "78273782");
    ASSERT_TRUE(digitsFromStr("qwertyuiopasdfghjklzxcvbnm") == "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
