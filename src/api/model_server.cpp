//
// Created by Freddy Zhu on 2022/9/21.
//

#include "model_server.h"
#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#ifdef BAZEL_BUILD
#include "examples/protos/helloworld.grpc.pb.h"
#else
#include "protos/algorithm.grpc.pb.h"
#endif

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

// Logic and data behind the server's behavior.
class AlgorithmServiceImpl final : public algorithm::Service {
    Status InitModel(ServerContext* context, const algorithm::AlgorithmRequest* request,
                     algorithm::AlgorithmReply* reply) override {
        std::string prefix("server received sendimg call");
        reply->set_ret_code(0);
        return Status::OK;
    }

    Status ReleaseModel(ServerContext* context, const algorithm::AlgorithmRequest* request,
                     algorithm::AlgorithmReply* reply) override {
        std::string prefix("server received sendimg call");
        reply->set_ret_code(0);
        return Status::OK;
    }

    Status ReleaseModel(ServerContext* context, const algorithm::AlgorithmRequest* request,
                     algorithm::AlgorithmReply* reply) override {
        std::string prefix("server received sendimg call");
        reply->set_ret_code(0);
        return Status::OK;
    }



};

void RunServer() {
    std::string server_address("127.0.0.1:55555");
    BenchmarkServiceImpl service;

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();

    return 0;
}