// package main

const URL = "http://m.5ikfc.com/"

func max(num1, num2 int) int {
	if num1 > num2 {
		return num1
	} else {
		return num2
	}
}

func nextNumber() func() int {
	i := 0
	return func() int {
		i += 1
		return i
	}
}

type Books struct {
	title  string
	author string
	id     int
}

func main() {
	// Single Line
	/* Multi line */
	age := 32
	a := 4
	ptr := &a
	println(age, *ptr)
	if a < 20 {
		println(a)
	}
	next := nextNumber()
	println(next())
	println(next())
	println(next())

	var balance = []float32{0.0, 1.0, 2.0}
	println(balance[2])

	var p *int = nil
	println(p)

	var numbers []int
	numbers = append(numbers, 0)
	numbers = append(numbers, 1)
	numbers = append(numbers, 2)

	for i, num := range numbers {
		println(i, num)
	}

	iMap := make(map[string]string)
	iMap["a"] = "1"
	iMap["b"] = "1"
	iMap["c"] = "1"
	for key, value := range iMap {
		print(key, value)
	}
}
