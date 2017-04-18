#ifndef EMULATIONSTATION_ALL_TESTGAMESERVER_H
#define EMULATIONSTATION_ALL_TESTGAMESERVER_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <grpc++/security/credentials.h>
#include <grpc++/channel.h>
#include <grpc++/create_channel.h>

#include "../../marketplace/src/GameServer.h"

using namespace testing;
using namespace std;

class GameServerTest : public ::testing::Test {
protected:
    GameServer gameServer = GameServer(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
};

TEST_F(GameServerTest, TestGetGamesAll) {
    vector<Game> availableGames = gameServer.getDownloadableGames("");

    EXPECT_EQ(availableGames.size(), 2);
    EXPECT_THAT(availableGames, Contains(Game("GAME 1", "5ddeed7a-0e69-11e7-93ae-92361f002671")));
    EXPECT_THAT(availableGames, Contains(Game("The Italian Plumber", "69a29de6-0e69-11e7-93ae-92361f002671")));

}

TEST_F(GameServerTest, TestGetGamesConsole1) {
    vector<Game> availableGames = gameServer.getDownloadableGames("HORGAN RETRO");

    EXPECT_EQ(availableGames.size(), 1);
    EXPECT_THAT(availableGames, Contains(Game("GAME 1", "5ddeed7a-0e69-11e7-93ae-92361f002671")));
}

TEST_F(GameServerTest, TestGetGamesConsole2) {
    vector<Game> availableGames = gameServer.getDownloadableGames("MODERN HORGAN");

    EXPECT_EQ(availableGames.size(), 1);
    EXPECT_THAT(availableGames, Contains(Game("The Italian Plumber", "69a29de6-0e69-11e7-93ae-92361f002671")));

}

#endif //EMULATIONSTATION_ALL_TESTGAMESERVER_H
