all: Update MarketServer UserServer UserDownloadServer AvailableGameServer

Update:
	mkdir -p protos
#	git submodule update --remote

MarketServer: ../marketplaceServer/src/MarketServer/MarketServer.proto
	protoc -I ../marketplaceServer/src/MarketServer/ --grpc_out=./protos --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ../marketplaceServer/src/MarketServer/MarketServer.proto
	protoc -I ../marketplaceServer/src/MarketServer/ --cpp_out=./protos ../marketplaceServer/src/MarketServer/MarketServer.proto

UserServer: ../marketplaceServer/src/UserServer/UserServer.proto
	protoc -I ../marketplaceServer/src/UserServer/ --grpc_out=./protos --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ../marketplaceServer/src/UserServer/UserServer.proto
	protoc -I ../marketplaceServer/src/UserServer/ --cpp_out=./protos ../marketplaceServer/src/UserServer/UserServer.proto

UserDownloadServer: ../marketplaceServer/src/UserDownloadServer/UserDownloadServer.proto
	protoc -I ../marketplaceServer/src/UserDownloadServer/ --grpc_out=./protos --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ../marketplaceServer/src/UserDownloadServer/UserDownloadServer.proto
	protoc -I ../marketplaceServer/src/UserDownloadServer/ --cpp_out=./protos ../marketplaceServer/src/UserDownloadServer/UserDownloadServer.proto

AvailableGameServer: ../marketplaceServer/src/AvailableGameServer/AvailableGameServer.proto
	protoc -I ../marketplaceServer/src/AvailableGameServer/ --grpc_out=./protos --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ../marketplaceServer/src/AvailableGameServer/AvailableGameServer.proto
	protoc -I ../marketplaceServer/src/AvailableGameServer/ --cpp_out=./protos ../marketplaceServer/src/AvailableGameServer/AvailableGameServer.proto