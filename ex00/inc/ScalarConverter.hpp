#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include "MyException.hpp"
#include "TypeFactory.hpp"
	
/* 
- static_cast
- const_cast
- reinterpret_cast
- dynamic_cast
 */

class ScalarConverter
{
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        static void convert(const std::string &s);
};


#endif // SCALARCONVERTER_HPP