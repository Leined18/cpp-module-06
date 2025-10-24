#include "TypeFactory.hpp"

// =======================
// Static parsers array
// =======================
TypeFactory::Parser TypeFactory::_parsers[TypeFactory::_maxTypes] = {
    NULL,                // NONE
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
// Static parser functions
// =======================
TypeFactory::eType TypeFactory::parseChar(const std::string &str) {
    return (str.size() == 1) ? CHAR : NONE;
}

TypeFactory::eType TypeFactory::parseInt(const std::string &str) {
    if (str.empty()) return NONE;
    size_t i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    if (i == str.size()) return NONE;
    for (; i < str.size(); i++)
        if (!std::isdigit(str[i])) return NONE;
    return INT;
}

TypeFactory::eType TypeFactory::parseFloat(const std::string &str) {
    (void)str;
    return NONE; // pendiente
}

TypeFactory::eType TypeFactory::parseDouble(const std::string &str) {
    (void)str;
    return NONE; // pendiente
}

// =======================
// Detect type (no estático)
// =======================
TypeFactory::eType TypeFactory::detectType(const std::string &str) {
    for (int i = 1; i < _maxTypes; i++) {
        if (_parsers[i] && _parsers[i](str) != NONE) {
            return static_cast<eType>(i);
        }
    }
    return NONE;
}

// =======================
// Cast helpers (no estáticos)
// =======================
std::string TypeFactory::castCharToString(char c) const {
    std::ostringstream oss;
    oss << "char: '" << c << "'\n";
    oss << "int: " << static_cast<int>(c) << "\n";
    oss << "float: " << static_cast<float>(c) << ".0f\n";
    oss << "double: " << static_cast<double>(c) << ".0\n";
    return oss.str();
}

std::string TypeFactory::castIntToString(int i) const {
    std::ostringstream oss;
    oss << "char: '" << static_cast<char>(i) << "'\n";
    oss << "int: " << i << "\n";
    oss << "float: " << static_cast<float>(i) << ".0f\n";
    oss << "double: " << static_cast<double>(i) << ".0\n";
    return oss.str();
}

std::string TypeFactory::castFloatToString(float f) const {
    std::ostringstream oss;
    oss << "char: '" << static_cast<char>(f) << "'\n";
    oss << "int: " << static_cast<int>(f) << "\n";
    oss << "float: " << f << "f\n";
    oss << "double: " << static_cast<double>(f) << "\n";
    return oss.str();
}

std::string TypeFactory::castDoubleToString(double d) const {
    std::ostringstream oss;
    oss << "char: '" << static_cast<char>(d) << "'\n";
    oss << "int: " << static_cast<int>(d) << "\n";
    oss << "float: " << static_cast<float>(d) << "f\n";
    oss << "double: " << d << "\n";
    return oss.str();
}
