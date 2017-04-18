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

TEST_F(LoginServerTest, TestLogin) {
    ASSERT_EQ(0,0);
}

#endif //EMULATIONSTATION_ALL_TESTUSERSERVER_H
