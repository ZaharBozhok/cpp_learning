#include "gtest/gtest.h"

TEST(Inheritance, FirstTest)
{
    class Test
    {
    };
    ASSERT_EQ(sizeof(Test), 1);
}
