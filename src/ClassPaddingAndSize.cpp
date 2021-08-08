#include "gtest/gtest.h"
#include <tuple>
#ifndef NDEBUG
#include "utils.h"
#endif

TEST(ClassPaddingAndSize, char_and_short_aligned_to_4bytes)
{
    std::tuple<char, short int> tup('a', 1);
#ifndef NDEBUG
    printTupleInfo(tup);
#endif
    ASSERT_EQ(sizeof(tup), 4);
}

TEST(ClassPaddingAndSize, short_and_char_and_int_aligned_to_8bytes)
{
    std::tuple<short int, char, int> tup(1, 'a', 1);
#ifndef NDEBUG
    printTupleInfo(tup);
#endif
    ASSERT_EQ(sizeof(tup), 8);
}

TEST(ClassPaddingAndSize, char_and_double_and_int_aligned_to_24bytes)
{
    std::tuple<char, double, int> tup(1, 1.2, 1);
#ifndef NDEBUG
    printTupleInfo(tup);
#endif
    ASSERT_EQ(sizeof(tup), 3 * 8);
}

TEST(ClassPaddingAndSize, double_and_int_and_char_aligned_to_16bytes)
{
    std::tuple<double, int, char> tup(1.2, 1, 'a');
#ifndef NDEBUG
    printTupleInfo(tup);
#endif
    ASSERT_EQ(sizeof(tup), 2 * 8);
}