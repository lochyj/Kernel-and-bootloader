#pragma once

#include "../drivers/ports.h"

int CMOS_READ(int addr) {
  int time = 0;
  outb(0x80|addr, 0x70);
  while((time = inb(0x71)) != 0){
    if(time > 0) return time;
  }
  return time;
}