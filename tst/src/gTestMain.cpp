#include "gtest/gtest.h"

//#include "../../marketplace/src/DownloadServer.cpp"
//#include "../../marketplace/src/GameServer.cpp"
//#include "../../marketplace/src/LoginServer.cpp"

#include "TestLoginServer.h"
#include "TestDownloadServer.h"
#include "TestGameServer.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}