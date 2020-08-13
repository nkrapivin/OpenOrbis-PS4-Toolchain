#pragma once 

#include <stdint.h>

// Keyboard defines.
#define ORBIS_KEYBOARD_PORT_TYPE_MAIN     0
#define ORBIS_KEYBOARD_MAX_KEYCODES      16
#define ORBIS_KEYBOARD_MAX_DATA_NUM      16

typedef enum OrbisKeyboardMapType {
    ORBIS_KEYBOARD_MAPPING_101 = 0,
    ORBIS_KEYBOARD_MAPPING_106 = 1
} OrbisKeyboardMapType;

typedef struct OrbisKeyboardData {
    uint64_t timestamp;
    uint8_t  reserved[8];
    bool     isConnected;
    int32_t  pressedKeysLen;
    uint32_t led;
    uint32_t modifierKeys;
    uint16_t keyCode[ORBIS_KEYBOARD_MAX_KEYCODES];
    uint8_t  reserved2[32];
} OrbisKeyboardData;

typedef struct OrbisKeyboardCharData {
    bool     coversionOk;
    int32_t  length;
    uint16_t unicodeChar;
    uint8_t  reserved[8];
} OrbisKeyboardCharData;