#ifndef EMULATIONSTATION_ALL_TESTGAMESERVER_H
#define EMULATIONSTATION_ALL_TESTGAMESERVER_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <grpc++/channel.h>
#include <grpc++/create_channel.h>

#include "../../marketplace/src/GameServer.h"

using namespace testing;
using namespace std;

class GameServerTest {
protected:
    GameServer gameServer = GameServer(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
};

TEST_F(GameServerTest, Test) {
    
}

#endif //EMULATIONSTATION_ALL_TESTGAMESERVER_H
