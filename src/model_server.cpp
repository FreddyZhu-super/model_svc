//
// Created by Freddy Zhu on 2022/9/21.
//

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#ifdef BAZEL_BUILD
#include "examples/protos/helloworld.grpc.pb.h"
#else

#include "api/protos/model.grpc.pb.h"
#include "api/protos/model.pb.h"
#include "model/manager.h"

#endif

//using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

// Logic and data behind the server's behavior.
class ModelServiceImpl final : public model_service::Model::Service {

    grpc::Status InitModel(grpc::ServerContext *context, const model_service::InitModelRequest *request,
                           model_service::ModelReply *reply) override {
        std::string prefix("server received init model call");

        ucloud::AlgoAPIName apiName;
        apiName= ucloud::AlgoAPIName(request->model_enum());

        std::map <int32_t, std::string> paramMap(request->model_param().begin(),request->model_param().end());

        Model::Manager manager;
        Model::STATUS status = manager.InitModel(apiName, paramMap);
        if (status != Model::SUCCESS) {
            reply->set_ret_code(Model::ERROR);
        }
        reply->set_ret_code(0);
        return Status::OK;
    }

    grpc::Status ReleaseModel(grpc::ServerContext *context, const model_service::ReleaseModelRequest *request,
                              model_service::ModelReply *reply) override {
        std::string prefix("server received release model call");
        Model::Manager manager;
        Model::STATUS status = manager.ReleaseModel(ucloud::AlgoAPIName(request->model_enum()));
        if (status != Model::SUCCESS) {
            reply->set_ret_code(Model::ERROR);
        }
        reply->set_ret_code(0);
        return grpc::Status::OK;
    }

    grpc::Status Inference(grpc::ServerContext *context, const model_service::InferenceRequest *request,
                           model_service::InferenceReply *reply) override {
        std::string prefix("server received inference model call");

        Model::Manager manager;
        model_service::ThresholdParam _param = request->param();
        model_service::InferenceInputData _data = request->data();
        ucloud::TvaiImage_S tvaImg;

        Model::InferenceParam inferParam(request->param().threshold(),request->param().nms_threshold());
        Model::InferenceResult inferRes;
        inferParam.nmsThreshold = _param.nms_threshold();
        inferParam.threshold = _param.threshold();

        inferParam.tvimage.pData = _data.pic_data();
        inferParam.tvimage.dataSize = _data.pic_size();
        inferParam.tvimage.height = _data.height();
        inferParam.tvimage.width = _data.width();
        inferParam.tvimage.stride = _data.stride();
        inferParam.tvimage.usePhyAddr = _data.use_physic_addr();
        inferParam.tvimage.uuid_cam = _data.sensor_id();
        Model::STATUS status = manager.Inference(ucloud::AlgoAPIName(request->model_enum()), &inferParam, &inferRes);
        if (status != Model::SUCCESS) {
            reply->set_ret_code(Model::ERROR);
            reply->set_err_message("inference failed");
            return grpc::Status::OK;
        }


        for (int i = 0; i < inferRes.size(); i++) {
            ucloud::BBox bb = inferRes[i];
            model_service::BBox *bbox = reply->add_bboxes();
            bbox->set_x0(bb.x0);
            bbox->set_y0(bb.y0);
            bbox->set_x1(bb.x1);
            bbox->set_y1(bb.y1);
            bbox->set_x(bb.x);
            bbox->set_y(bb.y);
            bbox->set_w(bb.w);
            bbox->set_h(bb.h);

            bbox->set_objectness(bb.objectness);
            bbox->set_confidence(bb.confidence);
            bbox->set_quality(bb.quality);
            bbox->set_objname(bb.objname);
            bbox->set_desc(bb.desc);
        }

        reply->set_ret_code(0);
        return grpc::Status::OK;
    }


};

void RunServer(std::string addr) {
    ModelServiceImpl service;

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    grpc::ServerBuilder builder;
    builder.AddListeningPort(addr, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr <grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << addr << std::endl;

    server->Wait();
}


int main() {
    std::string addr = "127.0.0.1:55555";
    RunServer(addr);
}



