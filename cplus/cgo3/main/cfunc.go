package main

import "micro-service/cplus/cgo3/common"

func Identify() {
	common.Register(common.DefaultAppExec, 1)
	data := common.CardData{}
	data.SetParams("../test/model/", "../test/data/upload_cover_20.png", 1)
	data.Check()
	common.UnRegister(1)
}
