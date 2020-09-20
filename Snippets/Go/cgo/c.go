package main

/*
#include "c.hpp"
*/
import "C"

func main() {
	a := C.int(1)
	b := C.int(2)
	s := C.sum(a, b)
	println(s)
}
