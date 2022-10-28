#pragma once

#include "vga.c"

#ifndef VGA_H
#define VGA_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

uint32 vga_index;

uint16* vga_buffer;

// Terminal colors

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
