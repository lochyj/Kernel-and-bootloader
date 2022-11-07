#include "ports.h"

#ifndef DISPLAY_H
#define DISPLAY_H

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


u32 offset = 0;



void setVGACursor(int offset2) {
  offset += offset2;
}

u32 getVGACursor() {
  return offset;
}

void enableVGACursor() {
  outb(0x3D4, 0x0A);
  char curstart = inb(0x3D5) & 0x1F;

  outb(0x3D4, 0x0A);
  outb(0x3D5, curstart | 0x20);
}

void outCharAtLocation(char character, int offset) {
  unsigned char *videomemory = (unsigned char *) VIDEO_ADDRESS;
  videomemory[offset] = character;
  videomemory[offset + 1] = COLOURS;
}

#define MASK 0x3C6
#define READ 0xC7
#define WRITE 0xC8
#define DATA 0xC9

void initScreen() {
  outb(MASK, 0xFF);
  outb(WRITE, 0);
  for (int i = 0; i < 255; i++) {
    outb(DATA, (((i>>5)&7)<<5) | (((i>>2)&7)<<2) | ((i&3)<<0));
  }
  outb(DATA, 0x3F);
  outb(DATA, 0x3F);
  outb(DATA, 0x3F);
}

#endif
