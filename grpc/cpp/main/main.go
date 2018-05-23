package main

import (
	"example"
	"log"
	"runtime"
	"sync"
	"time"

	"golang.org/x/net/context"
	"google.golang.org/grpc"
)

var (
	wg sync.WaitGroup
)

const (
	networkType = "tcp"
	server      = "127.0.0.1"
	port        = "50051"
	parallel    = 5  //连接并行度
	times       = 10 //每连接请求次数
)

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU())
	currTime := time.Now()

	//并行请求
	for i := 0; i < int(parallel); i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			exe()
		}()
	}
	wg.Wait()

	log.Printf("time taken: %.2f ", time.Now().Sub(currTime).Seconds())
}

func exe() {
	//建立连接
	conn, _ := grpc.Dial(server + ":" + port)
	defer conn.Close()
	client := example.NewSearchServiceClient(conn)
	for i := 0; i < int(times); i++ {
		searchService(client)
	}
}

func searchService(client example.SearchServiceClient) {
	var request example.SearchRequest
	request.Request = "world"
	response, _ := client.Search(context.Background(), &request)
	log.Printf("%#v", response.Response)
}
