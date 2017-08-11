package main

import (
        "fmt"

        "github.com/naturali/LevelDBGoWrapper/leveldbwrapperlib"
)

func main() {
        db := leveldbwrapperlib.NewLevelDBInterface()
        db.Put("name", "elsa");
        fmt.Println(db.Get("name"))
}
