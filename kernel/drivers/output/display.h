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



void setVGACursor(int offset) {
  offset /= 2;
  outb(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH);
  outb(VGA_CTRL_REGISTER, VGA_OFFSET_LOW);
  outb(VGA_DATA_REGISTER, (u16) (offset & 0xff));
  outb(VGA_DATA_REGISTER, (u16) (offset >> 8));
}

u16 getVGACursor() {
    u16 pos = 0;
    outb(0x3D4, 0x0F);
    pos |= inb(0x3D5);
    outb(0x3D4, 0x0E);
    pos |= ((u16)inb(0x3D5)) << 8;
    return pos;
}

void enableVGACursor() {
    outb(0x3D4, 0x09);   // set maximum scan line register to 15
    outb(0x3D5, 0x0F);

    outb(0x3D4, 0x0B);   // set the cursor end line to 15
    outb(0x3D5, 0x0F);

    outb(0x3D4, 0x0A);   // set the cursor start line to 14 and enable cursor visibility
    outb(0x3D5, 0x0E);
}

// Old code
// int getVGACursor() {
//   outb(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH);
//   int offset = inb(VGA_DATA_REGISTER) << 8;
//   outb(VGA_CTRL_REGISTER, VGA_OFFSET_LOW);
//   offset += inb(VGA_DATA_REGISTER);
//   return offset * 2;
// }

void outCharAtLocation(char character, int offset) {
  unsigned char *videomemory = (unsigned char *) VIDEO_ADDRESS;
  videomemory[offset] = character;
  videomemory[offset + 1] = COLOURS;
}

// #define MASK 0x3C6
// #define READ 0xC7
// #define WRITE 0xC8
// #define DATA 0xC9

// void initScreen() {
//   outb(MASK, 0xFF);
//   outb(WRITE, 0);
//   for (int i = 0; i < 255; i++) {
//     outb(DATA, (((i>>5)&7)<<5) | (((i>>2)&7)<<2) | ((i&3)<<0));
//   }
//   outb(DATA, 0x3F);
//   outb(DATA, 0x3F);
//   outb(DATA, 0x3F);
// }

#endif
