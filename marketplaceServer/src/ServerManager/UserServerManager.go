package ServerManager

import (
	"golang.org/x/net/context"
	"UserServer"
	"database/sql"
	"log"
)

// Data type use to implement login server service
type LoginServer struct{}

func runLoginServer() {
	UserServer.RegisterUserServerServer(s, &LoginServer{})
}

// Define UsernameAvailable
func (s *LoginServer) CheckUserExists(ctx context.Context, in *UserServer.UserQuery) (*UserServer.UsernameAvailable, error) {
	var reply *UserServer.UsernameAvailable = new(UserServer.UsernameAvailable)
	reply.EmailExists = false
	reply.UsernameExists = false
	
	rows, err := db.Query("SELECT USERNAME FROM USERS WHERE USERNAME = $1 OR EMAIL = $2", in.Username)
	if err != nil {
		log.Fatal(err)
		return reply, err
	}
	
	for rows.Next() {
		var username string
		err := rows.Scan(&username)
		if err != nil {
			log.Fatal(err)
			return reply, err
		}
		if len(username) > 0 {
			reply.UsernameExists = true
			return reply, nil
		}
	}
	
	rows, err = db.Query("SELECT EMAIL FROM USERS WHERE EMAIL = $1", in.Email)
	if err != nil {
		log.Fatal(err)
		return reply, err
	}
	
	for rows.Next() {
		var email string
		err := rows.Scan(&email)
		if err != nil {
			log.Fatal(err)
			return reply, err
		}
		if len(email) > 0 {
			reply.EmailExists = true
			return reply, nil
		}
	}
	
	return reply, nil
}

// Define LoginUser
func (s *LoginServer) UserLogin(ctx context.Context, in *UserServer.LoginRequest) (*UserServer.LoginReply, error) {
	var reply *UserServer.LoginReply = new(UserServer.LoginReply)
	reply.Id = ""
	
	userExists, err := s.CheckUserExists(ctx, &UserServer.UserQuery{Username: in.Username})
	if err != nil {
		log.Fatal(err)
		reply.Status = UserServer.LoginReply_NONEXISTANT_USERNAME
		return reply, err
	}
	
	if !userExists.UsernameExists {
		reply.Status = UserServer.LoginReply_NONEXISTANT_USERNAME
		return reply, nil
	}
	
	var userId string
	err = db.QueryRow("SELECT ID FROM USER WHERE USER = $1 AND PASSWORD = $2").Scan(&userId)
	
	switch {
	case err == sql.ErrNoRows:
		reply.Status = UserServer.LoginReply_BAD_PASSWORD
		return reply, nil
	case err != nil:
		log.Fatal(err)
		reply.Status = UserServer.LoginReply_BAD_PASSWORD
	}
	
	reply.Status = UserServer.LoginReply_OK
	reply.Id = userId
	return reply, nil
}

// Define RegisterUser
func (s *LoginServer) RegisterUser(ctx context.Context, in *UserServer.RegisterRequest) (*UserServer.RegisterStatus, error) {
	var reply *UserServer.RegisterStatus
	
	userExists, err := s.CheckUserExists(ctx, &UserServer.UserQuery{Username: in.Username, Email: in.Email})
	if err != nil {
		log.Fatal(err)
		reply.Status = UserServer.RegisterStatus_TAKEN_USERNAME
		return reply, err
	}
	
	if userExists.UsernameExists {
		reply.Status = UserServer.RegisterStatus_TAKEN_USERNAME
		return reply, nil
	}
	if userExists.EmailExists {
		reply.Status = UserServer.RegisterStatus_TAKEN_EMAIL
		return reply, nil
	}
	
	var userId string
	err = db.QueryRow("INSERT INTO USER (FIRST_NAME, LAST_NAME, EMAIL, USERNAME, PASSWORD) VALUES ($1, $2, $3, $4, $5) RETURNING ID",
		in.FistName, in.LastName, in.Email, in.Username, in.Password,).Scan(&userId)
	
	if err != nil {
		log.Fatal(err)
		reply.Status = UserServer.RegisterStatus_TAKEN_USERNAME
		return reply, err
	}
	
	reply.Status = UserServer.RegisterStatus_OK
	reply.UserId = userId
	return reply, nil
}