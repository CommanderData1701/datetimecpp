#ifndef TIMESPAN_HPP
#define TIMESPAN_HPP

class Timespan {
public:
    unsigned int getYears();

    unsigned int getMonths();

    unsigned int getDays();

    unsigned int getHours();

    unsigned int getMinutes();

    unsigned int getSeconds();

    unsigned int getMiliseconds();



#ifdef PUBLIC_CONSTRUCTORS
    Timespan(unsigned int miliseconds);
private:
#else
private:
    Timespan(unsigned int miliseconds);
#endif  // PUBLIC_CONSTRUCTORS
    
    unsigned int miliseconds;
};

#endif  // TIMESPAN_HPP
