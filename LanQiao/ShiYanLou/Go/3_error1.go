package main

import (
	"errors"
	"fmt"
)

func foo() {
	panic(errors.New("i'm a bug"))
	return
}

func test1() (result int) {
	defer func() {
		if r := recover(); r != nil {
			err := r.(error)
			fmt.Println("Cache Exception:", err)
		}
	}()
	foo()
	return 10
}

func main() {
	fmt.Println(test1()) // 0
}
