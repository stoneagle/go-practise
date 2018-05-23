package main

import (
	"fmt"
	"net"
	"os"

	"golang.org/x/net/context"

	"./TTG"
	"git.apache.org/thrift.git/lib/go/thrift"
)

func main() {
	// 下面定义协议
	transportFactory := thrift.NewTTransportFactory()
	protocolFactory := thrift.NewTBinaryProtocolFactoryDefault()
	transport, err := thrift.NewTSocket(net.JoinHostPort("127.0.0.1", "9090"))

	if err != nil {
		fmt.Fprintln(os.Stderr, "error resolving address:", err)
		os.Exit(1)
	}

	useTransport, err := transportFactory.GetTransport(transport)
	// 创建一个client
	client := TTG.NewTTGServiceClientFactory(useTransport, protocolFactory)
	if err := transport.Open(); err != nil {
		fmt.Fprintln(os.Stderr, "Error opening socket to server", " ", err)
		os.Exit(1)
	}
	defer transport.Close()
	// 注意此时的ID是999
	r := &TTG.Request{
		StudentID: 999,
	}
	// 根据request获取response
	resp, _ := client.GetStudentInfo(context.Background(), r)

	fmt.Println(resp)
}
