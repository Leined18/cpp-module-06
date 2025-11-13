#include "Data.hpp"

Data::Data(void): _info("default") {}
Data::Data(const Data &other) : _info(other._info) {}
Data &Data::operator=(const Data &other)
{
    if (this != &other)
        this->_info = other._info;
    return (*this);
}
Data::~Data(void) {}

Data::Data(const std::string &info): _info(info) {}

std::string Data::getInfo() const
{
    return this->_info;
}

void Data::setInfo(const std::string &info)
{
    this->_info = info;
}

// Overloading the output stream operator for Data class
std::ostream &operator<<(std::ostream &out, const Data &data)
{
    out << data.getInfo() << std::endl;
    return out;
}



