#include "MyException.hpp"

// Default constructor
MyException::MyException(void)
{
    return ;
}

const char* MyException::what() const throw() {
    return message.c_str();
}

MyException::MyException(const std::string& msg) : message(msg)
{
    return ;
}

// Copy constructor
MyException::MyException(const MyException &other)
{
    this->message = other.message;
}

// Assignment operator overload
MyException &MyException::operator=(const MyException &other)
{
    if (this != &other)
        this->message = other.message;
    return *this;
}

// Destructor
MyException::~MyException(void) throw()
{
    return ;
}

// Sobrecarga operador <<
std::ostream& operator<<(std::ostream& os, const MyException& ex)
{
    os << ex.what();
    return os;
}

