PREFIX ?= riscv64-linux-gnu-
MAKEFLAGS += --no-builtin-rules
.SUFFIXES:

.PHONY: all clean run

all: sort

clean:
	rm -rf sort *.o

lib.o: ../lib/lib.c ../lib/lib.h
	$(PREFIX)gcc -c $< -o $@ -march=rv32im -mabi=ilp32 -ffreestanding -nostdlib

main.o: main.c ../lib/lib.h
	$(PREFIX)gcc -c $< -o $@ -march=rv32im -mabi=ilp32 -ffreestanding -nostdlib

sort.o: sort.s
	$(PREFIX)gcc -c $< -o $@ -march=rv32im -mabi=ilp32

sort: lib.o main.o sort.o
	$(PREFIX)ld $^ -T ../lib/linker.lds -o $@ -melf32lriscv

.SECONDARY:
