.set Magic, 0x1BADB002

.set Flags, 0

.set Checksum, -(Magic + Flags)

# Enable Multiboot
.section .multiboot

.long Magic
.long Flags
.long Checksum

stackBottom:
    .skip 1024

stackTop:
    .section .text
    .global _start
    .type _start, @function

_start:
    # Set up the stack
    mov $stackTop, %esp

    mov ax, 19 ; Graphics mode
    int 16

    call main

    cli

hltLoop:
    hlt
    jmp hltLoop

.size _start, . - _start
