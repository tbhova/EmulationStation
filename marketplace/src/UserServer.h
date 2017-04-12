#ifndef EMULATIONSTATION_ALL_USERSERVER_H
#define EMULATIONSTATION_ALL_USERSERVER_H

#include <string>
#include <grpc++/channel.h>

class UserServer {
public:
    explicit UserServer(std::shared_ptr<grpc::Channel> channel);

private:

};


#endif //EMULATIONSTATION_ALL_USERSERVER_H
