#include "../output/ports.h"
#include "../input/cpu.h"
#include "../../include/types.h"


// TODO: Update this to not use sleep and instead utilize a different system of key cooldown
char* input() {
  char ch = 0;
  int finished = 0;
  char keycode = 0;
  int upper = 0;
  char* in = "";

  do {

    keycode = get_input();

    if (keycode == KEY_ENTER) {
      finished = 1;
    }
    else {

      int key = to_ascii_char(keycode);

      // If the character isn't within our defined set then ignore it
      if (key == 0) {
        outChar(0x00);
        in[ch] = key;
        ch++;
      }

      // If the shift key was pressed then we need to set the upper flag
      else if (key == KEY_SHIFT) {
        upper = 1;
      }

      // If the key returns a 1 then it is a backspace, remove the previous character; make sure that we only remove characters that the user typed
      else if(key == 1 ) {
        if (ch > 0) {
          rmChar();
          ch--;
        }
      }

      // If the key is a valid character then print it to the screen and add it to the input string
      else {
        if (upper == 1) {
          key = key - 32;
          upper = 0;
        }
        outChar(key);
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
  print(info);
  char* in = "";
  in = input();
  print("\n");
  return in;
}