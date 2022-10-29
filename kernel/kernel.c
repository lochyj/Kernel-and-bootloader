#include "kernel.h"
#include "drivers/vga.h"
#include "../include/io.h"
#include "drivers/keyboard.h"

// The entry point for our kernel.
void main() {
  init_vga_driver(WHITE, BLACK);

  printLn("Booted into the kernel...");

  update_cursor(1, 1);

  while (1){
    char* uin = inputI("[OPS - ROOT] # ");
    newLn();
    printLn(uin);
    uin = "";
  }
}
