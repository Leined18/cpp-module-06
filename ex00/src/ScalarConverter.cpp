#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &s)
{
    try {
        TypeFactory typeFactory;
        TypeFactory::eType type = typeFactory.detectType(s);
        std::cout << typeFactory.castToString(s, type) << std::endl;
    } 
    catch (const MyException &e) {
        std::cout << e.what() << std::endl;
    }
}


// Default constructor
ScalarConverter::ScalarConverter(void)
{
    return ;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void) other;
    return ;
}

// Assignment operator overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
    {
    }
    return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter(void)
{
    return ;
}

