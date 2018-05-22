package main

// #include "c_src.h"
// #include <stdlib.h>
import "C"

import (
	"fmt"
	"unsafe"
)

type GoFoo struct {
	foo C.Foo
}

func NewGoFoo() GoFoo {
	var ret GoFoo
	ret.foo = C.FooNew()
	return ret
}

func (f GoFoo) Destroy() {
	C.FooDestroy(f.foo)
}

func (f GoFoo) GetName() string {
	rLen := C.int(0)
	name := C.FooGetName(f.foo, &rLen)
	defer C.free(unsafe.Pointer(name)) // 必须使用C的free函数，释放FooGetName中malloc的内存
	return C.GoStringN(name, rLen)     // 从name构造出golang的string类型值
}

func (f GoFoo) SetName(name string) {
	cname := C.CString(name) // 将golang的string类型值转换为c中的char*类型值，这里会调用到c的malloc
	C.FooSetName(f.foo, cname)
	C.free(unsafe.Pointer(cname)) // 释放上malloc的内存
}

func main() {
	foo := NewGoFoo()
	fmt.Println(foo.GetName())
	foo.GetName()
	foo.SetName("new rokety")
	fmt.Println(foo.GetName())
	foo.Destroy()
}
