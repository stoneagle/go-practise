package common2

/*
#include <stdio.h>

#cgo CFLAGS : -I./

#include "data.h"
*/
import "C"

import (
	"fmt"
)

type GData C.struct_Tdata

func (data *GData) GDataSetA(a int) {
	data.a = C.int(a)
}

func (data *GData) GDataSetB(b byte) {
	data.b = C.char(b)
}

func Print(data *GData) bool {
	fmt.Printf("data : %d %c\n", data.a, data.b)
	return true
}
