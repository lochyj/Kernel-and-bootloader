#include "kernel.h"
#include "drivers/vga.h"
#include "include/io.h"
#include "drivers/keyboard.h"

// The entry point for our kernel.
void main() {
  init_vga_driver(WHITE, BLACK);

  printLn("Booted into the kernel...");

  while (1) {
    char* uin = 0x00;
    uin = inputI("[OPS Lochyj - ROOT] # ");
    printLn(uin);
    uin[0] = 0;
  }

}
