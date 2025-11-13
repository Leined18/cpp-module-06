#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
    public:
        virtual ~Base();
};

// declare functions implemented in identify.cpp
Base * generate(void);
void identify(Base* p);
void identify(Base& p);


#endif

