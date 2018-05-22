#include "src.hpp"
#include "c_src.h"
#include <cstring>

// 返回cxxFoo对象，但转换为void*
Foo FooNew()
{
    cxxFoo* ret = new cxxFoo("rokety");
    return (void*)ret;
}

void FooDestroy(Foo f)
{
    cxxFoo* foo = (cxxFoo*)f;
    delete foo;
}

// 封装cxxFoo的get_name方法
const char* FooGetName(Foo f, int* ret_len)
{
    cxxFoo* foo = (cxxFoo*)f;
    std::string name = foo->get_name();
    *ret_len = name.length();
    const char* ret_str = (const char*)malloc(*ret_len);
    memcpy((void*)ret_str, name.c_str(), *ret_len);
    return ret_str;
}

// 封装cxxFoo的set_name方法
void FooSetName(Foo f, char* name)
{
    cxxFoo* foo = (cxxFoo*)f;
    std::string _name(name, strlen(name));
    foo->set_name(_name);
}
