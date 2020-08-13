# Mouse

The mouse library is used for mouse input on PlayStation 4. This includes operations such as mouse button presses, X and Y axis of the mouse, wheel click, "Back" and "Forward" (also called X1 and X2 buttons), and even horizontal wheel which is present on some mouse models.

## Known Macros

The state of buttons pressed after a poll is stored in an integer. Below is a set of macros defined in the header that map buttons to bits.

```c
#define ORBIS_MOUSE_BUTTON_LEFT                 0x00000001
#define ORBIS_MOUSE_BUTTON_RIGHT                0x00000002
#define ORBIS_MOUSE_BUTTON_WHEEL                0x00000004
#define ORBIS_MOUSE_BUTTON_X1                   0x00000008
#define ORBIS_MOUSE_BUTTON_X2                   0x00000010
#define ORBIS_MOUSE_BUTTON_INTERCEPTED          0x80000000
```

There are also additional macroses used to define mouse parameters and type
```c
#define ORBIS_MOUSE_OPEN_PARAM_NORMAL                 0x00
#define ORBIS_MOUSE_OPEN_PARAM_MERGED                 0x01
#define ORBIS_MOUSE_PORT_TYPE_MAIN                       0
#define ORBIS_MOUSE_MAX_DATA_NUM                        64
```

`ORBIS_MOUSE_BUTTON_INTERCEPTED` "button" is used to tell if the mouse is being used by the system right now, for example an IME dialog, or quick menu, or any UI dialog that supports mouse.

Ideally you should ignore mouse any input if `ORBIS_MOUSE_BUTTON_INTERCEPTED` is "pressed".

## Known Structures

### OrbisMouseData

This structure is used to represent the current state of the mouse. This includes buttons, axes, and wheel.

- **uint64_t timestamp**: Timestamp of the data. (this will make sense in a minute)
- **bool connected**: If the mouse is connected or not.
- **uint32_t buttons**: State of the buttons.
- **int32_t xAxis**: Relative X axis coord.
- **int32_t yAxis**: Relative Y axis coord.
- **int32_t wheel**: Wheel movement integer.
- **int32_t tilt**: Horizontal wheel tilt. (present on some mice models)
- **uint8_t reserved[8]**: N/A

### OrbisMouseOpenParam

This structure is passed to `sceMouseOpen` to set the mouse parameters.

- **uint8_t behavior**: `ORBIS_MOUSE_OPEN_PARAM_NORMAL` or `ORBIS_MOUSE_OPEN_PARAM_MERGED`. If a user connects two mice to their console then you should use Merged mode.
- **uint8_t reserved[7]**: N/A (most likely padding?)

## Known Functions

**sceMouseInit()**

```c
int sceMouseInit();
```

Initializes the Mouse library. Must be called before any other Mouse functions. Returns `ORBIS_OK` on success, anything else on failure.

**sceMouseOpen(userID, type, index, param)**

```c
int sceMouseOpen(int32_t userID, int32_t type, int32_t index, const OrbisMouseOpenParam *param);
```

Opens a handle to the Mouse `type` (`ORBIS_MOUSE_PORT_TYPE_MAIN`) attached to `index` on the given `userID` with parameters `param`.

Returns a handle to the mouse, or less-than-zero on failure.

**sceMouseRead(handle, data, num)**

```c
int sceMouseRead(int32_t handle, OrbisMouseData *data, int32_t num);
```

Reads `num` input states (maximum up to `ORBIS_MOUSE_MAX_DATA_NUM`) from Mouse `handle` and stores them in the buffer `data`.

Returns the actual acquired number of input states on success, `0` when there's no new data, less-than-zero on failure.

**sceMouseClose(handle)**

```c
int sceMouseClose(int32_t handle);
```

Closes a handle to the mouse. Returns `ORBIS_OK` on success, anything else on failure.
