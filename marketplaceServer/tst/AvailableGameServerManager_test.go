package Testing

import (
	gameServer "AvailableGamesServer"
	"golang.org/x/net/context"
	"log"
	"testing"
	"ServerManager"
	"google.golang.org/grpc"
)

//const (
//	address = "localhost:50051"
//)
//
//var client gameServer.AvialableGameServerClient
//
//func init() {
//	fmt.Println("Init client")
//	conn, err := grpc.Dial(address, grpc.WithInsecure())
//	if err != nil {
//		log.Fatalf("did not connect: %v", err)
//	}
//	defer conn.Close()
//	client = gameServer.NewAvialableGameServerClient(conn)
//}
//
//func TestGetAvailableGamesList(t *testing.T) {
//	response, err := client.GetAvailableGamesList(context.Background(), &gameServer.GameFilters{})
//	if err != nil {
//		log.Fatalf("Error querying server: %v", err)
//
//
//	}
//	log.Printf("Game ID 0: %s", response.Ids[0].Id)
//	if response.Ids[0].Id != "id 1" {
//		t.Errorf("1st id in list is %s instead of id 1", response.Ids[0].Id)
//	}
//}

func TestGetAvailableGamesList(t *testing.T) {
	var s *grpc.Server
	
	
	response, err := s.GetAvailableGamesList(context.Background(), &gameServer.GameFilters{})
	if err != nil {
		log.Fatalf("Error querying server: %v", err)


	}
	log.Printf("Game ID 0: %s", response.Ids[0].Id)
	if response.Ids[0].Id != "id 1" {
		t.Errorf("1st id in list is %s instead of id 1", response.Ids[0].Id)
	}
}