#ifndef CXX_H
#define CXX_H

#include <string>

class cxxFoo
{
public:
    cxxFoo(std::string name);
    ~cxxFoo();
    std::string get_name();
    void set_name(std::string name);

private:
    std::string name;
};

#endif // CXX_H
