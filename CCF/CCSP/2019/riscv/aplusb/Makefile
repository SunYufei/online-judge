PREFIX ?= riscv64-linux-gnu-
MAKEFLAGS += --no-builtin-rules
.SUFFIXES:

.PHONY: all clean run

all: aplusb

clean:
	rm -rf aplusb *.o

lib.o: ../lib/lib.c ../lib/lib.h
	$(PREFIX)gcc -c $< -o $@ -march=rv32im -mabi=ilp32 -ffreestanding -nostdlib

main.o: main.c ../lib/lib.h
	$(PREFIX)gcc -c $< -o $@ -march=rv32im -mabi=ilp32 -ffreestanding -nostdlib

aplusb.o: aplusb.s
	$(PREFIX)gcc -c $< -o $@ -march=rv32im -mabi=ilp32

aplusb: lib.o main.o aplusb.o
	$(PREFIX)ld $^ -T ../lib/linker.lds -o $@ -melf32lriscv

.SECONDARY:
