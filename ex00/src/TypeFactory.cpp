#include "TypeFactory.hpp"
#include <cmath>
#include <sstream>
#include <limits>
#include <cctype>

// =======================
// Static parsers array
// =======================
TypeFactory::Parser TypeFactory::_parsers[TypeFactory::_maxTypes] = {
    NULL,                  // NONE
    &TypeFactory::parseChar,   // CHAR
    &TypeFactory::parseInt,    // INT
    &TypeFactory::parseFloat,  // FLOAT
    &TypeFactory::parseDouble  // DOUBLE
};

// =======================
// Constructor / Destructor
// =======================
TypeFactory::TypeFactory() {}
TypeFactory::TypeFactory(const TypeFactory &other) { (void)other; }
TypeFactory &TypeFactory::operator=(const TypeFactory &other) { (void)other; return *this; }
TypeFactory::~TypeFactory() {}

// =======================
// Auxiliares estáticos
// =======================
static bool isValidNumber(const std::string &str, bool allowDot = false) {
    if (str.empty()) return false;
    size_t i = 0;
    if (str[0] == '-' || str[0] == '+') {
        i = 1;
        if (i == str.size()) return false;
    }
    bool dot = false;
    bool hasDigit = false;
    for (; i < str.size(); ++i) {
        if (str[i] == '.') {
            if (!allowDot || dot) return false;
            dot = true;
        } else if (!std::isdigit(str[i])) {
            return false;
        } else {
            hasDigit = true;
        }
    }
    return hasDigit;
}

static bool isPseudoLiteral(const std::string &str) {
    return (str == "-inff" || str == "+inff" || str == "nanf" ||
            str == "-inf" || str == "+inf" || str == "nan");
}

static bool getPseudoLiteralValue(const std::string &str, double &outValue) {
    if (str == "nan" || str == "nanf")       { outValue = std::numeric_limits<double>::quiet_NaN(); return true; }
    if (str == "+inf" || str == "+inff")     { outValue = std::numeric_limits<double>::infinity(); return true; }
    if (str == "-inf" || str == "-inff")     { outValue = -std::numeric_limits<double>::infinity(); return true; }
    return false;
}

// =======================
// Parsers
// =======================
TypeFactory::eType TypeFactory::parseChar(const std::string &str) {
    return (str.size() == 1 && !std::isdigit(str[0])) ? CHAR : NONE;
}

TypeFactory::eType TypeFactory::parseInt(const std::string &str) {
    return isValidNumber(str, false) ? INT : NONE;
}

TypeFactory::eType TypeFactory::parseFloat(const std::string &str) {
    if (str.size() < 2 || str[str.size() - 1] != 'f') return NONE;
    std::string core = str.substr(0, str.size() - 1);
    return isValidNumber(core, true) ? FLOAT : NONE;
}

TypeFactory::eType TypeFactory::parseDouble(const std::string &str) {
    return isValidNumber(str, true) ? DOUBLE : NONE;
}

// =======================
// Detect type
// =======================
TypeFactory::eType TypeFactory::detectType(const std::string &str) {
    if (str.empty()) return NONE;
    if (isPseudoLiteral(str)) return PSEUDO_LITERAL;
    for (int i = 1; i < _maxTypes; ++i) {
        if (_parsers[i] && _parsers[i](str) != NONE) {
            return static_cast<eType>(i);
        }
    }
    return NONE;
}

// =======================
// Build string helper
// =======================
std::string TypeFactory::buildString(const std::string &prefix,
                                     const std::string &valueStr,
                                     bool valid,
                                     const std::string &errorMsg) const {
    const std::string RED = "\033[1;31m";
    if (!valid) throw MyException(RED + errorMsg + "\033[0m");

    std::ostringstream oss;
    oss << prefix << valueStr << "\n";
    return oss.str();
}

// =======================
// Cast helpers
// =======================
std::string TypeFactory::castCharToString(double value) const {
    bool isPrintable = std::isfinite(value) && std::isprint(static_cast<char>(value));
    char c = isPrintable ? static_cast<char>(value) : 0;
    return buildString("char: ", "'" + std::string(1, c) + "'", isPrintable, "char: Non displayable.\n");
}

std::string TypeFactory::castIntToString(double value) const {
    bool isIntConvertible = std::isfinite(value) &&
                             value >= std::numeric_limits<int>::min() &&
                             value <= std::numeric_limits<int>::max();
    int i = isIntConvertible ? static_cast<int>(value) : 0;
    std::ostringstream oss;
    oss << i;
    return buildString("int: ", oss.str(), isIntConvertible, "int: Non displayable.\n");
}

std::string TypeFactory::castFloatToString(double value) const {
    bool isPrintable = std::isfinite(value) &&
                       value >= -std::numeric_limits<float>::max() &&
                       value <= std::numeric_limits<float>::max();
    std::ostringstream oss;
    isPrintable = isPrintable || std::isnan(value) || std::isinf(value);
    if (std::isnan(value)) oss << "nanf";
    else if (std::isinf(value)) oss << (value < 0 ? "-inff" : "+inff");
    else {
        float f = static_cast<float>(value);
        oss << f;
        if (f == static_cast<int>(f)) oss << ".0";
        oss << "f";
    }
    return buildString("float: ", oss.str(), isPrintable, "float: Non displayable.\n");
}

std::string TypeFactory::castDoubleToString(double value) const {
    bool isPrintable = std::isfinite(value) &&
                       value > -std::numeric_limits<double>::max() &&
                       value < std::numeric_limits<double>::max();
    std::ostringstream oss;
    isPrintable = isPrintable || std::isnan(value) || std::isinf(value);
    if (std::isnan(value)) oss << "nan";
    else if (std::isinf(value)) oss << (value < 0 ? "-inf" : "+inf");
    else {
        oss << value;
        if (value == static_cast<int>(value)) oss << ".0";
    }
    return buildString("double: ", oss.str(), isPrintable, "double: Non displayable.\n");
}

// =======================
// Build cast output
// =======================
std::string TypeFactory::buildCastOutput(double value) const {
    std::ostringstream oss;
    try { oss << castCharToString(value); } catch (const MyException &e) { oss << e.what(); }
    try { oss << castIntToString(value); } catch (const MyException &e) { oss << e.what(); }
    try { oss << castFloatToString(value); } catch (const MyException &e) { oss << e.what(); }
    try { oss << castDoubleToString(value); } catch (const MyException &e) { oss << e.what(); }
    return oss.str();
}

// =======================
// Cast from string
// =======================
std::string TypeFactory::castToString(const std::string &str, eType type) const {
    double value = 0.0;

    if (type == PSEUDO_LITERAL) {
        if (!getPseudoLiteralValue(str, value))
            throw MyException("Error: pseudo-literal inválido.");
    } else {
        std::istringstream ss(str);
        switch (type) {
            case CHAR: { char c; ss >> c; value = static_cast<double>(c); break; }
            case INT: { double i; ss >> i; value = i; break; }
            case FLOAT: { double f; ss >> f; value = f; break; }
            case DOUBLE: { double d; ss >> d; value = d; break; }
            default: throw MyException("Error: Type incompatible."); 
        }
    }
    return buildCastOutput(value);
}
