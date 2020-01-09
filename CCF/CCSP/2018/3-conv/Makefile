CC = g++
CFLAGS = -Wall -O2 -mavx -fopenmp -lpthread

all: my_run test

my_run : main.cpp solve.cpp
	$(CC) $(CFLAGS) main.cpp solve.cpp -o $@

.PHONY: test clean
test : my_run
	./$?

clean :
	$(RM) my_run
