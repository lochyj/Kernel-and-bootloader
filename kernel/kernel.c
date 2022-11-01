#include "kernel.h"
#include "drivers/vga.h"
#include "include/io.h"
#include "drivers/keyboard.h"
#include "include/time.h"

// The entry point for our kernel.
void main() {
  init_vga_driver(WHITE, BLACK);

  printLn("Booted into the kernel...");

  pause();
 
  printI(100);

}
