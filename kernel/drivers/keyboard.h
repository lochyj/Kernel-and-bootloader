#pragma once

#include "keyboard.c"

#ifndef KEYBOARD_H
#define KEYBOARD_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

#define KEYBOARD_PORT 0x60

// Common letters

#define INPUT_A 0x1E
#define INPUT_B 0x30
#define INPUT_C 0x2E
#define INPUT_D 0x20
#define INPUT_E 0x12
#define INPUT_F 0x21
#define INPUT_G 0x22
#define INPUT_H 0x23
#define INPUT_I 0x17
#define INPUT_J 0x24
#define INPUT_K 0x25
#define INPUT_L 0x26
#define INPUT_M 0x32
#define INPUT_N 0x31
#define INPUT_O 0x18
#define INPUT_P 0x19
#define INPUT_Q 0x10
#define INPUT_R 0x13
#define INPUT_S 0x1F
#define INPUT_T 0x14
#define INPUT_U 0x16
#define INPUT_V 0x2F
#define INPUT_W 0x11
#define INPUT_X 0x2D
#define INPUT_Y 0x15
#define INPUT_Z 0x2C
#define INPUT_1 0x02
#define INPUT_2 0x03
#define INPUT_3 0x04
#define INPUT_4 0x05
#define INPUT_5 0x06
#define INPUT_6 0x07
#define INPUT_7 0x08
#define INPUT_8 0x09
#define INPUT_9 0x0A
#define INPUT_0 0x0B

// Special letters

#define INPUT_MINUS 0x0C
#define INPUT_EQUAL 0x0D
#define INPUT_SQUARE_OPEN_BRACKET 0x1A
#define INPUT_SQUARE_CLOSE_BRACKET 0x1B
#define INPUT_SEMICOLON 0x27
#define INPUT_BACKSLASH 0x2B
#define INPUT_COMMA 0x33
#define INPUT_DOT 0x34
#define INPUT_FORESLASH 0x35
#define INPUT_BACKSPACE 0x0E
#define INPUT_DELETE 0x53
#define INPUT_DOWN 0x50
#define INPUT_END 0x4F
#define INPUT_ENTER 0x1C
#define INPUT_ESC 0x01
#define INPUT_HOME 0x47
#define INPUT_INSERT 0x52
#define INPUT_KEYPAD_5 0x4C
#define INPUT_KEYPAD_MUL 0x37
#define INPUT_KEYPAD_Minus 0x4A
#define INPUT_KEYPAD_PLUS 0x4E
#define INPUT_KEYPAD_DIV 0x35
#define INPUT_LEFT 0x4B
#define INPUT_PAGE_DOWN 0x51
#define INPUT_PAGE_UP 0x49
#define INPUT_PRINT_SCREEN 0x37
#define INPUT_RIGHT 0x4D
#define INPUT_SPACE 0x39
#define INPUT_TAB 0x0F
#define INPUT_UP 0x48

// Function keys

#define INPUT_F1 0x3B
#define INPUT_F2 0x3C
#define INPUT_F3 0x3D
#define INPUT_F4 0x3E
#define INPUT_F5 0x3F
#define INPUT_F6 0x40
#define INPUT_F7 0x41
#define INPUT_F8 0x42
#define INPUT_F9 0x43
#define INPUT_F10 0x44
#define INPUT_F11 0x85
#define INPUT_F12 0x86

#endif

char get_ascii_char(uint8 key_code) {
  switch(key_code) {

    // Special letters

    case INPUT_MINUS : return '-';
    case INPUT_EQUAL : return '=';
    case INPUT_SQUARE_OPEN_BRACKET : return '[';
    case INPUT_SQUARE_CLOSE_BRACKET : return ']';
    case INPUT_SEMICOLON : return ';';
    case INPUT_BACKSLASH : return '\\';
    case INPUT_COMMA : return ',';
    case INPUT_DOT : return '.';
    case INPUT_SLASH : return '/';
    case INPUT_SPACE : return ' ';

    // Common letters

    case INPUT_A : return 'A';
    case INPUT_B : return 'B';
    case INPUT_C : return 'C';
    case INPUT_D : return 'D';
    case INPUT_E : return 'E';
    case INPUT_F : return 'F';
    case INPUT_G : return 'G';
    case INPUT_H : return 'H';
    case INPUT_I : return 'I';
    case INPUT_J : return 'J';
    case INPUT_K : return 'K';
    case INPUT_L : return 'L';
    case INPUT_M : return 'M';
    case INPUT_N : return 'N';
    case INPUT_O : return 'O';
    case INPUT_P : return 'P';
    case INPUT_Q : return 'Q';
    case INPUT_R : return 'R';
    case INPUT_S : return 'S';
    case INPUT_T : return 'T';
    case INPUT_U : return 'U';
    case INPUT_V : return 'V';
    case INPUT_W : return 'W';
    case INPUT_X : return 'X';
    case INPUT_Y : return 'Y';
    case INPUT_Z : return 'Z';
    case INPUT_1 : return '1';
    case INPUT_2 : return '2';
    case INPUT_3 : return '3';
    case INPUT_4 : return '4';
    case INPUT_5 : return '5';
    case INPUT_6 : return '6';
    case INPUT_7 : return '7';
    case INPUT_8 : return '8';
    case INPUT_9 : return '9';
    case INPUT_0 : return '0';

    // Special keys

    case INPUT_BACKSPACE : return '1';

    // Default return for unknown or unspecified key codes

    default : return 0;
  }
}