all: MarketServer/MarketServer.pb.go UserServer/UserServer.pb.go UserDownloadServer/UserDownloadServer.pb.go AvailableGameServer/AvailableGameServer.pb.go

MarketServer/MarketServer.pb.go: MarketServer/MarketServer.proto
	protoc -I MarketServer/ --go_out=plugins=grpc:MarketServer MarketServer/MarketServer.proto
#	mv MarketServer.pb.go MarketServer

UserServer/UserServer.pb.go: UserServer/UserServer.proto
	protoc -I UserServer/ --go_out=plugins=grpc:UserServer UserServer/UserServer.proto
#	mv UserServer.pb.go UserServer

UserDownloadServer/UserDownloadServer.pb.go: UserDownloadServer/UserDownloadServer.proto
	protoc -I UserDownloadServer/ --go_out=plugins=grpc:UserDownloadServer UserDownloadServer/UserDownloadServer.proto
#	mv UserDownloadServer.pb.go UserDownloadServer

AvailableGameServer/AvailableGameServer.pb.go: AvailableGameServer/AvailableGameServer.proto
	protoc -I AvailableGameServer/ --go_out=plugins=grpc:AvailableGameServer AvailableGameServer/AvailableGameServer.proto
#	mv AvailableGameServer.pb.go AvailableGameServer