#ifndef TYPEFACTORY_HPP
#define TYPEFACTORY_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include "MyException.hpp"
#include <limits>
#include <cmath>

class TypeFactory
{
public:
    enum eType {
        NONE = 0,
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        PSEUDO_LITERAL,
        MAX
    };

    typedef eType (*Parser)(const std::string &str);

    TypeFactory();
    TypeFactory(const TypeFactory &other);
    TypeFactory &operator=(const TypeFactory &other);
    ~TypeFactory();

    eType detectType(const std::string &str);

    // Métodos de casteo accesibles vía objeto
    std::string castCharToString(double value  ) const;
    std::string castIntToString(double value   ) const;
    std::string castFloatToString(double value ) const;
    std::string castDoubleToString(double value) const;

    std::string buildCastOutput(double value) const;
    std::string castToString(const std::string &str, eType type) const;

    // Métodos de chequeo como funciones miembro const
    std::string buildString(const std::string &prefix,
        const std::string &valueStr, bool valid = true,
        const std::string &errorMsg = "Error: Valor inválido.\n") const;


private:
    
    static eType parseChar(const std::string &str);
    static eType parseInt(const std::string &str);
    static eType parseFloat(const std::string &str);
    static eType parseDouble(const std::string &str);

    static const int _maxTypes = MAX;
    static Parser _parsers[_maxTypes];
};

#endif
