#include "GameServer.h"
//#include "../protos/AvailableGameServer.pb.h"

#include <grpc/grpc.h>
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>

using namespace std;

using AvailableGameServer::GameDetails;
using AvailableGameServer::GameFilters;
using AvailableGameServer::GameId;
using AvailableGameServer::GameIdList;

GameServer::GameServer() : GameServer("127.0.0.1") {}

GameServer::GameServer(const std::string &ip) {
    const string serverLocation = ip + ":50051";
    grpc::CreateChannel(ip, grpc::InsecureChannelCredentials());
//    AvailableGameServer::
}