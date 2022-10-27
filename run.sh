
# Compile the assembly bootloader files
as --32 ./boot/boot.asm -o ./out/boot.o

# Complile the kernel C files
gcc -m32 -c ./kernel/kernel.c -o ./out/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

# Link the kernel with kernel.o and the boot files
ld -m elf_i386 -T ./boot/linker.ld ./out/kernel.o ./out/boot.o -o ./out/MyOS.bin -nostdlib

#Check if the MyOS.bin file is x86
grub-file --is-x86-multiboot ./out/MyOS.bin

# Build the ISO file for running in QEMU
mkdir -p isodir/boot/grub
cp ./out/MyOS.bin isodir/boot/MyOS.bin
cp ./boot/grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o ./out/MyOS.iso isodir

# Run the ISO file in QEMU
qemu-system-x86_64 -cdrom ./out/MyOS.iso