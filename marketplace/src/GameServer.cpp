#include "GameServer.h"

using namespace std;

using AvailableGameServer::GameDetails;
using AvailableGameServer::GameFilters;
using AvailableGameServer::GameId;
using AvailableGameServer::GameIdList;

GameServer::GameServer(shared_ptr<grpc::Channel> channel)
        : serverStub(AvailableGameServer::AvailableGameServer::NewStub(channel)) {}

vector<Game> GameServer::getDownloadableGames(const string console) {
    vector<Game> games = vector<Game>();

    grpc::ClientContext context;

    GameFilters filters;
    filters.set_console(console);
    GameIdList idList;
    serverStub->GetAvailableGamesList(&context, filters, &idList);

    for (int i = 0; i < idList.ids_size(); i++) {
        const string id = idList.ids(i).id();
        games.push_back(getGameDetails(id));
    }

    return games;
}

Game GameServer::getGameDetails(const std::string &id) {
    GameDetails game;
    grpc::ClientContext getGameContext;
    GameId gameId;
    gameId.set_id(id);
    serverStub->GetGameDetails(&getGameContext, gameId, &game);
    return Game(game.title(), id);
}
