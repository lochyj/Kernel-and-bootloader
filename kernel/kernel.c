#include "include/types.h"
#include "drivers/output/io.h"
#include "drivers/input/cpu.h"

// The entry point for our kernel.
void main() {

  char* video_memory = (char*) 0xb8000;
    *video_memory = 'X';

}
