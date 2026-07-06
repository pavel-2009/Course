#include <grpcpp/grpcpp.h>

#include "predict.grpc.pb.h"

using predictor::PredictRequest;
using predictor::PredictResponse;
using predictor::Predictor;


int main()
{
    auto channel =
        grpc::CreateChannel(
            "localhost:50051",
            grpc::InsecureChannelCredentials());

    auto stub =
        Predictor::NewStub(channel);

    PredictRequest request;
    request.set_text("I C++");

    PredictResponse response;

    grpc::ClientContext context;

    auto status =
        stub->Predict(
            &context,
            request,
            &response);

    if (status.ok())
    {
        std::cout
            << response.label()
            << " "
            << response.score()
            << '\n';
    }
}