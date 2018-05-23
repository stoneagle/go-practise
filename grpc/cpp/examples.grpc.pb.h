// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: examples.proto
#ifndef GRPC_examples_2eproto__INCLUDED
#define GRPC_examples_2eproto__INCLUDED

#include "examples.pb.h"

#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

class SearchService final {
 public:
  static constexpr char const* service_full_name() {
    return "SearchService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Search(::grpc::ClientContext* context, const ::SearchRequest& request, ::SearchResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::SearchResponse>> AsyncSearch(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::SearchResponse>>(AsyncSearchRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::SearchResponse>> PrepareAsyncSearch(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::SearchResponse>>(PrepareAsyncSearchRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::SearchResponse>* AsyncSearchRaw(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::SearchResponse>* PrepareAsyncSearchRaw(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status Search(::grpc::ClientContext* context, const ::SearchRequest& request, ::SearchResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::SearchResponse>> AsyncSearch(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::SearchResponse>>(AsyncSearchRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::SearchResponse>> PrepareAsyncSearch(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::SearchResponse>>(PrepareAsyncSearchRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< ::SearchResponse>* AsyncSearchRaw(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::SearchResponse>* PrepareAsyncSearchRaw(::grpc::ClientContext* context, const ::SearchRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Search_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Search(::grpc::ServerContext* context, const ::SearchRequest* request, ::SearchResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Search : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Search() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Search() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Search(::grpc::ServerContext* context, const ::SearchRequest* request, ::SearchResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSearch(::grpc::ServerContext* context, ::SearchRequest* request, ::grpc::ServerAsyncResponseWriter< ::SearchResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Search<Service > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_Search : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Search() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Search() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Search(::grpc::ServerContext* context, const ::SearchRequest* request, ::SearchResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Search : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_Search() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::SearchRequest, ::SearchResponse>(std::bind(&WithStreamedUnaryMethod_Search<BaseClass>::StreamedSearch, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_Search() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Search(::grpc::ServerContext* context, const ::SearchRequest* request, ::SearchResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSearch(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::SearchRequest,::SearchResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_Search<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_Search<Service > StreamedService;
};


#endif  // GRPC_examples_2eproto__INCLUDED
