#include "ScalarConverter.hpp"




static std::ostringstream &castToOss(const std::string &s, TypeFactory &self, TypeFactory::eType type)
{
    static std::ostringstream oss;
    std::stringstream ss(s);

    if (ss.fail())
        throw MyException("Error: Invalid character input.");
    switch (type)
    {
        case TypeFactory::CHAR:
            char c; ss >> c;
            oss << self.castCharToString(c);
            break;
        case TypeFactory::INT:
            int i; ss >> i;
            oss << self.castIntToString(i);
            break;
        case TypeFactory::FLOAT:
            float f; ss >> f;
            oss << self.castFloatToString(f);
            break;
        case TypeFactory::DOUBLE:
            double d; ss >> d;
            oss << self.castDoubleToString(d);
            break;
        default:
            throw MyException("Error: Unknown type for conversion.");
    }
    return (oss);
}

void ScalarConverter::convert(const std::string &s)
{
    TypeFactory::eType    _detectedType;
    TypeFactory          _typeFactory;

    try {
        _detectedType = _typeFactory.detectType(s);
        if (_detectedType == TypeFactory::NONE)
            throw MyException("Error: IMPOSSIBLE");
        std::ostringstream &oss = castToOss(s, _typeFactory, _detectedType);
        std::cout << oss.str();
        return ;
    } catch (const MyException &e) {
        std::cout << e.what() << std::endl;
        return ;
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

