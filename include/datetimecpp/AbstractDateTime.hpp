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

class AbstractDateTimeIMPL;
typedef std::shared_ptr<AbstractDateTimeIMPL> AbstractDateTime;

class AbstractDateTimeIMPL {
public:
    friend Timespan calculateDistance(AbstractDateTime datetime1,
                                      AbstractDateTime datetime2);
protected:
    AbstractDateTimeIMPL() noexcept;

    virtual void setAttributes() noexcept = 0;

    virtual std::string toString() const noexcept = 0;

    std::time_t miliseconds;
};

#endif  // ABSTRACT_DATE_TIME_HPP
