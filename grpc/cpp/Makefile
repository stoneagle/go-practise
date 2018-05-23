subdir = ./
  
# configPathDir = /home/wuzhongyang/src/grpc 
# export PATH=$PATH:$(configPathDir)/bins/opt:$(configPathDir)/bins/opt/protobuf
# export CPATH=$(configPathDir)/include:$(configPathDir)/third_party/protobuf/src
# export LIBRARY_PATH=$(configPathDir)/libs/opt:$(configPathDir)/libs/opt/protobuf
# export PKG_CONFIG_PATH=$(configPathDir)/libs/opt/pkgconfig:$(configPathDir)/third_party/protobuf
# export LD_LIBRARY_PATH=$(configPathDir)/libs/opt

SOURCES = $(wildcard $(subdir)*.cc)  
SRCOBJS = $(patsubst %.cc,%.o,$(SOURCES))  
CC = g++  
  
%.o:%.cc  
	$(CC) -std=c++11 -I/usr/local/include -pthread -c $< -o $@  
  
all: client server  
  
client: examples.grpc.pb.o examples.pb.o examples_client.o  
	$(CC) $^ -L/usr/local/lib `pkg-config --libs grpc++ grpc` -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed -lprotobuf -lpthread -ldl -lssl -o $@  
  
server: examples.grpc.pb.o examples.pb.o examples_server.o  
	$(CC) $^ -L/usr/local/lib `pkg-config --libs grpc++ grpc` -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed -lprotobuf -lpthread -ldl -lssl -o $@  
#chmod 777 $@  
  
clean:  
	rm -f *.o && rm -f examples.grpc.pb.* && rm -f examples.pb.* && rm -f server && rm -f client

cpp-proto:
	protoc --cpp_out=$(subdir) examples.proto && protoc --grpc_out=$(subdir) --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin examples.proto  
