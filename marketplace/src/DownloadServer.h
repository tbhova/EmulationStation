#ifndef EMULATIONSTATION_ALL_DOWNLOADSERVER_H
#define EMULATIONSTATION_ALL_DOWNLOADSERVER_H

#include <string>
#include <grpc++/channel.h>
#include <grpc/grpc.h>

#include "../protos/UserDownloadServer.grpc.pb.h"
#include "GameServer.h"


class DownloadServer {
public:
    explicit DownloadServer(std::shared_ptr<grpc::Channel> channel, GameServer* gameServer);

    std::string getGameDownloadLink(std::string username, std::string password, std::string gameId);

    std::vector<Game> getPurchasedGames(std::string username);

private:
    std::unique_ptr<UserDownloadServer::UserDownloadServer::Stub> serverStub;
    GameServer* gameServer;
};


#endif //EMULATIONSTATION_ALL_DOWNLOADSERVER_H
