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