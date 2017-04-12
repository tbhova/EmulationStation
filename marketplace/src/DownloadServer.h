#ifndef EMULATIONSTATION_ALL_DOWNLOADSERVER_H
#define EMULATIONSTATION_ALL_DOWNLOADSERVER_H

#include <string>
#include <grpc++/channel.h>

class DownloadServer {
public:
    explicit DownloadServer(std::shared_ptr<grpc::Channel> channel);

private:
};


#endif //EMULATIONSTATION_ALL_DOWNLOADSERVER_H
