package main

import (
	"fmt"
	"micro-service/cplus/cgo6/common"
	"micro-service/cplus/cgo6/common2"
)

func main() {
	data := common.GData{A: 2, B: 'b'}
	fmt.Println(data)
	common.Print(&data)

	data2 := common2.GData{}
	data2.GDataSetA(2)
	data2.GDataSetB('b')
	common2.Print(&data2)
}
