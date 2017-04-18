#ifndef EMULATIONSTATION_ALL_TESTDOWNLOADSERVER_H
#define EMULATIONSTATION_ALL_TESTDOWNLOADSERVER_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../marketplace/src/DownloadServer.h"

using namespace testing;
using namespace std;

class DownloadServerTest : public Test {
private:
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
    GameServer gameServer = GameServer(channel);
protected:
    DownloadServer downloadServer = DownloadServer(channel, &gameServer);
};

TEST_F(DownloadServerTest, TestGetPurchases) {
    vector<Game> games = downloadServer.getPurchasedGames("UNAME");

    EXPECT_THAT(games, Contains(Game("GAME 1", "5ddeed7a-0e69-11e7-93ae-92361f002671")));
    EXPECT_THAT(games, Contains(Game("The Italian Plumber", "69a29de6-0e69-11e7-93ae-92361f002671")));
}

TEST_F(DownloadServerTest, TestGetPurchasesNoUser) {
    vector<Game> games = downloadServer.getPurchasedGames("USERNAME");
    ASSERT_EQ(games.size(), 0);
}

TEST_F(DownloadServerTest, TestGetDownloadLinkValid) {
    string result = downloadServer.getGameDownloadLink("UNAME", "NOT_PASSWORD", "69a29de6-0e69-11e7-93ae-92361f002671");
    ASSERT_EQ(result, "s3 link to game 2");
}

TEST_F(DownloadServerTest, TestGetDownloadLinkInvalidUsername) {
    string result = downloadServer.getGameDownloadLink("horgan", "NOT_PASSWORD", "69a29de6-0e69-11e7-93ae-92361f002671");
    ASSERT_EQ(result, "");
}

TEST_F(DownloadServerTest, TestGetDownloadLinkInvalidPassword) {
    string result = downloadServer.getGameDownloadLink("UNAME", "PASSWORD", "69a29de6-0e69-11e7-93ae-92361f002671");
    ASSERT_EQ(result, "");
}

TEST_F(DownloadServerTest, TestGetDownloadLinkInvalidGameId) {
    string result = downloadServer.getGameDownloadLink("UNAME", "NOT_PASSWORD", "79a29de6-0e69-11e7-93ae-92361f002671");
    ASSERT_EQ(result, "");
}

#endif //EMULATIONSTATION_ALL_TESTDOWNLOADSERVER_H
