PREFIX ?= riscv64-linux-gnu-
MAKEFLAGS += --no-builtin-rules
.SUFFIXES:

.PHONY: all clean run

all: fruit

clean:
	rm -rf fruit *.o

lib.o: ../lib/lib.c ../lib/lib.h
	$(PREFIX)gcc -c $< -o $@ -march=rv32im -mabi=ilp32 -ffreestanding -nostdlib

main.o: main.c ../lib/lib.h
	$(PREFIX)gcc -c $< -o $@ -march=rv32im -mabi=ilp32 -ffreestanding -nostdlib

fruit.o: fruit.s
	$(PREFIX)gcc -c $< -o $@ -march=rv32im -mabi=ilp32

fruit: lib.o main.o fruit.o
	$(PREFIX)ld $^ -T ../lib/linker.lds -o $@ -melf32lriscv

.SECONDARY:
