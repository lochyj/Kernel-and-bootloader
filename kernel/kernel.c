#include "include/types.h"
#include "drivers/output/io.h"
#include "drivers/input/cpu.h"
#include "drivers/input/keyboard.h"

// The entry point for our kernel.
void main() {

  clear();

  print("Number 1\n");
  print("Number 2\n");

  u16 time = CMOS_READ(0x00);

  do {
    time = CMOS_READ(0x00);
    intOut(time);
    print("\n");
    sleep(0x09FFFFFF);
  } while (1);

  char* in = input();
  print(in);

}
