SHELL := /bin/bash

clean:
	rm -rf ./out/
	rm -rf ./isodir/

	mkdir ./out/
	mkdir -p isodir/boot/grub

%.o: %.asm
	nasm -felf32 $@ -o ./out/$<

# %.o: %.c
# 	gcc -m32 -c $@ -o ./out/$< -std=gnu99 -ffreestanding -O2 -Wall -Wextra

%.o: %.cpp
	g++ -m32 -c $@ -o ./out/$< -std=gnu99 -ffreestanding -O2 -Wall -Wextra

link:
	ld -m elf_i386 -T ./include/linker.ld ./out/*.o ./out/OPS.bin -nostdlib

build:
	grub-file --is-x86-multiboot ./out/OPS.bin

	cp ./out/OPS.bin isodir/boot/OPS.bin
	cp ./include/grub.cfg isodir/boot/grub/grub.cfg

	grub-mkrescue -o ./out/OPS.iso isodir

run:
	qemu-system-x86_64 -cdrom ./out/OPS.iso