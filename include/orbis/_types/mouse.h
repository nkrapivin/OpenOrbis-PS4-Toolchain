#pragma once 

#include <stdint.h>

// sceMouseOpen modes.
#define ORBIS_MOUSE_OPEN_PARAM_NORMAL                 0x00
#define ORBIS_MOUSE_OPEN_PARAM_MERGED                 0x01

#define ORBIS_MOUSE_PORT_TYPE_MAIN                       0

// maximum amount of data you can request.
#define ORBIS_MOUSE_MAX_DATA_NUM                        64

// Mouse buttons.
#define ORBIS_MOUSE_BUTTON_LEFT                 0x00000001
#define ORBIS_MOUSE_BUTTON_RIGHT                0x00000002
#define ORBIS_MOUSE_BUTTON_WHEEL                0x00000004

// Additional buttons.
#define ORBIS_MOUSE_BUTTON_X1                   0x00000008
#define ORBIS_MOUSE_BUTTON_X2                   0x00000010

// IME, UI dialogs, etc...
#define ORBIS_MOUSE_BUTTON_INTERCEPTED          0x80000000

typedef struct OrbisMouseOpenParam {
    uint8_t behavior; // ORBIS_MOUSE_OPEN_PARAM_*
    uint8_t reserved[7];
} OrbisMouseOpenParam;

typedef struct OrbisMouseData {
    uint64_t timestamp;
    bool     connected;
    uint32_t buttons;
    int32_t  xAxis;
    int32_t  yAxis;
    int32_t  wheel;
    int32_t  tilt;
    uint8_t  reserved[8];
} OrbisMouseData;
