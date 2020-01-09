PREFIX ?= riscv64-linux-gnu-
MAKEFLAGS += --no-builtin-rules
.SUFFIXES:

.PHONY: all clean run

all: fib

clean:
	rm -rf fib *.o

lib.o: ../lib/lib.c ../lib/lib.h
	$(PREFIX)gcc -c $< -o $@ -march=rv32im -mabi=ilp32 -ffreestanding -nostdlib

main.o: main.c ../lib/lib.h
	$(PREFIX)gcc -c $< -o $@ -march=rv32im -mabi=ilp32 -ffreestanding -nostdlib

fib.o: fib.s
	$(PREFIX)gcc -c $< -o $@ -march=rv32im -mabi=ilp32

fib: lib.o main.o fib.o
	$(PREFIX)ld $^ -T ../lib/linker.lds -o $@ -melf32lriscv

.SECONDARY:
