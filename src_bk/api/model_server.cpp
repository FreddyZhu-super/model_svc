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
#include "protos/model.grpc.pb.h"
#include "protos/model.pb.h"
#include "../model/manager.h"
#endif

//using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

// Logic and data behind the server's behavior.
class ModelServiceImpl final : public model_service::Model::Service {

    grpc::Status InitModel(grpc::ServerContext* context, const model_service::InitModelRequest* request,
                           model_service::ModelReply* reply) override {
        std::string prefix("server received init model call");
        Model::Manager manager;
        Model::STATUS status = manager.InitModel(request->model_enum(),request->model_param());
        if (status!=Model::SUCCESS){
            reply->set_ret_code(Model::ERROR);
        }
        reply->set_ret_code(0);
        return Status::OK;
    }

    grpc::Status ReleaseModel(grpc::ServerContext* context, const model_service::ReleaseModelRequest* request,
                        model_service::ModelReply* reply) override {
        std::string prefix("server received release model call");
        Model::Manager manager;
        Model::STATUS status = manager.ReleaseModel(request->model_enum());
        if (status!=Model::SUCCESS){
            reply->set_ret_code(Model::ERROR);
        }
        reply->set_ret_code(0);
        return grpc::Status::OK;
    }

    grpc::Status Inference(grpc::ServerContext* context, const model_service::InferenceRequest* request,
                          model_service::InferenceReply* reply) override {
        std::string prefix("server received inference model call");

        Model::Manager manager;
        Model::STATUS status = manager.Inference(request->model_enum(),request->param())
        if (status!=Model::SUCCESS){
            reply->set_ret_code(Model::ERROR);
        }

        reply->set_ret_code(0);
        return grpc::Status::OK;
    }
};

void RunServer() {
    std::string server_address("127.0.0.1:55555");
    ModelServiceImpl service;

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();

    return 0;
}