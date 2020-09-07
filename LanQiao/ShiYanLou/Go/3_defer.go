package main

import "fmt"

func test() (result int) {
    defer func() {
        result = 12
    }()
    return 10
}

func main() {
    fmt.Println(test())     // 12
}