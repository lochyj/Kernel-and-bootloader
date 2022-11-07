echo "-------- removing old files --------"

# Remove the old output directories and files
rm -rf ./out/

echo "-------- re-creating directories --------"

# Re-create output directories
mkdir ./out/

echo "-------- assembly compiler --------"

# Compile the assembly bootloader files
nasm ./boot/kernel-entry.asm -f elf -o ./out/boot.o
nasm ./boot/mbr.asm -f bin -o ./out/mbr.o

echo "-------- C compiler --------"

# Complile the kernel C files
gcc -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c ./kernel/kernel.c -o ./out/kernel.o

echo "-------- linker --------"

# Link the kernel with kernel.o and the boot files
ld -m elf_i386 ./out/kernel.o ./out/boot.o -o ./out/binaries.bin -nostdlib --oformat binary -Ttext 0x1000
cat ./out/mbr.o ./out/binaries.bin > ./out/Image.bin

echo "-------- qemu run --------"

# Run the ISO file in QEMU
qemu-system-i386 -fda ./out/Image.bin