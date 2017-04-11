all: Update MarketServer UserServer UserDownloadServer AvailableGameServer

Update:
#	git submodule update --remote

MarketServer: ../marketplaceServer/src/MarketServer/MarketServer.proto
	protoc -I ../marketplaceServer/src/MarketServer/ --cpp_out=./protos ../marketplaceServer/src/MarketServer/MarketServer.proto

UserServer: ../marketplaceServer/src/UserServer/UserServer.proto
	protoc -I ../marketplaceServer/src/UserServer/ --cpp_out=./protos ../marketplaceServer/src/UserServer/UserServer.proto
	
UserDownloadServer: ../marketplaceServer/src/UserDownloadServer/UserDownloadServer.proto
	protoc -I ../marketplaceServer/src/UserDownloadServer/ --cpp_out=./protos ../marketplaceServer/src/UserDownloadServer/UserDownloadServer.proto
	
AvailableGameServer: ../marketplaceServer/src/AvailableGameServer/AvailableGameServer.proto
	protoc -I ../marketplaceServer/src/AvailableGameServer/ --cpp_out=./protos ../marketplaceServer/src/AvailableGameServer/AvailableGameServer.proto