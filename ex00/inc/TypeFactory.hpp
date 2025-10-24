#ifndef TYPEFACTORY_HPP
#define TYPEFACTORY_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include "MyException.hpp"

class TypeFactory
{
public:
    enum eType {
        NONE = 0,
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        MAX
    };

    typedef eType (*Parser)(const std::string &str);

    TypeFactory();
    TypeFactory(const TypeFactory &other);
    TypeFactory &operator=(const TypeFactory &other);
    ~TypeFactory();

    eType detectType(const std::string &str);

    // Métodos de casteo accesibles vía objeto
    std::string castCharToString(char c) const;
    std::string castIntToString(int i) const;
    std::string castFloatToString(float f) const;
    std::string castDoubleToString(double d) const;

private:
    static eType parseChar(const std::string &str);
    static eType parseInt(const std::string &str);
    static eType parseFloat(const std::string &str);
    static eType parseDouble(const std::string &str);

    static const int _maxTypes = MAX;
    static Parser _parsers[_maxTypes];
};

#endif
