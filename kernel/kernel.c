#include "kernel.h"
#include "drivers/vga.h"
#include "include/io.h"
#include "drivers/keyboard.h"
#include "include/time.h"

// The entry point for our kernel.
void main() {
  init_vga_driver(WHITE, BLACK);

  printLn("Booted into the kernel...");

  int val;
  val = CMOS_READ(0);
  printI(val);

  sleep(0x00FFFFFF);

  val = CMOS_READ(1);
  newLn();
  printI(val);

}
