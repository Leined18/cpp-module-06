#ifndef MYEXCEPTION_HPP
# define MYEXCEPTION_HPP
# include <iostream>

class MyException : public std::exception
{
    protected:
        std::string message;
    public:
        MyException(void);
        MyException(const std::string& msg);
        MyException(const MyException& other);
        MyException &operator=(const MyException &other);
        virtual ~MyException() throw();
        virtual const char* what() const throw();
};

// Declaración del operador de inserción (externa, no miembro)
std::ostream& operator<<(std::ostream& os, const MyException& ex);

#endif  

