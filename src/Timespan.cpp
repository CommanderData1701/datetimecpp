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
#include "datetimecpp/Timespan.hpp"

TimespanIMPL::TimespanIMPL(std::time_t miliseconds) noexcept {
    this->miliseconds = miliseconds;
}

Timespan makeTimespan(std::time_t miliseconds) noexcept {
    return Timespan(new TimespanIMPL(miliseconds));
}

double TimespanIMPL::getYears() const noexcept {
    return 1.0 * this->miliseconds / MILISECONDS_IN_A_YEAR;
}

double TimespanIMPL::getMonths() const noexcept {
    return 1.0 * this->miliseconds / MILISECONDS_IN_A_MONTH;
}

double TimespanIMPL::getHours() const noexcept {
    return 1.0 * this->miliseconds / MILISECONDS_IN_AN_HOUR;
}

double TimespanIMPL::getMinutes() const noexcept {
    return 1.0 * this->miliseconds / MILISECONDS_IN_A_MINUTE;
}

double TimespanIMPL::getSeconds() const noexcept {
    return 1.0 * this->miliseconds / MILISECONDS_IN_A_SECOND;
}

unsigned int TimespanIMPL::getMiliseconds() const noexcept {
    return this->miliseconds;
}
