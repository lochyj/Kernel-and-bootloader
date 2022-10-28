#pragma once

int strlen(char* str) {
  int len = 0;
  while(str[len]) len++;
  return len;
}

int digit_count(int num) {
  uint32 count = 0;
  if(num == 0) return 1;
  while(num > 0) {
    count++; num = num/10;
  }
  return count;
}

void out_char(char ch) {
    vga_buffer[vga_index] = vga_driver(ch, VGA_TEXT, VGA_BACK);
    vga_index++;
}

void printT(char *str) {
  uint32 index = 0;
  while(str[index]){
    out_char(str[index]);
    index++;
  }
}

// New line index that stores the number of new lines generated
static int next_line_index = 1;

void newLn() {
  if(next_line_index >= 55){
    next_line_index = 0;
    clear_vga_buffer(&vga_buffer, VGA_TEXT, VGA_BACK);
  }
  vga_index = 80*next_line_index;
  next_line_index++;
}

void printLn(char *str) {
  printT(str);
  newLn();
}

void rmChar() {
  vga_index--;
  vga_buffer[vga_index] = vga_driver(' ', VGA_TEXT, VGA_BACK);
}

void clear() {
  vga_index = 0;
  clear_vga_buffer(&vga_buffer, VGA_TEXT, VGA_BACK);
}
