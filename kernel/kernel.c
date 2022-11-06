#include "kernel.h"
#include "drivers/vga.h"
#include "include/io.h"

// The entry point for our kernel.
void main() {

  clear();
  
  print("Hello World!\n");
  intOut(1000);

}
