package main

import (
	"fmt"
	"sync"
)

/*
extern void go_callback_int(int foo, int p1);

static inline void CallMyFunction(int foo) {
	go_callback_int(foo, 5);
}
*/
import "C"

//export go_callback_int
func go_callback_int(foo C.int, p1 C.int) {
	fn := lookup(int(foo))
	fn(p1)
}

func MyCallback(x C.int) {
	fmt.Println("callback with", x)
}

func main() {
	i := register(MyCallback)
	C.CallMyFunction(C.int(i))
	unregister(i)
}

var mu sync.Mutex
var index int
var fns = make(map[int]func(C.int))

func register(fn func(C.int)) int {
	mu.Lock()
	defer mu.Unlock()
	index++
	for fns[index] != nil {
		index++
	}
	fns[index] = fn
	return index
}

func lookup(i int) func(C.int) {
	mu.Lock()
	defer mu.Unlock()
	return fns[i]
}

func unregister(i int) {
	mu.Lock()
	defer mu.Unlock()
	delete(fns, i)
}
