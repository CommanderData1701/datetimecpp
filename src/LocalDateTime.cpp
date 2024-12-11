/*
MIT License

Copyright (c) 2024 Linus Henke

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <cmath>
#include <cstdlib>
#include <sstream>

#include "datetimecpp/LocalDateTime.hpp"

LocalDateTimeIMPL::LocalDateTimeIMPL() noexcept : AbstractDateTimeIMPL() {
    this->setAttributes();
}

LocalDateTimeIMPL::LocalDateTimeIMPL(std::time_t seconds) noexcept :
    AbstractDateTimeIMPL(seconds) {
    this->setAttributes();
}

LocalDateTime makeLokalDateTime() noexcept {
    return LocalDateTime(new LocalDateTimeIMPL());
}

LocalDateTime makeLokalDateTime(std::time_t seconds) noexcept {
    return LocalDateTime(new LocalDateTimeIMPL(seconds));
}

void LocalDateTimeIMPL::setAttributes() noexcept {
    std::tm* ts = std::localtime(&this->absoluteSeconds);

    this->year = ts->tm_year + 1900;
    this->month = ts->tm_mon + 1;
    this->day = ts->tm_mday;
    this->hour = ts->tm_hour;
    this->minute = ts->tm_min;
    this->seconds = ts->tm_sec == 60 ? 59 : ts->tm_sec;

    delete ts;
    ts = nullptr;
}

void LocalDateTimeIMPL::setAbsoluteSeconds() noexcept {
    std::tm ts;

    ts.tm_year = this->year - 1900;
    ts.tm_mon = this->month - 1;
    ts.tm_mday = this->day;
    ts.tm_hour = this->hour;
    ts.tm_min = this->minute;
    ts.tm_sec = this->seconds;

    this->absoluteSeconds = std::mktime(&ts);
}

LocalDateTime operator+(const Timespan& span,
                        const AbstractDateTime& dt) noexcept {
    return makeLokalDateTime(span->getSeconds() + dt->getAbsoluteSeconds());
}

LocalDateTime operator+(AbstractDateTime dt, Timespan span) noexcept {
    return makeLokalDateTime(span->getSeconds() + dt->getAbsoluteSeconds());
}

std::string LocalDateTimeIMPL::toString() const noexcept {
    char year[5];
    std::sprintf(year, "%04d", this->year);

    char month[3];
    std::sprintf(month, "%02d", this->month);

    char day[3];
    std::sprintf(day, "%02d", this->day);

    char hour[3];
    std::sprintf(hour, "%02d", this->hour);

    char minute[3];
    std::sprintf(minute, "%02d", this->minute);

    char second[3];
    std::sprintf(second, "%02d", this->seconds);

    std::stringstream stringStream;
    stringStream << year << '-' << month << '-' << day << ' '
                 << hour << ':' << minute << ':' << second;

    return stringStream.str();
}

LocalDateTime LocalDateTimeIMPL::setYear(int year) noexcept {
    this->year = year;
    this->setAbsoluteSeconds();

    return LocalDateTime(this);
}

LocalDateTime LocalDateTimeIMPL::setMonth(int month) noexcept {
    this->month = 12 - std::abs(month) % 12;
    this->setAbsoluteSeconds();

    return LocalDateTime(this);
}

// TODO: implement
LocalDateTime LocalDateTimeIMPL::setDay(int day) noexcept {
    int daysInMonth;

    this->day = daysInMonth - std::abs(day) % daysInMonth;
    this->setAbsoluteSeconds();

    return LocalDateTime(this);
}
