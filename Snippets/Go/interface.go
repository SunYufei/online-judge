package main

type Phone interface {
	call()
}

type NokiaPhone struct {
}

type iPhone struct {
}

func (nokiaPhone NokiaPhone) call() {
	println("Nokia call()")
}

func (ip iPhone) call() {
	println("iPhone call()")
}

func main() {
	var phone Phone
	phone = new(NokiaPhone)
	phone.call()
	phone = new(iPhone)
	phone.call()
}
