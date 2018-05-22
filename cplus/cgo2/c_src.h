#ifndef WRAP_CPP_H
#define WRAP_CPP_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    typedef void* Foo;
    Foo FooNew();
    void FooDestroy(Foo f);
    const char* FooGetName(Foo f, int* retLen);
    void FooSetName(Foo f, char* name);

#ifdef __cplusplus

}
#endif // __cplusplus

#endif // WRAP_CPP_H
