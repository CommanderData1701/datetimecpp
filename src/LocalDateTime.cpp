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
#include "datetimecpp/LocalDateTime.hpp"

LocalDateTimeIMPL::LocalDateTimeIMPL() noexcept : AbstractDateTimeIMPL() {
    this->setAttributes();
}

LocalDateTimeIMPL::LocalDateTimeIMPL(std::time_t miliseconds) noexcept :
    AbstractDateTimeIMPL(miliseconds) {
    this->setAttributes();
}

LocalDateTime makeLokalDateTime() noexcept {
    return LocalDateTime(new LocalDateTimeIMPL());
}

LocalDateTime makeLokalDateTime(std::time_t miliseconds) noexcept {
    return LocalDateTime(new LocalDateTimeIMPL(miliseconds));
}

void LocalDateTimeIMPL::setAttributes() noexcept {
    std::tm* ts = std::localtime(&this->miliseconds);

    this->year = ts->tm_year + 1900;
    this->month = ts->tm_mon + 1;
    this->day = ts->tm_mday;
    this->hour = ts->tm_hour;
    this->minute = ts->tm_min;
    this->seconds = ts->tm_sec == 60 ? 59 : ts->tm_sec;

    delete ts;
    ts = nullptr;
}

void LocalDateTimeIMPL::setMiliseconds() noexcept {
    std::tm ts;

    ts.tm_year = this->year - 1900;
    ts.tm_mon = this->month - 1;
    ts.tm_mday = this->day;
    ts.tm_hour = this->hour;
    ts.tm_min = this->minute;
    ts.tm_sec = this->seconds;

    this->miliseconds = std::mktime(&ts);
}
