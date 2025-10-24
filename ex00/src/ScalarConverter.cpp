#include "ScalarConverter.hpp"



static std::ostringstream &castCharToOss(char c)
{
    static std::ostringstream oss;

    if (!oss.str().empty())
        oss.str("");
    oss.clear();
    oss << "char: '" << c << "'" << std::endl;
    oss << "int: " << static_cast<int>(c) << std::endl;
    oss << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    oss << "double: " << static_cast<double>(c) << ".0" << std::endl;
    return (oss);
}

void ScalarConverter::convert(const std::string &s)
{
    std::stringstream ss(s);
    char c;

    for (size_t i = 0; i < s.length(); ++i)
    {
        if (!isprint(s[i]) && !isspace(s[i]))
        {
            std::cout << "char: impossible" << std::endl;
            return ;
        }
    }
    ss >> c;
    std::cout << castCharToOss(c).str() << std::endl;
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
    (void) other;
    return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter(void)
{
    return ;
}

