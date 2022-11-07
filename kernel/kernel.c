#include "include/types.h"
#include "drivers/output/io.h"
#include "drivers/input/cpu.h"

// The entry point for our kernel.
void main() {

  clear();
  enableVGACursor();

  print("PLEASE WORK | 16\n");
  sleep(0x00FFFFFF);
  intOut(getVGACursor());

}
