project("marketplace")

set(marketplace_SOURCES
        src/GameServer.cpp
        src/DownloadServer.cpp
        src/LoginServer.cpp
        src/MarketplaceServers.cpp)
set(marketplace_HEADERS
        src/GameServer.h
        src/LoginServer.h
        src/DownloadServer.h
        src/MarketplaceServers.h)

set(proto_SOURCES
        protos/AvailableGameServer.grpc.pb.cc
        protos/AvailableGameServer.pb.cc
        protos/MarketServer.grpc.pb.cc
        protos/MarketServer.pb.cc
        protos/UserDownloadServer.grpc.pb.cc
        protos/UserDownloadServer.pb.cc
        protos/UserServer.grpc.pb.cc
        protos/UserServer.pb.cc)
set(proto_HEADERS
        protos/AvailableGameServer.grpc.pb.h
        protos/AvailableGameServer.pb.h
        protos/MarketServer.grpc.pb.h
        protos/MarketServer.pb.h
        protos/UserDownloadServer.grpc.pb.h
        protos/UserDownloadServer.pb.h
        protos/UserServer.grpc.pb.h
        protos/UserServer.pb.h)

include_directories(${COMMON_INCLUDE_DIRS} ../marketplace/src)
add_library(marketplace STATIC ${proto_SOURCES} ${proto_HEADERS} ${marketplace_SOURCES} ${marketplace_HEADERS})
target_link_libraries(marketplace ${COMMON_LIBRARIES} grpc++_unsecure grpc gpr ${PROTOBUF_LIBRARY} ${_gRPC_ALLTARGETS_LIBRARIES})
