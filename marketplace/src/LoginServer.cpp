#include "LoginServer.h"

using namespace std;

using UserServer::UsernameAvailable;
using UserServer::UserQuery;
using UserServer::LoginReply;
using UserServer::LoginRequest;
using UserServer::RegisterStatus;
using UserServer::RegisterRequest;

LoginServer::LoginServer(std::shared_ptr<grpc::Channel> channel)
    : serverStub(UserServer::UserServer::NewStub(channel)) {}

string LoginServer::login(const std::string username, const std::string password) {
    grpc::ClientContext context;
    LoginReply reply;

    LoginRequest request;
    request.set_username(username);
    request.set_password(password);
    serverStub->UserLogin(&context, request, &reply);

    switch (reply.status()) {
        case UserServer::LoginReply_LoginError_BAD_PASSWORD:
            return "Invalid password";
        case UserServer::LoginReply_LoginError_NONEXISTANT_USERNAME:
            return "Invalid username";
        case UserServer::LoginReply_LoginError_OK:
            return reply.id();
        default:
            return "Error";
    }
}
