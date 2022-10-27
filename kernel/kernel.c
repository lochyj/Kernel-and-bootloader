#include "kernel.h"
#include "drivers/vga.h"

// The entry point for our kernel.

void main() {
    // Init the VGA Driver
    // (Text colour, Background colour)
    init_vga_driver(WHITE, BLACK);

    char* string = "Hello, World!";

    for(int i = 0; i < 13; i++) {
      vga_buffer[i] = vga_driver(string[i], WHITE, BLACK);
    }
}