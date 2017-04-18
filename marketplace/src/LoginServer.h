#ifndef EMULATIONSTATION_ALL_USERSERVER_H
#define EMULATIONSTATION_ALL_USERSERVER_H

#include <string>
#include <grpc++/channel.h>
#include <grpc/grpc.h>

#include "../protos/UserServer.grpc.pb.h"

class LoginServer {
public:
    explicit LoginServer(std::shared_ptr<grpc::Channel> channel);

    bool usernameAvailable(const std::string username);
    bool emailAvailable(const std::string email);

    std::string login(const std::string username, const std::string password);



private:
    UserServer::UsernameAvailable checkUser(const std::string username, const std::string email);

    std::unique_ptr<UserServer::UserServer::Stub> serverStub;
};


#endif //EMULATIONSTATION_ALL_USERSERVER_H
