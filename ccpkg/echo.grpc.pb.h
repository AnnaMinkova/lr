// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: echo.proto
#ifndef GRPC_echo_2eproto__INCLUDED
#define GRPC_echo_2eproto__INCLUDED

#include "echo.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace suggest {

class Suggest final {
 public:
  static constexpr char const* service_full_name() {
    return "suggest.Suggest";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Answer(::grpc::ClientContext* context, const ::suggest::SuggestRequest& request, ::suggest::SuggestResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::suggest::SuggestResponse>> AsyncAnswer(::grpc::ClientContext* context, const ::suggest::SuggestRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::suggest::SuggestResponse>>(AsyncAnswerRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::suggest::SuggestResponse>> PrepareAsyncAnswer(::grpc::ClientContext* context, const ::suggest::SuggestRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::suggest::SuggestResponse>>(PrepareAsyncAnswerRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void Answer(::grpc::ClientContext* context, const ::suggest::SuggestRequest* request, ::suggest::SuggestResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void Answer(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::suggest::SuggestResponse* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void Answer(::grpc::ClientContext* context, const ::suggest::SuggestRequest* request, ::suggest::SuggestResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void Answer(::grpc::ClientContext* context, const ::suggest::SuggestRequest* request, ::suggest::SuggestResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void Answer(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::suggest::SuggestResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void Answer(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::suggest::SuggestResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::suggest::SuggestResponse>* AsyncAnswerRaw(::grpc::ClientContext* context, const ::suggest::SuggestRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::suggest::SuggestResponse>* PrepareAsyncAnswerRaw(::grpc::ClientContext* context, const ::suggest::SuggestRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status Answer(::grpc::ClientContext* context, const ::suggest::SuggestRequest& request, ::suggest::SuggestResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::suggest::SuggestResponse>> AsyncAnswer(::grpc::ClientContext* context, const ::suggest::SuggestRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::suggest::SuggestResponse>>(AsyncAnswerRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::suggest::SuggestResponse>> PrepareAsyncAnswer(::grpc::ClientContext* context, const ::suggest::SuggestRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::suggest::SuggestResponse>>(PrepareAsyncAnswerRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void Answer(::grpc::ClientContext* context, const ::suggest::SuggestRequest* request, ::suggest::SuggestResponse* response, std::function<void(::grpc::Status)>) override;
      void Answer(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::suggest::SuggestResponse* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void Answer(::grpc::ClientContext* context, const ::suggest::SuggestRequest* request, ::suggest::SuggestResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void Answer(::grpc::ClientContext* context, const ::suggest::SuggestRequest* request, ::suggest::SuggestResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void Answer(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::suggest::SuggestResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void Answer(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::suggest::SuggestResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::suggest::SuggestResponse>* AsyncAnswerRaw(::grpc::ClientContext* context, const ::suggest::SuggestRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::suggest::SuggestResponse>* PrepareAsyncAnswerRaw(::grpc::ClientContext* context, const ::suggest::SuggestRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Answer_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Answer(::grpc::ServerContext* context, const ::suggest::SuggestRequest* request, ::suggest::SuggestResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Answer : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_Answer() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Answer() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Answer(::grpc::ServerContext* /*context*/, const ::suggest::SuggestRequest* /*request*/, ::suggest::SuggestResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestAnswer(::grpc::ServerContext* context, ::suggest::SuggestRequest* request, ::grpc::ServerAsyncResponseWriter< ::suggest::SuggestResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Answer<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Answer : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_Answer() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::suggest::SuggestRequest, ::suggest::SuggestResponse>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::suggest::SuggestRequest* request, ::suggest::SuggestResponse* response) { return this->Answer(context, request, response); }));}
    void SetMessageAllocatorFor_Answer(
        ::grpc::experimental::MessageAllocator< ::suggest::SuggestRequest, ::suggest::SuggestResponse>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(0);
    #endif
      static_cast<::grpc_impl::internal::CallbackUnaryHandler< ::suggest::SuggestRequest, ::suggest::SuggestResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_Answer() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Answer(::grpc::ServerContext* /*context*/, const ::suggest::SuggestRequest* /*request*/, ::suggest::SuggestResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* Answer(
      ::grpc::CallbackServerContext* /*context*/, const ::suggest::SuggestRequest* /*request*/, ::suggest::SuggestResponse* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* Answer(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::suggest::SuggestRequest* /*request*/, ::suggest::SuggestResponse* /*response*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_Answer<Service > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_Answer<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Answer : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_Answer() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Answer() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Answer(::grpc::ServerContext* /*context*/, const ::suggest::SuggestRequest* /*request*/, ::suggest::SuggestResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Answer : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_Answer() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Answer() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Answer(::grpc::ServerContext* /*context*/, const ::suggest::SuggestRequest* /*request*/, ::suggest::SuggestResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestAnswer(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Answer : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_Answer() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->Answer(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_Answer() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Answer(::grpc::ServerContext* /*context*/, const ::suggest::SuggestRequest* /*request*/, ::suggest::SuggestResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* Answer(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* Answer(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Answer : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_Answer() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::suggest::SuggestRequest, ::suggest::SuggestResponse>(
            [this](::grpc_impl::ServerContext* context,
                   ::grpc_impl::ServerUnaryStreamer<
                     ::suggest::SuggestRequest, ::suggest::SuggestResponse>* streamer) {
                       return this->StreamedAnswer(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_Answer() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Answer(::grpc::ServerContext* /*context*/, const ::suggest::SuggestRequest* /*request*/, ::suggest::SuggestResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedAnswer(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::suggest::SuggestRequest,::suggest::SuggestResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_Answer<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_Answer<Service > StreamedService;
};

}  // namespace suggest


#endif  // GRPC_echo_2eproto__INCLUDED
