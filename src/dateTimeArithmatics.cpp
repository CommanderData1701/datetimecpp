#include "datetimecpp/util/dateTimeArithmatics.hpp"

bool isLeapYear(int year) noexcept {
    if (year % 4 == 0 && year % 100 != 0) {
        return true;
    } else if (year % 100 == 0) {
        return year % 400 == 0;
    } else {
        return false;
    }
}

int getDaysInMonth(int month, int year) noexcept {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else {
        return month < 8 ? 30 + (month % 2) : 31 - (month % 2);
    }
}
