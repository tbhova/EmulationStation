all: MarketServer UserServer UserDownloadServer AvailableGameServer

MarketServer: MarketServer/MarketServer.proto
	protoc -I MarketServer/ --go_out=plugins=grpc:. MarketServer/MarketServer.proto
	mv MarketServer.pb.go MarketServer

UserServer: UserServer/UserServer.proto
	protoc -I UserServer/ --go_out=plugins=grpc:. UserServer/UserServer.proto
	mv UserServer.pb.go UserServer
	
UserDownloadServer: UserDownloadServer/UserDownloadServer.proto
	protoc -I UserDownloadServer/ --go_out=plugins=grpc:. UserDownloadServer/UserDownloadServer.proto
	mv UserDownloadServer.pb.go UserDownloadServer
	
AvailableGameServer: AvailableGameServer/AvailableGameServer.proto
	protoc -I AvailableGameServer/ --go_out=plugins=grpc:. AvailableGameServer/AvailableGameServer.proto
	mv AvailableGameServer.pb.go AvailableGameServer