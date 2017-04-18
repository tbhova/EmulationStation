package ServerManager

import (
	GameServer "AvailableGameServer"
	"golang.org/x/net/context"
	"log"
	"database/sql"
)

// Data type used to implement the AvailableGameServer
type AvailableGameServer struct{}

func runAvailableGameServer() {
	GameServer.RegisterAvailableGameServerServer(s, &AvailableGameServer{})
}

func (s *AvailableGameServer) GetAvailableGamesList(ctx context.Context, in *GameServer.GameFilters) (*GameServer.GameIdList, error) {
	var ids []*(GameServer.GameId) = make([]*(GameServer.GameId), 0)

	var rows *sql.Rows
	var err error
	if in.Console != "" {
		rows, err = db.Query("SELECT ID FROM GAME WHERE CONSOLE = $1", in.Console)
	} else {
		rows, err = db.Query("SELECT ID FROM GAME")
	}
	
	if err != nil {
		log.Fatal(err)
		return &GameServer.GameIdList{Ids: ids}, err
	}

	defer rows.Close()
	for rows.Next() {
		var id string
		err := rows.Scan(&id)
		
		if err != nil {
			log.Fatal(err)
			return &GameServer.GameIdList{Ids: ids}, err
		}
		
		var gameId *GameServer.GameId = new(GameServer.GameId)
		gameId.Id = id
		ids = append(ids, gameId)
	}
	
	if err := rows.Err(); err != nil {
		log.Fatal(err)
		return nil, err
	}
	
	//ids[0] = &GameServer.GameId{"id 1"}
	
	return &GameServer.GameIdList{Ids: ids}, nil
}

func (s *AvailableGameServer) GetGameDetails(ctx context.Context, id *GameServer.GameId) (*GameServer.GameDetails, error) {
	var details *GameServer.GameDetails = new(GameServer.GameDetails)
	
	err := db.QueryRow("SELECT ID, TITLE, CONSOLE, RELEASE_DATE, DEVELOPER, PUBLISHER, GENRE, PLAYERS, PRICE FROM GAME WHERE ID= $1", id.Id).
		Scan(&details.Id, &details.Title, &details.Console, &details.ReleaseDate, &details.Developer, &details.Publisher, &details.Genre, &details.Players, &details.Price)
	
	if err != nil {
		log.Fatalf("Get game id: %s \n Error: %s", id.GetId(), err)
		return details, err
	}
	
	return details, nil
}