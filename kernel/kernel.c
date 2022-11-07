#include "include/types.h"
#include "drivers/output/io.h"
#include "drivers/input/cpu.h"

// The entry point for our kernel.
void main() {

  
  enableVGACursor();

  print("Hello, World!\nADDDOF");

}
