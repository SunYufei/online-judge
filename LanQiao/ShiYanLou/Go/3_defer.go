package shiyanlou

import "fmt"

func test() (result int) {
    defer func() {
        result = 12
    }()
    return 10
}

func main3_1() {
    fmt.Println(test())     // 12
}