project("marketplace")

set(marketplace_SOURCES
        src/GameServer.cpp src/DownloadServer.cpp src/UserServer.cpp)
set(marketplace_HEADERS
        src/GameServer.h src/UserServer.h src/DownloadServer.h)

include_directories(${COMMON_INCLUDE_DIRS} ../marketplace/src)
add_library(marketplace STATIC ${marketplace_SOURCES} ${marketplace_HEADERS})
target_link_libraries(marketplace ${COMMON_LIBRARIES})
