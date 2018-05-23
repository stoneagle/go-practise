prerequisite:  
	sudo yum install -y automake libtool flex bison pkgconfig gcc-c++ boost-devel libevent-devel zlib-devel python-devel ruby-devel openssl-devel

install:
	wget http://mirrors.shu.edu.cn/apache/thrift/0.11.0/thrift-0.11.0.tar.gz

create:
	thrift --gen cpp TTG.thrift && thrift --gen go TTG.thrift

server:
	cd gen-cpp && g++ -o server -std=c++11 -I . -I /usr/local/include -L /usr/local/lib -lthrift TTGService_server.skeleton.cpp TTGService.cpp TTG_constants.cpp TTG_types.cpp

client:
	cd gen-cpp && g++ -o client -std=c++11 -I . -I /usr/local/include -L /usr/local/lib -lthrift client.cpp TTGService.cpp TTG_constants.cpp TTG_types.cpp
