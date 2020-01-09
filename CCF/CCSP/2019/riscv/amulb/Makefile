PREFIX ?= riscv64-linux-gnu-
MAKEFLAGS += --no-builtin-rules
.SUFFIXES:

.PHONY: all clean run

all: amulb

clean:
	rm -rf amulb *.o

lib.o: ../lib/lib.c ../lib/lib.h
	$(PREFIX)gcc -c $< -o $@ -march=rv32im -mabi=ilp32 -ffreestanding -nostdlib

main.o: main.c ../lib/lib.h
	$(PREFIX)gcc -c $< -o $@ -march=rv32im -mabi=ilp32 -ffreestanding -nostdlib

amulb.o: amulb.s
	$(PREFIX)gcc -c $< -o $@ -march=rv32im -mabi=ilp32

amulb: lib.o main.o amulb.o
	$(PREFIX)ld $^ -T ../lib/linker.lds -o $@ -melf32lriscv

.SECONDARY:
