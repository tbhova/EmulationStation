#include "GameServer.h"

#include <grpc++/channel.h>
#include <grpc++/create_channel.h>

using namespace std;

using AvailableGameServer::GameDetails;
using AvailableGameServer::GameFilters;
using AvailableGameServer::GameId;
using AvailableGameServer::GameIdList;
using AvailableGameServer::AvialableGameServer;

GameServer::GameServer(shared_ptr<grpc::Channel> channel)
        : serverStub(AvialableGameServer::NewStub(channel)) {}

vector<Game> GameServer::getDownloadableGames() {
    vector<Game> games = vector<Game>();

    grpc::ClientContext context;

    GameIdList idList;
    serverStub->GetAvailableGamesList(&context, GameFilters(), &idList);

    for (int i = 0; i < idList.ids_size(); i++) {
        const GameId id = idList.ids(i);

        GameDetails game;
        grpc::ClientContext getGameContext;
        serverStub->GetGameDetails(&getGameContext, id, &game);

        games.push_back(Game(game.title(), id.id()));
    }

    return games;
}
