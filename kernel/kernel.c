#include "kernel.h"
#include "drivers/vga.h"
#include "include/io.h"
#include "drivers/keyboard.h"

// The entry point for our kernel.
void main() {
  init_vga_driver(WHITE, BLACK);

  printLn("Booted into the kernel...");

  char* info = "[OPS Lochyj - ROOT] # ";

  while (1) {
    char* uin = "";
    printLn(uin);
    uin = inputI(info);
    printLn(uin);
    uin[0] = 0;
  }

}
