#include <gtest/gtest.h>

#include "datetimecpp/util/dateTimeArithmatics.hpp"

TEST(TestLeapYear, TestSomeExamples) {
    ASSERT_TRUE(isLeapYear(2012));
    ASSERT_TRUE(isLeapYear(1904));
    ASSERT_FALSE(isLeapYear(1994));
    ASSERT_FALSE(isLeapYear(1870));
    ASSERT_FALSE(isLeapYear(2041));
    ASSERT_FALSE(isLeapYear(1695));
    ASSERT_FALSE(isLeapYear(1591));
    ASSERT_FALSE(isLeapYear(1835));
    ASSERT_FALSE(isLeapYear(1933));
    ASSERT_TRUE(isLeapYear(1972));
}

TEST(TestDaysInMoth, TestSomeExamples) {
    ASSERT_EQ(daysInMonth(1, 0), 31);
    ASSERT_EQ(daysInMonth(3, 2), 31);
    ASSERT_EQ(daysInMonth(4, 3), 30);
    ASSERT_EQ(daysInMonth(5, 4), 31);
    ASSERT_EQ(daysInMonth(6, 5), 30);
    ASSERT_EQ(daysInMonth(7, 6), 31);

    ASSERT_EQ(daysInMonth(8, 42), 31);
    ASSERT_EQ(daysInMonth(9, 42), 30);
    ASSERT_EQ(daysInMonth(10, 42), 31);
    ASSERT_EQ(daysInMonth(11, 42), 30);
    ASSERT_EQ(daysInMonth(12, 42), 31);

    ASSERT_EQ(daysInMonth(2, 2012), 29);
    ASSERT_EQ(daysInMonth(2, 2011), 28);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
