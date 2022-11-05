#pragma once

#include "./ports.h"

#define VGA_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

enum vga_colour {
  BLACK,
  BLUE,
  GREEN,
  CYAN,
  RED,
  MAGENTA,
  BROWN,
  GREY,
  DARK_GREY,
  BRIGHT_BLUE,
  BRIGHT_GREEN,
  BRIGHT_CYAN,
  BRIGHT_RED,
  BRIGHT_MAGENTA,
  YELLOW,
  WHITE,
};

#define VGA_CTRL_REGISTER 0x3d4
#define VGA_DATA_REGISTER 0x3d5
#define VGA_OFFSET_LOW 0x0f
#define VGA_OFFSET_HIGH 0x0e

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define COLOURS 0x0f

void setVGACursor(int offset) {
  offset /= 2;
  outb(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH);
  outb(VGA_DATA_REGISTER, (uint16) (offset >> 8));
  outb(VGA_CTRL_REGISTER, VGA_OFFSET_LOW);
  outb(VGA_DATA_REGISTER, (uint16) (offset & 0xff));
}

int getVGACursor() {
  outb(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH);
  int offset = inb(VGA_DATA_REGISTER) << 8;
  outb(VGA_CTRL_REGISTER, VGA_OFFSET_LOW);
  offset += inb(VGA_DATA_REGISTER);
  return offset * 2;
}

void outCharAtLocation(char character, int offset) {
  unsigned char *videomemory = (unsigned char *) VIDEO_ADDRESS;
  videomemory[offset] = character;
  videomemory[offset + 1] = COLOURS;
}
