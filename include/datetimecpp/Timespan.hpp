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
#ifndef TIMESPAN_HPP
#define TIMESPAN_HPP

#include <cmath>
#include <ctime>
#include <memory>

/**
 * TimespanIMPL is a proxy class which shall only be instanciated through a
 * smart pointer. It represents a span of time with the finest granularity being
 * seconds.
 */
class TimespanIMPL;
typedef std::shared_ptr<TimespanIMPL> Timespan;

class TimespanIMPL {
public:
    /**
     * <p>
     * Timespan objects should be created using a constructor function.
     * </p>
     *
     * @param miliseconds Miliseconds representing the timespan.
     * @return Constructed Timespan object
     */
    friend Timespan makeTimespan(std::time_t miliseconds) noexcept;

    /**
     * <p>
     * Return the timespan in years.
     * </p>
     *
     * @return timeSpanInYears
     */
    double getYears() const noexcept;

    /**
     * <p>
     * Return the timespan in months.
     * </p>
     *
     * @return timespanInMonths
     */
    double getMonths() const noexcept;

    /**
     * <p>
     * Return the timespan in days.
     * </p>
     *
     * @return timespanInDays
     */
    double getDays() const noexcept;

    /**
     * <p>
     * Return the timespan in hours.
     * </p>
     *
     * @return timespanInHours
     * @since 1.0
     */
    double getHours() const noexcept;

    /***
     * <p>
     * Return the timespan in minutes.
     * </p>
     *
     * @return timespanInMinutes
     * @since 1.0
     */
    double getMinutes() const noexcept;

    /**
     * <p>
     * Return the timespan in seconds.
     * </p>
     * 
     * @return timespanInSeconds
     * @since 1.0
     */
    std::time_t getSeconds() const noexcept;
private:
    /**
     * <p>
     * Constructor for creating a timespan from a number of seconds.
     * </p>
     *
     * @param seconds Timespan that shall be created in seconds
     * @since 1.0
     */
    TimespanIMPL(std::time_t seconds) noexcept;
    
    std::time_t seconds;

    static constexpr double SECONDS_IN_A_YEAR = 3.154e+7;
    static constexpr double SECONDS_IN_A_MONTH = 2.628e+6;
    static constexpr double SECONDS_IN_A_DAY = 8.64e+4;
    static constexpr double SECONDS_IN_AN_HOUR = 3.6e+3;
    static constexpr double SECONDS_IN_A_MINUTE = 60000;
};

Timespan makeTimespan(std::time_t seconds) noexcept;

#endif  // TIMESPAN_HPP
