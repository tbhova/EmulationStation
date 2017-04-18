#ifndef EMULATIONSTATION_ALL_TESTUSERSERVER_H
#define EMULATIONSTATION_ALL_TESTUSERSERVER_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <grpc/grpc.h>
#include <grpc++/create_channel.h>

#include "../../marketplace/src/LoginServer.h"

using namespace testing;
using namespace std;

class LoginServerTest : public Test {
protected:
    LoginServer loginServer = LoginServer(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
};

TEST_F(LoginServerTest, TestLoginValid) {
    ASSERT_EQ(loginServer.login("UNAME", "NOT_PASSWORD"), "4989c6f6-0e69-11e7-93ae-92361f002671");
}

TEST_F(LoginServerTest, TestLoginBadPassword) {
    ASSERT_EQ(loginServer.login("UNAME", "PASSWORD1234"), "Invalid password");
}

TEST_F(LoginServerTest, TestLoginBadUsername) {
    ASSERT_EQ(loginServer.login("USERNAME", "NOT_PASSWORD"), "Invalid username");
}

#endif //EMULATIONSTATION_ALL_TESTUSERSERVER_H
