#ifndef ABSTRACT_DATE_TIME_HPP
#define ABSTRACT_DATE_TIME_HPP

#include <memory>
#include <string>

class AbstractDateTimeIMPL;
typedef std::shared_ptr<AbstractDateTimeIMPL> AbstractDateTime;

class AbstractDateTimeIMPL {
protected:
    AbstractDateTimeIMPL();

    virtual void setAttributes() = 0;

    virtual std::string toString() = 0;
};

#endif  // ABSTRACT_DATE_TIME_HPP
