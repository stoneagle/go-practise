#include "TTGService.h"

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TCompactProtocol.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using boost::shared_ptr;

int main(int argc, char **argv) {
        // 定义socket的host和端口, server端口是9090之前已经说过
        boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
        // 下面定义协议, 如果协议和server不一致, 会出现一些错误
        //
        // 错误: Thrift: Mon Oct 24 22:22:52 2016 TConnectedClient processing exception: Bad version identifier
        //
        boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
        boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

        transport->open();
        // ID设置为1
        TTG::Request r;
        r.studentID = 1;
        TTG::Response resp;

        TTG::TTGServiceClient client(protocol);
        client.getStudentInfo(resp, r);

        transport->close();
        printf("ID=%d  name=%s  state=%d\n", resp.studentID, resp.name.c_str(), resp.state);
        return 0;
}
