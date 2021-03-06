#include <fstream>
#include <iostream>
#include <memory>


#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include <nlohmann/json.hpp>

#include "suggestService.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using suggestService::SuggestRequest;
using SuggestService::Suggest;
using suggestService::SuggestResponse;
using suggestService::suggestService;


class SuggestServiceImpl final : public suggestService::Service {
 public:
  SuggestServiceImpl(const std::string& filename = "suggestions.json",
                     const int duration = 15) {
    std::thread upgrade(&SuggestServiceImpl::upgradeVariants, this, filename, duration);
    upgrade.detach();
  }

 private:
  Status Query(ServerContext* context, const SuggestRequest* request,
               SuggestResponse* response) override {
    google::protobuf::RepeatedPtrField<Suggest> goodVariants;
    std::shared_lock<std::shared_mutex> lock(mutex);
    int position = 0;
    for (const auto& variant : variants) {
      if (variant.id == request->query()) {
        Suggest suggest;
        suggest.set_text(variant.name);
        suggest.set_position(position);
        ++position;
        goodVariants.Add(suggest);
      }
    }
    lock.unlock();
    *response->mutable_suggest_answer() = goodVariants;
    return Status::OK;
  }

  void upgradeVariants(const std::string& filename, const int duration) {
    while(true) {
      std::unique_lock<std::shared_mutex> lock(mutex);
      std::ifstream file{filename};
      if (!file) {
        throw std::runtime_error{"unable to open json: " + filename};
      }
      nlohmann::json suggests;
      file >> suggests;
      file.close();
      for (const auto& item : suggests) {
        variants.insert(Suggestion(item));
      }
      lock.unlock();
      std::this_thread::sleep_for(std::chrono::minutes(duration));
    }
  }

  std::set<Suggestion> variants;
  std::shared_mutex mutex;
};

void RunServer() {
  std::string server_address("0.0.0.0:9090");
  SuggestServiceImpl service;

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}



int main(int argc, char** argv) {
  makeSuggestionsJson();
  RunServer();

  return 0;
}
