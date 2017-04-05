package main

import (
	"os/exec"
	"fmt"
	"sync"
	"ServerManager"
)

func flywayMigration(wg *sync.WaitGroup) {
	out, err := exec.Command("flyway", "migrate").Output()
	
	if err != nil {
		fmt.Println("Error occured running flyway migration")
		fmt.Printf("%s\n", err)
	}
	fmt.Printf("%s\n", out)
	
	wg.Done()
}

func init() {
	fmt.Println("init")
	wg := new(sync.WaitGroup)
	wg.Add(1)
	go flywayMigration(wg)
	wg.Wait()
}

func main() {
	fmt.Println("main")
	ServerManager.Run()
}
