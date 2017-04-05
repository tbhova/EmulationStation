package Testing

import (
	"testing"
	"os"
)

func TestMain(m *testing.M) {
	//fmt.Println("Test begin")
	//go ServerManager.Run()
	//fmt.Println("Server registered")
	os.Exit(m.Run())
}
