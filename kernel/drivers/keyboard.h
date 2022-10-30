#pragma once

#ifndef KEYBOARD_H
#define KEYBOARD_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

#define KEYBOARD_PORT 0x60

#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

// update for qwerty us

#define KEY_A 0x1E
#define KEY_B 0x30
#define KEY_C 0x2E
#define KEY_D 0x20
#define KEY_E 0x12
#define KEY_F 0x21
#define KEY_G 0x22
#define KEY_H 0x23
#define KEY_I 0x17
#define KEY_J 0x24
#define KEY_K 0x25
#define KEY_L 0x26
#define KEY_M 0x32
#define KEY_N 0x31
#define KEY_O 0x18
#define KEY_P 0x19
#define KEY_Q 0x10
#define KEY_R 0x13
#define KEY_S 0x1F
#define KEY_T 0x14
#define KEY_U 0x16
#define KEY_V 0x2F
#define KEY_W 0x11
#define KEY_X 0x2D
#define KEY_Y 0x15
#define KEY_Z 0x2C
#define KEY_1 0x02
#define KEY_2 0x03
#define KEY_3 0x04
#define KEY_4 0x05
#define KEY_5 0x06
#define KEY_6 0x07
#define KEY_7 0x08
#define KEY_8 0x09
#define KEY_9 0x0A
#define KEY_0 0x0B
#define KEY_MINUS 0x0C
#define KEY_EQUAL 0x0D
#define KEY_SQUARE_OPEN_BRACKET 0x1A
#define KEY_SQUARE_CLOSE_BRACKET 0x1B
#define KEY_SEMICOLON 0x27
#define KEY_BACKSLASH 0x2B
#define KEY_COMMA 0x33
#define KEY_DOT 0x34
#define KEY_FORESLASH 0x35
#define KEY_F1 0x3B
#define KEY_F2 0x3C
#define KEY_F3 0x3D
#define KEY_F4 0x3E
#define KEY_F5 0x3F
#define KEY_F6 0x40
#define KEY_F7 0x41
#define KEY_F8 0x42
#define KEY_F9 0x43
#define KEY_F10 0x44
#define KEY_F11 0x85
#define KEY_F12 0x86
#define KEY_BACKSPACE 0x0E
#define KEY_DELETE 0x53
#define KEY_DOWN 0x50
#define KEY_END 0x4F
#define KEY_ENTER 0x1C
#define KEY_ESC 0x01
#define KEY_HOME 0x47
#define KEY_INSERT 0x52
#define KEY_KEYPAD_5 0x4C
#define KEY_KEYPAD_MUL 0x37
#define KEY_KEYPAD_Minus 0x4A
#define KEY_KEYPAD_PLUS 0x4E
#define KEY_KEYPAD_DIV 0x35
#define KEY_LEFT 0x4B
#define KEY_PAGE_DOWN 0x51
#define KEY_PAGE_UP 0x49
#define KEY_PRINT_SCREEN 0x37
#define KEY_RIGHT 0x4D
#define KEY_SPACE 0x39
#define KEY_TAB 0x0F
#define KEY_UP 0x48
#define KEY_SHIFT 0x2A

//TODO: Update this

char to_ascii_char(uint8 key_code) {
  switch(key_code) {
    case KEY_A : return 'a';
    case KEY_B : return 'b';
    case KEY_C : return 'c';
    case KEY_D : return 'd';
    case KEY_E : return 'e';
    case KEY_F : return 'f';
    case KEY_G : return 'g';
    case KEY_H : return 'h';
    case KEY_I : return 'i';
    case KEY_J : return 'j';
    case KEY_K : return 'k';
    case KEY_L : return 'l';
    case KEY_M : return 'm';
    case KEY_N : return 'n';
    case KEY_O : return 'o';
    case KEY_P : return 'p';
    case KEY_Q : return 'q';
    case KEY_R : return 'r';
    case KEY_S : return 's';
    case KEY_T : return 't';
    case KEY_U : return 'u';
    case KEY_V : return 'v';
    case KEY_W : return 'w';
    case KEY_X : return 'x';
    case KEY_Y : return 'y';
    case KEY_Z : return 'z';
    case KEY_1 : return '1';
    case KEY_2 : return '2';
    case KEY_3 : return '3';
    case KEY_4 : return '4';
    case KEY_5 : return '5';
    case KEY_6 : return '6';
    case KEY_7 : return '7';
    case KEY_8 : return '8';
    case KEY_9 : return '9';
    case KEY_0 : return '0';
    case KEY_MINUS : return '-';
    case KEY_EQUAL : return '=';
    case KEY_SQUARE_OPEN_BRACKET : return '[';
    case KEY_SQUARE_CLOSE_BRACKET : return ']';
    case KEY_SEMICOLON : return ';';
    case KEY_BACKSLASH : return '\\';
    case KEY_COMMA : return ',';
    case KEY_DOT : return '.';
    case KEY_FORESLASH : return '/';
    case KEY_SPACE : return ' ';
    case KEY_BACKSPACE : return 1;
    default : return 0;
  }
}

#endif

int digit_ascii_codes[10] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};

uint8 inb(uint16 port) {
  uint8 ret;
  asm volatile("inb %1, %0" : "=a"(ret) : "d"(port));
  return ret;
}

void outb(uint16 port, uint8 data) {
  asm volatile("outb %0, %1" : "=a"(data) : "d"(port));
}

char get_input_keycode() {
  char ch = 0;
  while((ch = inb(KEYBOARD_PORT)) != 0){
    if(ch > 0)
      return ch;
  }
  return ch;
}

/*
*  Keep the cpu busy for doing nothing (no-op)
*  so that io port will not be processed by cpu
*  here timer can also be used, but lets do this in looping counter
*/

void sleep(uint32 timer_count) {
  while(1){
    asm volatile("nop");
    timer_count--;
    if(timer_count <= 0)
      break;
  }
}

/* TODO: Implement these properly
int get_cursor_position() {
  outb(REG_SCREEN_CTRL, 14);
  int position = inb(REG_SCREEN_DATA) << 8;

  outb(REG_SCREEN_CTRL, 15);
  position += inb(REG_SCREEN_DATA);

  return position * 2;
}

void update_cursor(int x, int y) {
	uint16 pos = y * VGA_WIDTH + x;
 
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8) ((pos >> 8) & 0xFF));
}
*/

// TODO: Update this to not use sleep and instead utilize a different system of key cooldown
char* input() {
  char ch = 0;
  int finished = 0;
  char keycode = 0;
  int upper = 0;
  char* in = "";

  do {

    keycode = get_input_keycode();

    if (keycode == KEY_ENTER) {
      finished = 1;
    }
    else {

      int key = to_ascii_char(keycode);

      // if the character isn't within our defined set then ignore it
      if (key == 0) {
        out_char(0x00);
        in[ch] = key;
        ch++;
      }

      else if (key == KEY_SHIFT) {
        upper = 1;
      }

      // If the key returns a 1 then it is a backspace, remove the previous character; make sure that we only remove characters that the user typed
      else if(key == 1 ) {
        if (ch > 0) {
          rmChar();
          in[ch] = 0;
          ch--;
        }
      }

      // If the key is a valid character then print it to the screen and add it to the input string
      else {
        if (upper == 1) {
          key = key - 32;
          upper = 0;
        }
        out_char(key);
        in[ch] = key;
        ch++;
      }
    }
    sleep(0x09FFFFFF);
  } while(finished < 1);

  in[0] = 0;
  return in;
}

char* inputI(char* info) {
  printT(info);
  char* in;
  in = input();
  newLn();
  return in;
}
