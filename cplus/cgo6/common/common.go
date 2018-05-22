package common

/*
#include <stdio.h>

#cgo CFLAGS : -I./

#include "data.h"
*/
import "C"

import (
	"fmt"
)

type GData C.struct_Data

func Print(data *GData) bool {
	fmt.Printf("data : %d %c\n", data.A, data.B)
	return true
}
