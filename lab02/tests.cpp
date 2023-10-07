#include <iostream>
#include <gtest/gtest.h>
#include "eleven.h"

TEST(ElevenTests, DefaultConstructor)
{
    Eleven e;
    EXPECT_EQ(e.size(), 0);
   
}

TEST(ElevenTests, ConstructorWithSizeAndValue)
{
    Eleven e(3, 'A');
    EXPECT_EQ(e.size(), 3);
    
}

TEST(ElevenTests, ConstructorWithInitializerList)
{
    Eleven e({ '1', 'A', '0' });
    EXPECT_EQ(e.size(), 3);
    
}

TEST(ElevenTests, OperatorAddition)
{
    Eleven e1({ '1', 'A', '0' });
    Eleven e2({ 'A', 'A', 'A' });
    Eleven result = e1 + e2;
    EXPECT_EQ(result.size(), 4);
   
}

TEST(ElevenTests, OperatorSubtraction)
{
    Eleven e1({ 'A', 'A', 'A' });
    Eleven e2({ '1', 'A', '0' });
    Eleven result = e1 - e2;
    EXPECT_EQ(result.size(), 3);

}
