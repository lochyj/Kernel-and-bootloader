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

uint16 vga_driver(unsigned char ch, uint8 fore_color, uint8 back_color)  {
  uint16 ax = 0;
  uint8 ah = 0, al = 0;

  ah = back_color;
  ah <<= 4;
  ah |= fore_color;
  ax = ah;
  ax <<= 8;
  al = ch;
  ax |= al;

  return ax;
}

//clear video buffer array
void clear_vga_buffer(uint16 **buffer, uint8 fore_color, uint8 back_color) {
  uint32 i;
  for(i = 0; i < BUFSIZE; i++){
    (*buffer)[i] = vga_driver(NULL, fore_color, back_color);
  }
}

//initialize vga buffer
void init_vga_driver(uint8 fore_color, uint8 back_color) {
  vga_buffer = (uint16*)VGA_ADDRESS;  //point vga_buffer pointer to VGA_ADDRESS 
  clear_vga_buffer(&vga_buffer, fore_color, back_color);  //clear buffer
}