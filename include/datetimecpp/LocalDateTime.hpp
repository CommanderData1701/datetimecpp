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
#ifndef DATE_TIME_HPP
#define DATE_TIME_HPP

#include <memory>

#include "AbstractDateTime.hpp"
#include "Timespan.hpp"

/**
 * Class representing DateTime objects.
 */
class LocalDateTimeIMPL;
typedef std::shared_ptr<LocalDateTimeIMPL> LocalDateTime;

class LocalDateTimeIMPL final : public AbstractDateTimeIMPL {
public:
    friend LocalDateTime makeLokalDateTime() noexcept;

    friend LocalDateTime makeLokalDateTime(std::time_t seconds) noexcept;

    std::string toString() const noexcept override;

    LocalDateTime setYear(int year) noexcept;

    LocalDateTime setMonth(int month) noexcept;

    LocalDateTime setDay(int day) noexcept;

    LocalDateTime setHour(int hour) noexcept;

    LocalDateTime setMinute(int minute) noexcept;

    LocalDateTime setSecond(int second) noexcept;
private:
    LocalDateTimeIMPL() noexcept;

    LocalDateTimeIMPL(std::time_t miliseconds) noexcept;

    void setAttributes() noexcept override;
    void setAbsoluteSeconds() noexcept override;

    int year;
    int month;
    int day;
    int hour;
    int minute;
    int seconds;
};

LocalDateTime makeLocalDateTime() noexcept;

LocalDateTime makeLocalDateTime(std::time_t seconds) noexcept;

LocalDateTime operator+(const Timespan& span,
                        const AbstractDateTime& dt) noexcept;

LocalDateTime operator+(const AbstractDateTime& dt,
                        const Timespan& span) noexcept;

#endif  // DATE_TIME_HPP
