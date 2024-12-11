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
#ifndef ABSTRACT_DATE_TIME_HPP
#define ABSTRACT_DATE_TIME_HPP

#include <memory>
#include <string>
#include <ctime>

#include "Timespan.hpp"

/**
 * A base class for representing all DateTime objects in this library. They all
 * share unix time as a common measure.
 */
class AbstractDateTimeIMPL;
typedef std::shared_ptr<AbstractDateTimeIMPL> AbstractDateTime;

class AbstractDateTimeIMPL {
public:
    /**
     * <p>
     * Get the string representation of the underlying object.
     * </p>
     *
     * @return String representation of the object.
     */
    virtual std::string toString() const noexcept = 0;

    /**
     * <p>
     * Return the absolute time in unix time.
     * </p>
     *
     * @return Absolute time of the object
     */
    std::time_t getAbsoluteSeconds() const noexcept;

    /**
     * <p>
     * Overload the - operator so that it returns the distance between two 
     * DateTimeObjects. The operator is abelian in this case.
     * </p>
     *
     * @param first One of the elements of difference calculation
     * @param second One of the elements of difference calculation
     * @return Distance in form of a Timespan object
     */
    friend Timespan operator-(const AbstractDateTime& first,
                              const AbstractDateTime& second) noexcept;

    /**
     * <p>
     * Overloading the == operator, which checks if they represent the same
     * point in time.
     * </p>
     *
     * @param first One of the elements that shall be compared
     * @param second One of the elements that shall be compared
     * @return True if absoluteSeconds is the same for both
     */
    friend bool operator==(const AbstractDateTime& first,
                           const AbstractDateTime& second) noexcept;

    /**
     * <p>
     * Overloading the <= operator, which checks if the lhs is earlier or at the
     * same time as the rhs.
     * </p>
     *
     * @param first LHS of the comparison
     * @param second RHS of the comparison
     * @return True if lhs is earlier or at the same time as rhs.
     */
    friend bool operator<=(const AbstractDateTime& first,
                           const AbstractDateTime& second) noexcept;
    
    /**
     * <p>
     * Overloading the >= operator, which checks if the lhs is later or at the
     * same time as the rhs.
     * </p>
     *
     * @param first LHS of the comparison
     * @param second RHS of the comparison
     * @return True if lhs is later or at the same time as rhs.
     */
    friend bool operator>=(const AbstractDateTime& first,
                           const AbstractDateTime& second) noexcept;

    /**
     * <p>
     * Overloading the < operator, which checks if the lhs is earlier then the
     * rhs.
     * </p>
     *
     * @param first LHS of the comparison
     * @param second RHS of the comparison
     * @return True if lhs is earlier as rhs.
     */
    friend bool operator<(const AbstractDateTime& first,
                          const AbstractDateTime& second) noexcept;

    /**
     * <p>
     * Overloading the > operator, which checks if the lhs is later then the
     * rhs.
     * </p>
     *
     * @param first LHS of the comparison
     * @param second RHS of the comparison
     * @return True if lhs is later as rhs.
     */
    friend bool operator>(const AbstractDateTime& first,
                          const AbstractDateTime& second) noexcept;
protected:
    /**
     * <p>
     * Constructor that fetches the current local time of the system.
     * </p>
     */
    AbstractDateTimeIMPL() noexcept;

    /**
     * <p>
     * Constructor that constructs a new {@code AbstractDateTimeIMPL} object
     * from a given absolute time in seconds.
     * </p>
     *
     * @param seconds Seconds passed since the unix time stamp.
     */
    AbstractDateTimeIMPL(std::time_t seconds) noexcept;

    /**
     * <p>
     * Set the absolute time according to the fields of the derived class.
     * </p>
     */
    virtual void setAbsoluteSeconds() noexcept = 0;

    /**
     * <p>
     * Set the fields of the derived class according to the absolute time.
     * </p>
     */
    virtual void setAttributes() noexcept = 0;

    /**
     * Seconds passed since 00:00 hours, Jan 1, 1970 UTC.
     */
    std::time_t absoluteSeconds;
};

#endif  // ABSTRACT_DATE_TIME_HPP
