#include "kernel.h"
#include "drivers/vga.h"
#include "../lib/io.h"
#include "drivers/keyboard.h"

// The entry point for our kernel.
void main() {
  init_vga_driver(WHITE, BLACK);

  printLn("This is not a kernel");
  printLn("This is the BEST");
  printT("Username: ");
  input();
}
