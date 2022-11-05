#pragma once

// #include "../drivers/keyboard.h"

int strlen(char* str) {
  int len = 0;
  while(str[len]) len++;
  return len;
}

int digit_count(int num) {
  uint32 count = 0;
  if (num == 0) return 1;
  while (num > 0) {
    count++; num = num/10;
  }
  return count;
}

int getRow(int offset) {
  return offset / (2 * MAX_COLS);
}

int getOffset(int col, int row) {
  return 2 * (row * MAX_COLS + col);
}

int moveToNewLine(int offset) {
  return get_offset(0, getRow(offset) + 1);
}

void memCpy(char *source, char *dest, int nbytes) {
  int i;
  for (i = 0; i < nbytes; i++) {
    *(dest + i) = *(source + i);
  }
}

int scrollLn(int offset) {
  memCpy(
    (char *) (getOffset(0, 1) + VIDEO_ADDRESS),
    (char *) (getOffset(0, 0) + VIDEO_ADDRESS),
    MAX_COLS * (MAX_ROWS - 1) * 2
  );

  for (int col = 0; col < MAX_COLS; col++) {
    outCharAtLocation(' ', getOffset(col, MAX_ROWS - 1));
  }

  return offset - 2 * MAX_COLS;
}

void print(char *string) {
  int offset = getVGACursor();
  int i = 0;
  while (string[i] != 0) {
    if (offset >= MAX_ROWS * MAX_COLS * 2) {
      offset = scrollLn(offset);
    }
    if (string[i] == '\n') {
      offset = moveToNewLine(offset);
    } else {
      outCharAtLocation(string[i], offset);
      offset += 2;
    }
    i++;
  }
  setVGACursor(offset);
}

void clear() {
  for (int i = 0; i < MAX_COLS * MAX_ROWS; ++i) {
    outCharAtLocation(' ', i * 2);
  }
  setVGACursor(getOffset(0, 0));
}

// TODO: Improve this soon

char* reverse(char** str) {
  char* temp = str;
  int n = strlen(temp);

  for (int i = 0; i < n / 2; i++) {
    char ch = str[i];
    str[i] = str[n - i - 1];
    str[n - i - 1] = ch;
  }
}

char* itoa(int n, char s[]) {
  int i, sign;
  if ((sign = n) < 0)  /* record sign */
    n = -n;           /* make n positive */
  i = 0;
  do {                          /* generate digits in reverse order */
    s[i++] = n % 10 + '0';     /* get next digit */
  } while ((n /= 10) > 0);    /* delete it */
  if (sign < 0) s[i++] = '-';
  s[i] = '\0';
  char* rev = reverse(&s);
  return rev;
}

void intOut(int num) {
  char str_num = digit_count(num);
  char* int_str = itoa(num, str_num);
  print(int_str);
}
