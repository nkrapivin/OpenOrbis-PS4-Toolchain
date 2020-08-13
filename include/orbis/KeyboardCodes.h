#ifndef _SCE_KEYBOARD_CODE_H_
#define _SCE_KEYBOARD_CODE_H_

#define ORBIS_KEYBOARD_MKEY_L_CTRL  (1U<<0)
#define ORBIS_KEYBOARD_MKEY_L_SHIFT (1U<<1)
#define ORBIS_KEYBOARD_MKEY_L_ALT   (1U<<2)
#define ORBIS_KEYBOARD_MKEY_L_WIN   (1U<<3)
#define ORBIS_KEYBOARD_MKEY_R_CTRL  (1U<<4)
#define ORBIS_KEYBOARD_MKEY_R_SHIFT (1U<<5)
#define ORBIS_KEYBOARD_MKEY_R_ALT   (1U<<6)
#define ORBIS_KEYBOARD_MKEY_R_WIN   (1U<<7)

#define ORBIS_KEYBOARD_LED_NUM_LOCK    (1U<<0)
#define ORBIS_KEYBOARD_LED_CAPS_LOCK   (1U<<1)
#define ORBIS_KEYBOARD_LED_SCROLL_LOCK (1U<<2)

#define ORBIS_KEYBOARD_CODE_NO_KEYS 0x00
#define ORBIS_KEYBOARD_CODE_E_ROLLOVER 0x01
#define ORBIS_KEYBOARD_CODE_E_POSTFAIL 0x02
#define ORBIS_KEYBOARD_CODE_E_UNDEF 0x03
#define ORBIS_KEYBOARD_CODE_ESCAPE 0x29
#define ORBIS_KEYBOARD_CODE_106_KANJI 0x35
#define ORBIS_KEYBOARD_CODE_CAPS_LOCK 0x39
#define ORBIS_KEYBOARD_CODE_F1 0x3A
#define ORBIS_KEYBOARD_CODE_F2 0x3B
#define ORBIS_KEYBOARD_CODE_F3 0x3C
#define ORBIS_KEYBOARD_CODE_F4 0x3D
#define ORBIS_KEYBOARD_CODE_F5 0x3E
#define ORBIS_KEYBOARD_CODE_F6 0x3F
#define ORBIS_KEYBOARD_CODE_F7 0x40
#define ORBIS_KEYBOARD_CODE_F8 0x41
#define ORBIS_KEYBOARD_CODE_F9 0x42
#define ORBIS_KEYBOARD_CODE_F10 0x43
#define ORBIS_KEYBOARD_CODE_F11 0x44
#define ORBIS_KEYBOARD_CODE_F12 0x45
#define ORBIS_KEYBOARD_CODE_PRINTSCREEN 0x46
#define ORBIS_KEYBOARD_CODE_SCROLL_LOCK 0x47
#define ORBIS_KEYBOARD_CODE_PAUSE 0x48
#define ORBIS_KEYBOARD_CODE_INSERT 0x49
#define ORBIS_KEYBOARD_CODE_HOME 0x4A
#define ORBIS_KEYBOARD_CODE_PAGE_UP 0x4b
#define ORBIS_KEYBOARD_CODE_DELETE 0x4C
#define ORBIS_KEYBOARD_CODE_END 0x4D
#define ORBIS_KEYBOARD_CODE_PAGE_DOWN 0x4E
#define ORBIS_KEYBOARD_CODE_RIGHT_ARROW 0x4F
#define ORBIS_KEYBOARD_CODE_LEFT_ARROW 0x50
#define ORBIS_KEYBOARD_CODE_DOWN_ARROW 0x51
#define ORBIS_KEYBOARD_CODE_UP_ARROW 0x52
#define ORBIS_KEYBOARD_CODE_NUM_LOCK 0x53
#define ORBIS_KEYBOARD_CODE_APPLICATION 0x65
#define ORBIS_KEYBOARD_CODE_KANA 0x88
#define ORBIS_KEYBOARD_CODE_HENKAN 0x8A
#define ORBIS_KEYBOARD_CODE_MUHENKAN 0x8B
#define ORBIS_KEYBOARD_CODE_A 0x04
#define ORBIS_KEYBOARD_CODE_B 0x05
#define ORBIS_KEYBOARD_CODE_C 0x06
#define ORBIS_KEYBOARD_CODE_D 0x07
#define ORBIS_KEYBOARD_CODE_E 0x08
#define ORBIS_KEYBOARD_CODE_F 0x09
#define ORBIS_KEYBOARD_CODE_G 0x0A
#define ORBIS_KEYBOARD_CODE_H 0x0B
#define ORBIS_KEYBOARD_CODE_I 0x0C
#define ORBIS_KEYBOARD_CODE_J 0x0D
#define ORBIS_KEYBOARD_CODE_K 0x0E
#define ORBIS_KEYBOARD_CODE_L 0x0F
#define ORBIS_KEYBOARD_CODE_M 0x10
#define ORBIS_KEYBOARD_CODE_N 0x11
#define ORBIS_KEYBOARD_CODE_O 0x12
#define ORBIS_KEYBOARD_CODE_P 0x13
#define ORBIS_KEYBOARD_CODE_Q 0x14
#define ORBIS_KEYBOARD_CODE_R 0x15
#define ORBIS_KEYBOARD_CODE_S 0x16
#define ORBIS_KEYBOARD_CODE_T 0x17
#define ORBIS_KEYBOARD_CODE_U 0x18
#define ORBIS_KEYBOARD_CODE_V 0x19
#define ORBIS_KEYBOARD_CODE_W 0x1A
#define ORBIS_KEYBOARD_CODE_X 0x1B
#define ORBIS_KEYBOARD_CODE_Y 0x1C
#define ORBIS_KEYBOARD_CODE_Z 0x1D
#define ORBIS_KEYBOARD_CODE_1 0x1E
#define ORBIS_KEYBOARD_CODE_2 0x1F
#define ORBIS_KEYBOARD_CODE_3 0x20
#define ORBIS_KEYBOARD_CODE_4 0x21
#define ORBIS_KEYBOARD_CODE_5 0x22
#define ORBIS_KEYBOARD_CODE_6 0x23
#define ORBIS_KEYBOARD_CODE_7 0x24
#define ORBIS_KEYBOARD_CODE_8 0x25
#define ORBIS_KEYBOARD_CODE_9 0x26
#define ORBIS_KEYBOARD_CODE_0 0x27
#define ORBIS_KEYBOARD_CODE_ENTER 0x28
#define ORBIS_KEYBOARD_CODE_ESC 0x29
#define ORBIS_KEYBOARD_CODE_BS 0x2A
#define ORBIS_KEYBOARD_CODE_TAB 0x2B
#define ORBIS_KEYBOARD_CODE_SPACE 0x2C
#define ORBIS_KEYBOARD_CODE_MINUS 0x2D
#define ORBIS_KEYBOARD_CODE_EQUAL_101 0x2E
#define ORBIS_KEYBOARD_CODE_ACCENT_CIRCONFLEX_106 0x2E
#define ORBIS_KEYBOARD_CODE_LEFT_BRACKET_101 0x2F
#define ORBIS_KEYBOARD_CODE_ATMARK_106 0x2F
#define ORBIS_KEYBOARD_CODE_RIGHT_BRACKET_101 0x30
#define ORBIS_KEYBOARD_CODE_LEFT_BRACKET_106 0x30
#define ORBIS_KEYBOARD_CODE_BACKSLASH_101 0x31
#define ORBIS_KEYBOARD_CODE_RIGHT_BRACKET_106 0x32
#define ORBIS_KEYBOARD_CODE_SEMICOLON 0x33
#define ORBIS_KEYBOARD_CODE_QUOTATION_101 0x34
#define ORBIS_KEYBOARD_CODE_COLON_106 0x34
#define ORBIS_KEYBOARD_CODE_COMMA 0x36
#define ORBIS_KEYBOARD_CODE_PERIOD 0x37
#define ORBIS_KEYBOARD_CODE_SLASH 0x38
#define ORBIS_KEYBOARD_CODE_CAPS_LOCK 0x39
#define ORBIS_KEYBOARD_CODE_KPAD_NUMLOCK 0x53
#define ORBIS_KEYBOARD_CODE_KPAD_SLASH 0x54
#define ORBIS_KEYBOARD_CODE_KPAD_ASTERISK 0x55
#define ORBIS_KEYBOARD_CODE_KPAD_MINUS 0x56
#define ORBIS_KEYBOARD_CODE_KPAD_PLUS 0x57
#define ORBIS_KEYBOARD_CODE_KPAD_ENTER 0x58
#define ORBIS_KEYBOARD_CODE_KPAD_1 0x59
#define ORBIS_KEYBOARD_CODE_KPAD_2 0x5A
#define ORBIS_KEYBOARD_CODE_KPAD_3 0x5B
#define ORBIS_KEYBOARD_CODE_KPAD_4 0x5C
#define ORBIS_KEYBOARD_CODE_KPAD_5 0x5D
#define ORBIS_KEYBOARD_CODE_KPAD_6 0x5E
#define ORBIS_KEYBOARD_CODE_KPAD_7 0x5F
#define ORBIS_KEYBOARD_CODE_KPAD_8 0x60
#define ORBIS_KEYBOARD_CODE_KPAD_9 0x61
#define ORBIS_KEYBOARD_CODE_KPAD_0 0x62
#define ORBIS_KEYBOARD_CODE_KPAD_PERIOD 0x63
#define ORBIS_KEYBOARD_CODE_BACKSLASH_106 0x87
#define ORBIS_KEYBOARD_CODE_YEN_106 0x89

#endif