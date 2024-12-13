#ifndef DATE_TIME_ARITHMETICS_HPP
#define DATE_TIME_ARITHMETICS_HPP

/**
 * Check if a year is a leap year.
 *
 * @param year The year to check.
 * @return True if the year is a leap year, false otherwise.
 */
bool isLeapYear(int year) noexcept;

/**
 * Get the number of days in a month.
 *
 * @param month The month to get the number of days for.
 * @param year The year to get the number of days for.
 * @return The number of days in the month.
 */
int daysInMonth(int month, int year) noexcept;

#endif  // DATE_TIME_ARITHMETICS_HPP
