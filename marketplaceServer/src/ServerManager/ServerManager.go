package ServerManager

import (
	"golang.org/x/net/context"
	"net"
	"log"
	"google.golang.org/grpc/reflection"
	"google.golang.org/grpc"
	pb "MarketServer"
	"database/sql"
	_ "github.com/lib/pq"
)

var s *grpc.Server

var db *sql.DB = nil

func init() {
	var err error
	db, err = sql.Open("postgres", "user=postgres password=hespw123 dbname=content sslmode=verify-full")
	if err != nil {
		log.Fatal(err)
	}

	lis, err := net.Listen("tcp", port)
	if err != nil {
		log.Fatalf("failed to listen: %v", err)
	}
	s = grpc.NewServer()
	pb.RegisterGreeterServer(s, &GreetingServer{})
	
	RunLoginServer()
	RunUserDownloadServer()
	RunAvailableGameServer()
	
	// Register reflection service on gRPC GreetingServer.
	reflection.Register(s)
	if err := s.Serve(lis); err != nil {
		log.Fatalf("failed to serve: %v", err)
	}


}

const (
	port = ":50051"
)

// Server types used to implement servers.
type GreetingServer struct{}

// SayHello implements helloworld.GreeterServer
func (s *GreetingServer) SayHello(ctx context.Context, in *pb.HelloRequest) (*pb.HelloReply, error) {
	return &pb.HelloReply{Message: "Hello " + in.Name}, nil
}

func Run() {
	
}
