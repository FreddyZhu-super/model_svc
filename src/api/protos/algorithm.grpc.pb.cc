// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: algorithm.proto

#include "algorithm.pb.h"
#include "algorithm.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace algorithm {

static const char* Algorithm_method_names[] = {
  "/algorithm.Algorithm/InitModel",
  "/algorithm.Algorithm/ReleaseModel",
  "/algorithm.Algorithm/Inference",
};

std::unique_ptr< Algorithm::Stub> Algorithm::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Algorithm::Stub> stub(new Algorithm::Stub(channel, options));
  return stub;
}

Algorithm::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_InitModel_(Algorithm_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_ReleaseModel_(Algorithm_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Inference_(Algorithm_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Algorithm::Stub::InitModel(::grpc::ClientContext* context, const ::algorithm::AlgorithmRequest& request, ::algorithm::AlgorithmReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::algorithm::AlgorithmRequest, ::algorithm::AlgorithmReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_InitModel_, context, request, response);
}

void Algorithm::Stub::async::InitModel(::grpc::ClientContext* context, const ::algorithm::AlgorithmRequest* request, ::algorithm::AlgorithmReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::algorithm::AlgorithmRequest, ::algorithm::AlgorithmReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_InitModel_, context, request, response, std::move(f));
}

void Algorithm::Stub::async::InitModel(::grpc::ClientContext* context, const ::algorithm::AlgorithmRequest* request, ::algorithm::AlgorithmReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_InitModel_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::algorithm::AlgorithmReply>* Algorithm::Stub::PrepareAsyncInitModelRaw(::grpc::ClientContext* context, const ::algorithm::AlgorithmRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::algorithm::AlgorithmReply, ::algorithm::AlgorithmRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_InitModel_, context, request);
}

::grpc::ClientAsyncResponseReader< ::algorithm::AlgorithmReply>* Algorithm::Stub::AsyncInitModelRaw(::grpc::ClientContext* context, const ::algorithm::AlgorithmRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncInitModelRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Algorithm::Stub::ReleaseModel(::grpc::ClientContext* context, const ::algorithm::AlgorithmRequest& request, ::algorithm::AlgorithmReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::algorithm::AlgorithmRequest, ::algorithm::AlgorithmReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_ReleaseModel_, context, request, response);
}

void Algorithm::Stub::async::ReleaseModel(::grpc::ClientContext* context, const ::algorithm::AlgorithmRequest* request, ::algorithm::AlgorithmReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::algorithm::AlgorithmRequest, ::algorithm::AlgorithmReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ReleaseModel_, context, request, response, std::move(f));
}

void Algorithm::Stub::async::ReleaseModel(::grpc::ClientContext* context, const ::algorithm::AlgorithmRequest* request, ::algorithm::AlgorithmReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ReleaseModel_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::algorithm::AlgorithmReply>* Algorithm::Stub::PrepareAsyncReleaseModelRaw(::grpc::ClientContext* context, const ::algorithm::AlgorithmRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::algorithm::AlgorithmReply, ::algorithm::AlgorithmRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_ReleaseModel_, context, request);
}

::grpc::ClientAsyncResponseReader< ::algorithm::AlgorithmReply>* Algorithm::Stub::AsyncReleaseModelRaw(::grpc::ClientContext* context, const ::algorithm::AlgorithmRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncReleaseModelRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Algorithm::Stub::Inference(::grpc::ClientContext* context, const ::algorithm::InferenceRequest& request, ::algorithm::InferenceReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::algorithm::InferenceRequest, ::algorithm::InferenceReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Inference_, context, request, response);
}

void Algorithm::Stub::async::Inference(::grpc::ClientContext* context, const ::algorithm::InferenceRequest* request, ::algorithm::InferenceReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::algorithm::InferenceRequest, ::algorithm::InferenceReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Inference_, context, request, response, std::move(f));
}

void Algorithm::Stub::async::Inference(::grpc::ClientContext* context, const ::algorithm::InferenceRequest* request, ::algorithm::InferenceReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Inference_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::algorithm::InferenceReply>* Algorithm::Stub::PrepareAsyncInferenceRaw(::grpc::ClientContext* context, const ::algorithm::InferenceRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::algorithm::InferenceReply, ::algorithm::InferenceRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Inference_, context, request);
}

::grpc::ClientAsyncResponseReader< ::algorithm::InferenceReply>* Algorithm::Stub::AsyncInferenceRaw(::grpc::ClientContext* context, const ::algorithm::InferenceRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncInferenceRaw(context, request, cq);
  result->StartCall();
  return result;
}

Algorithm::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Algorithm_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Algorithm::Service, ::algorithm::AlgorithmRequest, ::algorithm::AlgorithmReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Algorithm::Service* service,
             ::grpc::ServerContext* ctx,
             const ::algorithm::AlgorithmRequest* req,
             ::algorithm::AlgorithmReply* resp) {
               return service->InitModel(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Algorithm_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Algorithm::Service, ::algorithm::AlgorithmRequest, ::algorithm::AlgorithmReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Algorithm::Service* service,
             ::grpc::ServerContext* ctx,
             const ::algorithm::AlgorithmRequest* req,
             ::algorithm::AlgorithmReply* resp) {
               return service->ReleaseModel(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Algorithm_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Algorithm::Service, ::algorithm::InferenceRequest, ::algorithm::InferenceReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Algorithm::Service* service,
             ::grpc::ServerContext* ctx,
             const ::algorithm::InferenceRequest* req,
             ::algorithm::InferenceReply* resp) {
               return service->Inference(ctx, req, resp);
             }, this)));
}

Algorithm::Service::~Service() {
}

::grpc::Status Algorithm::Service::InitModel(::grpc::ServerContext* context, const ::algorithm::AlgorithmRequest* request, ::algorithm::AlgorithmReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Algorithm::Service::ReleaseModel(::grpc::ServerContext* context, const ::algorithm::AlgorithmRequest* request, ::algorithm::AlgorithmReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Algorithm::Service::Inference(::grpc::ServerContext* context, const ::algorithm::InferenceRequest* request, ::algorithm::InferenceReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace algorithm
