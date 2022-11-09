#include "include/types.h"
#include "drivers/output/io.h"
#include "drivers/input/cpu.h"
#include "drivers/input/keyboard.h"

// The entry point for our kernel.
void main() {

  clear();

  print("Number 1\n");
  print("Number 2");

  char* in = input();
  print(in);


}
