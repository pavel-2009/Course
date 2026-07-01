#include <grpcpp/grpcpp.h>

#include "predict.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using predictor::PredictRequest;
using predictor::PredictResponse;
using predictor::Predictor;


class PredictorImpl final : public Predictor::Service {

    public:
        Status Predict(
            ServerContext* context,
            const PredictRequest* request,
            PredictResponse* response
        ) override {

            if (request->text().find("love") != std::string::npos) {
                response->set_label("positive");
                response->set_score(0.95f);
            } else {
                response->set_label("negative");
                response->set_score(0.25f);
            };

            return Status::OK;

        };
};


int main() {

    PredictorImpl service;

    ServerBuilder builder;

    builder.AddListeningPort(
        "0.0.0.0:50051",
        grpc::InsecureServerCredentials()
    );

    builder.RegisterService(&service);

    auto server = builder.BuildAndStart();

    std::cout << "Server started\n";

    server->Wait();

}
