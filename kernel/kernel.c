#include "include/types.h"
#include "drivers/output/io.h"
#include "drivers/input/cpu.h"
#include "drivers/input/keyboard.h"

// The entry point for our kernel.
void main() {

  clear();

  u32 loc = getVGACursor();

  intOut(loc);

  print("Booted into the kernel successfully!\n");

  loc = getVGACursor();

  intOut(loc);

}
