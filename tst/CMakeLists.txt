project("test")

include(CTest)
enable_testing()

set(REPO ${CMAKE_CURRENT_SOURCE_DIR}/..)

#set(gtest_disable_pthreads on) #needed in MinGW
include(${REPO}/DownloadProject/DownloadProject.cmake)
download_project(
        PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        UPDATE_DISCONNECTED 1
)

set(test_SOURCES
        src/gTestMain.cpp)

set(test_HEADERS
        src/TestLoginServer.h src/TestDownloadServer.h src/TestGameServer.h)

find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})

add_executable(runUnitTests ${test_SOURCES} ${test_HEADERS})
target_link_libraries(runUnitTests gtest gmock grpc++_unsecure grpc gpr ${PROTOBUF_LIBRARIES} ${_gRPC_ALLTARGETS_LIBRARIES} marketplace)
#add_test(runUnitTests runUnitTests) #included in all tutorials but I don't know what it actually does.


add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)

if (TARGET runUnitTests)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../marketplace ${CMAKE_CURRENT_BINARY_DIR}/marketplace)
endif()
