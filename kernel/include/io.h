#pragma once

// TODO: there is something wrong with the print functions that cause the text to be over written on the same line and to not get reset when using the input function

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

// Line index

// TODO: Fix this | info up top
void printT(char *str) {
  uint32 index = 0;
  while(str[index]){
    out_char(str[index]);
    index++;
  }
}

char* reverse(char* str) {
  int len = strlen(str);
  char* rev = "";
  for(int i = 0; i < len; i++) {
    rev[i] = str[len - i - 1];
  }
  return rev;
}

char* itoa(int n, char s[]) {
  int i, sign;
  if ((sign = n) < 0)  /* record sign */
      n = -n;          /* make n positive */
  i = 0;
  do {       /* generate digits in reverse order */
      s[i++] = n % 10 + '0';   /* get next digit */
  } while ((n /= 10) > 0);     /* delete it */
  if (sign < 0) s[i++] = '-';
  s[i] = '\0';
  reverse(s);
  return s;
}


void printI(int num) {
  char str_num = 10;
  char* int_str = itoa(num, str_num);
  printT(int_str);
}



// New line index that stores the number of new lines generated
static int next_line_index = 1;

void newLn() {
  if (next_line_index >= 20) {
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
