#include "src.hpp"
#include <iostream>

cxxFoo::cxxFoo(std::string name)
{
    this->name = name;
}

cxxFoo::~cxxFoo()
{
}

std::string cxxFoo::get_name()
{
    return this->name;
}

void cxxFoo::set_name(std::string name)
{
    this->name = name;
}
