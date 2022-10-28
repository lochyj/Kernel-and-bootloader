#include "keyboard.h"

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

void sleep(uint32 timer_count) {
  while(1){
    asm volatile("nop");
    timer_count--;
    if(timer_count <= 0)
      break;
  }
}

// TODO: Get the users input and return it as a string

char* input() {
  char* userInput = "";
  char keycode = 0;
  char numChar = 0;
  
  do {
    keycode = get_input_keycode();
    if (keycode == KEY_ENTER) {
      return userInput;
    } else {
      int key = get_ascii_char(keycode);
      if (key == 0) {
        out_char('~');
        numChar++;
      } else if(key == '1') {
        rmChar();
        numChar--;
      } else {
        out_char(key);
        userInput[numChar] = key;
        numChar++;
      }
    }
    if (numChar == 0) {
      return userInput;
    }
    sleep(0x04FFFFFF);
  } while(numChar > 0);
}
