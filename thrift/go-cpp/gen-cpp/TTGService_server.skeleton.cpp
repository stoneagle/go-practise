// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "TTGService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::TTG;

class TTGServiceHandler : virtual public TTGServiceIf {
 public:
  TTGServiceHandler() {
    // Your initialization goes here
  }

  void getStudentInfo(Response& _return, const Request& request) {
    // Your implementation goes here
    printf("getStudentInfo\n");
    printf("request.studentID: %d", request.studentID);
    _return.studentID = request.studentID;
    _return.name = "hello";
    _return.infos.push_back("测试1");
    _return.infos.push_back("测试2");
    _return.state = ResponseState::StateOk;
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::apache::thrift::stdcxx::shared_ptr<TTGServiceHandler> handler(new TTGServiceHandler());
  ::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(new TTGServiceProcessor(handler));
  ::apache::thrift::stdcxx::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::apache::thrift::stdcxx::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::apache::thrift::stdcxx::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

