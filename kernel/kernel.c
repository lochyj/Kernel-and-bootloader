#include "kernel.h"
#include "drivers/vga.h"
#include "include/io.h"
#include "drivers/keyboard.h"
#include "include/time.h"

// The entry point for our kernel.
void main() {

  clear();
  
  print("Hello World!\n");

}
