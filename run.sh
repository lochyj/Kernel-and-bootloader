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
gcc -m32 -ffreestanding -fno-pic -c ./kernel/kernel.c -o ./out/kernel.o

echo "-------- linker --------"

# Link the kernel with kernel.o and the boot files
ld -m elf_i386 -T ./include/linker.ld ./out/kernel.o ./out/boot.o -o ./out/kernel.bin -nostdlib --oformat binary -Ttext 0x1000
cat ./out/mbr.o ./out/kernel.bin > ./out/OPS.bin

echo "-------- qemu run --------"

# Run the ISO file in QEMU
qemu-system-x86_64 -drive format=raw,file=./out/OPS.bin