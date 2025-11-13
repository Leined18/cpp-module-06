#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>

class Data
{
    private:
        std::string _info; // Example member variable
    public:
        Data(void);
        Data(const std::string &info);
        Data(const Data& other);
        Data &operator=(const Data &other);
        ~Data();

        std::string getInfo() const;
        void setInfo(const std::string &info);
};

// Overloading the output stream operator for Data class
std::ostream &operator<<(std::ostream &out, const Data &data);

#endif

