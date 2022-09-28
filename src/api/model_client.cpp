#include <chrono>
#include <ctime>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#ifdef BAZEL_BUILD
#else

#include "protos/model.grpc.pb.h"

#endif

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;


class ModelClient {
public:
    ModelClient(std::shared_ptr <Channel> channel)
            : stub_(model_service::Model::NewStub(channel)) {}

    // Assembles the client's payload, sends it and presents the response back
    // from the server.
    std::string Inference(std::string data) {
        // Data we are sending to the server.

        model_service::InferenceRequest request;
        request.set_pic_data(data);

        model_service::InferenceReply reply;

        ClientContext context;

        // The actual RPC.
        auto millisec_start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        Status status = stub_->Inference(&context, request, &reply);
        auto millisec_end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        int d;
        d = millisec_end - millisec_start;
         std::cout << "cost: " << d << std::endl;

        // Act upon its status.
        if (status.ok()) {
            return reply.err_message();
        } else {
            std::cout << status.error_code() << ": " << status.error_message()
                      << std::endl;
            return "RPC failed";
        }
    }


private:
    std::unique_ptr <model_service::Model::Stub> stub_;
};

int main(int argc, char **argv) {
    std::string target_str = "127.0.0.1:55555";
    ModelClient client(grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
    std::string reply = client.Inference("a");
    std::cout << "received: " << reply << std::endl;
    return 0;
}