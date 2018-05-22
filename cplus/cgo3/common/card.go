package common

/*
#cgo LDFLAGS: -L ../test/lib -ltest -lIPCReading-S-r0.0.1 -lstdc++ -lDNN -lopenblas -lopencv_highgui -lopencv_imgcodecs -llibjasper -llibjpeg -llibtiff -llibpng -llibwebp -lopencv_imgproc -lopencv_core  -lpthread -lstdc++ -fopenmp -ldl -lz -lm
#include "../test/test.h"
#include <stdlib.h>
*/
import "C"
import (
	"fmt"
	"sync"
)

type CardData C.struct_data

var (
	mu  sync.Mutex
	fns = make(map[int]func(C.int))
)

func (data *CardData) SetParams(model, img string, app int) {
	data.modelPath = C.CString(model)
	data.imgPath = C.CString(img)
	data.appId = C.int(app)
}

func (data *CardData) Check() {
	C.CardIdentify(C.struct_data(*data))
}

//export cardCallBack
func cardCallBack(appId C.int, bookId C.int) {
	fn := lookup(int(appId))
	fn(bookId)
}

func lookup(appId int) func(C.int) {
	mu.Lock()
	defer mu.Unlock()
	return fns[appId]
}

func Register(fn func(C.int), appId int) {
	mu.Lock()
	defer mu.Unlock()
	fns[appId] = fn
}

func UnRegister(appId int) {
	mu.Lock()
	defer mu.Unlock()
	delete(fns, appId)
}

func DefaultAppExec(bookId C.int) {
	fmt.Println("callback with", bookId)
}
