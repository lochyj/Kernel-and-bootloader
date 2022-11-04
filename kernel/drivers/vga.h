#pragma once

#ifndef VGA_H
#define VGA_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

uint32 vga_index;

uint16* vga_buffer;

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

// Defining constants

#define VGA_BACK BLACK
#define VGA_TEXT WHITE
#define VGA_ADDRESS 0xB8000
#define BUFSIZE 2200
#define NULL 0
#define VGA_WIDTH 80

#endif

// uint16 vga_driver(unsigned char ch, uint8 fore_color, uint8 back_color)  {
//   uint16 ax = 0;
//   uint8 ah = 0, al = 0;

//   ah = back_color;
//   ah <<= 4;
//   ah |= fore_color;
//   ax = ah;
//   ax <<= 8;
//   al = ch;
//   ax |= al;

//   return ax;
// }


//----

#define VGA_CTRL_REGISTER 0x3d4
#define VGA_DATA_REGISTER 0x3d5
#define VGA_OFFSET_LOW 0x0f
#define VGA_OFFSET_HIGH 0x0e

void set_cursor(int offset) {
    offset /= 2;
    outb(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH);
    outb(VGA_DATA_REGISTER, (unsigned char) (offset >> 8));
    outb(VGA_CTRL_REGISTER, VGA_OFFSET_LOW);
    outb(VGA_DATA_REGISTER, (unsigned char) (offset & 0xff));
}

int get_cursor() {
    outb(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH);
    int offset = inb(VGA_DATA_REGISTER) << 8;
    outb(VGA_CTRL_REGISTER, VGA_OFFSET_LOW);
    offset += inb(VGA_DATA_REGISTER);
    return offset * 2;
}


#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0f

void set_char_at_video_memory(char character, int offset) {
    unsigned char *vidmem = (unsigned char *) VIDEO_ADDRESS;
    vidmem[offset] = character;
    vidmem[offset + 1] = WHITE_ON_BLACK;
}
