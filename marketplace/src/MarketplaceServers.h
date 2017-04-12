#ifndef EMULATIONSTATION_ALL_MARKETPLACESERVERS_H
#define EMULATIONSTATION_ALL_MARKETPLACESERVERS_H

#include "GameServer.h"
#include "UserServer.h"
#include "DownloadServer.h"

class MarketplaceServers {
public:
    MarketplaceServers();
    ~MarketplaceServers();
    GameServer* gameServer() { return  gameClient; }
    UserServer* userServer() { return userClient; }
    DownloadServer* downloadServer() { return downloadClient; }

private:
    GameServer *gameClient;
    UserServer *userClient;
    DownloadServer *downloadClient;
};


#endif //EMULATIONSTATION_ALL_MARKETPLACESERVERS_H
