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

