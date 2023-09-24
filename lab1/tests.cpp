#include <gtest/gtest.h>
#include "foo.h"

TEST(test01, foo) {
    ASSERT_TRUE(print_number("abcklm56ld") == "56");
}

TEST(test02, foo) {
    ASSERT_TRUE(print_number("23buka101likep") == "23\n101\n");
}

TEST(test03, foo) {
    ASSERT_TRUE(print_number("iwannabeyouslave") == "");
}

TEST(test04, foo) {
    ASSERT_TRUE(print_number("abc!@#wannagonnajonna@()^ll") == "");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
