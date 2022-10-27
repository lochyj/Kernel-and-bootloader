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

    call main

    cli

hltLoop:
    hlt
    jmp hltLoop

.size _start, . - _start
