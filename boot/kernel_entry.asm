; Unused code

global _start
[bits 32]

_start:
    [extern kernel_main] ; call the main function from kernel.c
    call kernel_main ; Calls the kernel main function
    jmp $