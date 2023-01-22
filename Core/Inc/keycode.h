#ifndef __KEYCODE_H
#define __KEYCODE_H

#ifdef __cplusplus
extern "C" {
#endif
class Keycode:
    
    /* 
    USB HID Keycode constants.
    
    This list is modeled after the names for USB keycodes defined in
    https://usb.org/sites/default/files/hut1_21_0.pdf#page=83.
    This list does not include every single code, but does include all the keys on
    a regular PC or Mac keyboard.
    Remember that keycodes are the names for key *positions* on a US keyboard, and may
    not correspond to the character that you mean to send if you want to emulate non-US keyboard.
    For instance, on a French keyboard (AZERTY instead of QWERTY),
    the keycode for 'q' is used to indicate an 'a'. Likewise, 'y' represents 'z' on
    a German keyboard. This is historical: the idea was that the keycaps could be changed
    without changing the keycodes sent, so that different firmware was not needed for
    different variations of a keyboard.
    */

    #define KEY_A 0x04
    /* a  and  A */
    #define KEY_B 0x05
    /* b  and  B */
    #define KEY_C 0x06
    /* c  and  C */
    #define KEY_D 0x07
    /* d  and  D */
    #define KEY_E 0x08
    /* e  and  E */
    #define KEY_F 0x09
    /* f  and  F */
    #define KEY_G 0x0A
    /* g  and  G */
    #define KEY_H 0x0B
    /* h  and  H */
    #define KEY_I 0x0C
    /* i  and  I */
    #define KEY_J 0x0D
    /* j  and  J */
    #define KEY_K 0x0E
    /* k  and  K */
    #define KEY_L 0x0F
    /* l  and  L */
    #define KEY_M 0x10
    /* m  and  M */
    #define KEY_N 0x11
    /* n  and  N */
    #define KEY_O 0x12
    /* o  and  O */
    #define KEY_P 0x13
    /* p  and  P */
    #define KEY_Q 0x14
    /* q  and  Q */
    #define KEY_R 0x15
    /* r  and  R */
    #define KEY_S 0x16
    /* s  and  S */
    #define KEY_T 0x17
    /* t  and  T */
    #define KEY_U 0x18
    /* u  and  U */
    #define KEY_V 0x19
    /* v  and  V */
    #define KEY_W 0x1A
    /* w  and  W */
    #define KEY_X 0x1B
    /* x  and  X */
    #define KEY_Y 0x1C
    /* y  and  Y */
    #define KEY_Z 0x1D
    /* z  and  Z */
    #define KEY_ONE 0x1E
    /* 1  and  ! */
    #define KEY_TWO 0x1F
    /* 2  and  @ */
    #define KEY_THREE 0x20
    /* 3  and  # */
    #define KEY_FOUR 0x21
    /* 4  and  $ */
    #define KEY_FIVE 0x22
    /* 5  and  % */
    #define KEY_SIX 0x23
    /* 6  and  ^ */
    #define KEY_SEVEN 0x24
    /* 7  and  & */
    #define KEY_EIGHT 0x25
    /* 8  and  * */
    #define KEY_NINE 0x26
    /* 9  and  ( */
    #define KEY_ZERO 0x27
    /* 0  and  ) */
    #define KEY_ENTER 0x28
    /* Enter (Return) */
    #define KEY_RETURN ENTER
    /* Alias for  ENTER */
    #define KEY_ESCAPE 0x29
    /* Escape */
    #define KEY_BACKSPACE 0x2A
    /* Delete backward (Backspace) */
    #define KEY_TAB 0x2B
    /* Tab and Backtab */
    #define KEY_SPACEBAR 0x2C
    /* Spacebar */
    #define KEY_SPACE SPACEBAR
    /* Alias for SPACEBAR */
    #define KEY_MINUS 0x2D
    /* -` and  _ */
    #define KEY_EQUALS 0x2E
    /* =` and  + */
    #define KEY_LEFT_BRACKET 0x2F
    /* [  and  { */
    #define KEY_RIGHT_BRACKET 0x30
    /* ]  and  } */
    #define KEY_BACKSLASH 0x31
    r/* \  and  | */
    #define KEY_POUND 0x32
    /* #  and  ~  (Non-US keyboard) */
    #define KEY_SEMICOLON 0x33
    /* ;  and  : */
    #define KEY_QUOTE 0x34
    /* '  and  " */
    #define KEY_GRAVE_ACCENT 0x35
    /* r""":literal:`\  and  ~ */
    #define KEY_COMMA 0x36
    /* ,  and  < */
    #define KEY_PERIOD 0x37
    /* .  and  > */
    #define KEY_FORWARD_SLASH 0x38
    /* /  and  ? */
    #define KEY_CAPS_LOCK 0x39
    /* Caps Lock */
    #define KEY_F1 0x3A
    /* Function key F1 */
    #define KEY_F2 0x3B
    /* Function key F2 */
    #define KEY_F3 0x3C
    /* Function key F3 */
    #define KEY_F4 0x3D
    /* Function key F4 */
    #define KEY_F5 0x3E
    /* Function key F5 */
    #define KEY_F6 0x3F
    /* Function key F6 */
    #define KEY_F7 0x40
    /* Function key F7 */
    #define KEY_F8 0x41
    /* Function key F8 */
    #define KEY_F9 0x42
    /* Function key F9 */
    #define KEY_F10 0x43
    /* Function key F10 */
    #define KEY_F11 0x44
    /* Function key F11 */
    #define KEY_F12 0x45
    /* Function key F12 */

    #define KEY_PRINT_SCREEN 0x46
    /* Print Screen (SysRq) */
    #define KEY_SCROLL_LOCK 0x47
    /* Scroll Lock */
    #define KEY_PAUSE 0x48
    /* Pause (Break) */

    #define KEY_INSERT 0x49
    /* Insert */
    #define KEY_HOME 0x4A
    /* Home (often moves to beginning of line) */
    #define KEY_PAGE_UP 0x4B
    /* Go back one page */
    #define KEY_DELETE 0x4C
    /* Delete forward */
    #define KEY_END 0x4D
    /* End (often moves to end of line) */
    #define KEY_PAGE_DOWN 0x4E
    /* Go forward one page */

    #define KEY_RIGHT_ARROW 0x4F
    /* Move the cursor right */
    #define KEY_LEFT_ARROW 0x50
    /* Move the cursor left */
    #define KEY_DOWN_ARROW 0x51
    /* Move the cursor down */
    #define KEY_UP_ARROW 0x52
    /* Move the cursor up */

    #define KEY_KEYPAD_NUMLOCK 0x53
    /* Num Lock (Clear on Mac) */
    #define KEY_KEYPAD_FORWARD_SLASH 0x54
    /* Keypad  / */
    #define KEY_KEYPAD_ASTERISK 0x55
    /* Keypad  * */
    #define KEY_KEYPAD_MINUS 0x56
    /* Keyapd  - */
    #define KEY_KEYPAD_PLUS 0x57
    /* Keypad  + */
    #define KEY_KEYPAD_ENTER 0x58
    /* Keypad Enter */
    #define KEY_KEYPAD_ONE 0x59
    /* Keypad  1  and End */
    #define KEY_KEYPAD_TWO 0x5A
    /* Keypad  2  and Down Arrow */
    #define KEY_KEYPAD_THREE 0x5B
    /* Keypad  3  and PgDn */
    #define KEY_KEYPAD_FOUR 0x5C
    /* Keypad  4  and Left Arrow */
    #define KEY_KEYPAD_FIVE 0x5D
    /* Keypad  5 */
    #define KEY_KEYPAD_SIX 0x5E
    /* Keypad  6  and Right Arrow */
    #define KEY_KEYPAD_SEVEN 0x5F
    /* Keypad  7  and Home */
    #define KEY_KEYPAD_EIGHT 0x60
    /* Keypad  8  and Up Arrow */
    #define KEY_KEYPAD_NINE 0x61
    /* Keypad  9  and PgUp */
    #define KEY_KEYPAD_ZERO 0x62
    /* Keypad  0  and Ins */
    #define KEY_KEYPAD_PERIOD 0x63
    /* Keypad  .  and Del */
    #define KEY_KEYPAD_BACKSLASH 0x64
    /* Keypad  \\  and  |  (Non-US) */

    #define KEY_APPLICATION 0x65
    /* Application: also known as the Menu key (Windows) */
    #define KEY_POWER 0x66
    /* Power (Mac) */
    #define KEY_KEYPAD_EQUALS 0x67
    /* Keypad  =  (Mac) */
    #define KEY_F13 0x68
    /* Function key F13 (Mac) */
    #define KEY_F14 0x69
    /* Function key F14 (Mac) */
    #define KEY_F15 0x6A
    /* Function key F15 (Mac) */
    #define KEY_F16 0x6B
    /* Function key F16 (Mac) */
    #define KEY_F17 0x6C
    /* Function key F17 (Mac) */
    #define KEY_F18 0x6D
    /* Function key F18 (Mac) */
    #define KEY_F19 0x6E
    /* Function key F19 (Mac) */

    #define KEY_F20 0x6F
    /* Function key F20 */
    #define KEY_F21 0x70
    /* Function key F21 */
    #define KEY_F22 0x71
    /* Function key F22 */
    #define KEY_F23 0x72
    /* Function key F23 */
    #define KEY_F24 0x73
    /* Function key F24 */

    #define KEY_LEFT_CONTROL 0xE0
    /* Control modifier left of the spacebar */
    #define KEY_CONTROL LEFT_CONTROL
    /* Alias for LEFT_CONTROL */
    #define KEY_LEFT_SHIFT 0xE1
    /* Shift modifier left of the spacebar */
    #define KEY_SHIFT LEFT_SHIFT
    /* Alias for LEFT_SHIFT */
    #define KEY_LEFT_ALT 0xE2
    /* Alt modifier left of the spacebar */
    #define KEY_ALT LEFT_ALT
    /* Alias for LEFT_ALT; Alt is also known as Option (Mac) */
    #define KEY_OPTION ALT
    /* Labeled as Option on some Mac keyboards */
    #define KEY_LEFT_GUI 0xE3
    /* GUI modifier left of the spacebar */
    #define KEY_GUI LEFT_GUI
    /* Alias for LEFT_GUI; GUI is also known as the Windows key, Command (Mac), or Meta */
    #define KEY_WINDOWS GUI
    /* Labeled with a Windows logo on Windows keyboards */
    #define KEY_COMMAND GUI
    /* Labeled as Command on Mac keyboards, with a clover glyph */
    #define KEY_RIGHT_CONTROL 0xE4
    /* Control modifier right of the spacebar */
    #define KEY_RIGHT_SHIFT 0xE5
    /* Shift modifier right of the spacebar */
    #define KEY_RIGHT_ALT 0xE6
    /* Alt modifier right of the spacebar */
    #define KEY_RIGHT_GUI 0xE7
    /* GUI modifier right of the spacebar */


#ifdef __cplusplus
}
#endif

#endif

