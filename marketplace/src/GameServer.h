#ifndef EMULATIONSTATION_ALL_GAMESERVER_H
#define EMULATIONSTATION_ALL_GAMESERVER_H

#include <string>
#include <grpc/grpc.h>
#include <grpc++/channel.h>

#include "../protos/AvailableGameServer.grpc.pb.h"

struct Game {
    Game(const std::string name, const std::string id) : name(name), id(id) {}

    bool operator==(const Game &other) const {
        return other.id == id && other.name == name;
    }

    std::string name, id;
};

class GameServer {
public:
    explicit GameServer(std::shared_ptr<grpc::Channel> channel);
    std::vector<Game> getDownloadableGames(const std::string console);
    Game getGameDetails(const std::string &id);

private:
    std::unique_ptr<AvailableGameServer::AvailableGameServer::Stub> serverStub;
};


#endif //EMULATIONSTATION_ALL_GAMESERVER_H
