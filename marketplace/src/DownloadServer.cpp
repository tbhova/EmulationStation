#include "DownloadServer.h"

using namespace std;

using UserDownloadServer::DownloadRequest;
using UserDownloadServer::DownloadResponse;
using UserDownloadServer::UserDownloadListRequest;
using UserDownloadServer::DownloadsList;

DownloadServer::DownloadServer(std::shared_ptr<grpc::Channel> channel, GameServer* gameServer)
    : serverStub(UserDownloadServer::UserDownloadServer::NewStub(channel)), gameServer(gameServer) {}

string DownloadServer::getGameDownloadLink(std::string username, std::string password, std::string gameId) {
    grpc::ClientContext context;

    DownloadRequest request;
    request.set_username(username);
    request.set_password(password);
    request.set_gameid(gameId);

    DownloadResponse response;

    serverStub->DownloadGame(&context, request, &response);

    if (!response.available()) {
        return "";
    }
    return response.s3downloadlink();
}

vector<Game> DownloadServer::getPurchasedGames(std::string username) {
    vector<Game> games;

    grpc::ClientContext context;

    UserDownloadListRequest request;
    request.set_username(username);

    DownloadsList availableGames;

    serverStub->AvailableDownloads(&context, request, &availableGames);

    for (int i = 0; i < availableGames.games_size(); i++) {
        UserDownloadServer::Game game = availableGames.games(i);
        games.push_back(gameServer->getGameDetails(game.id()));
    }


    return games;
}
