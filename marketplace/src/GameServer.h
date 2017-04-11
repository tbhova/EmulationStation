#ifndef EMULATIONSTATION_ALL_GAMESERVER_H
#define EMULATIONSTATION_ALL_GAMESERVER_H

#include <string>
#include <grpc/grpc.h>

#include "../protos/AvailableGameServer.grpc.pb.h"

class GameServer {
public:
    GameServer();
    explicit GameServer(std::shared_ptr<grpc::Channel> channel);

private:
    std::unique_ptr<AvailableGameServer::AvialableGameServer::Stub> serverStub;
};


#endif //EMULATIONSTATION_ALL_GAMESERVER_H
