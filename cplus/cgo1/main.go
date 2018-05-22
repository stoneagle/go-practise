// go run main.go
package main

// #include "winlin.h"
// #cgo LDFLAGS: ${SRCDIR}/winlin.a -lstdc++
import "C"
import "fmt"

func main() {
	fmt.Println("version is", C.winlin_version())
}
