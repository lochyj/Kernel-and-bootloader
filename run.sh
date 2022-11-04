echo "-------- removing old files --------"

# Remove the old output directories and files
rm -rf ./out/
rm -rf ./isodir/

echo "-------- re-creating directories --------"

# Re-create output directories
mkdir ./out/
mkdir -p isodir/boot/grub

echo "-------- assembly compiler --------"

# Compile the assembly bootloader files
nasm -felf32 ./boot/boot.asm -o ./out/boot.o

echo "-------- C compiler --------"

# Complile the kernel C files
gcc -m32 -c ./kernel/kernel.c -o ./out/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

echo "-------- linker --------"

# Link the kernel with kernel.o and the boot files
ld -m elf_i386 -T ./include/linker.ld ./out/kernel.o ./out/boot.o -o ./out/OPS.bin -nostdlib

echo "-------- x86 check --------"

#Check if the OPS.bin file is x86
grub-file --is-x86-multiboot ./out/OPS.bin

echo "-------- copy --------"

# Copy the kernel to the isodir
cp ./out/OPS.bin isodir/boot/OPS.bin
cp ./include/grub.cfg isodir/boot/grub/grub.cfg

echo "-------- iso build --------"

# Build the ISO file for running in QEMU
grub-mkrescue -o ./out/OPS.iso isodir

echo "-------- qemu run --------"

# Run the ISO file in QEMU
qemu-system-x86_64 -cdrom ./out/OPS.iso