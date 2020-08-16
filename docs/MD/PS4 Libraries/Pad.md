# Pad library
The pad library is used for controller input to the Playstation 4. This includes operations such as opening a handle to a controller, reading the state, setting the light color, vibration settings, and other various actions.

### Known Macros
The state of buttons pressed after a poll is stored in an integer. Below is a set of macros defined in the header that map buttons to bits.

```c
#define ORBIS_PAD_BUTTON_L3           0x0002
#define ORBIS_PAD_BUTTON_R3           0x0004
#define ORBIS_PAD_BUTTON_OPTIONS      0x0008
#define ORBIS_PAD_BUTTON_UP           0x0010
#define ORBIS_PAD_BUTTON_RIGHT        0x0020
#define ORBIS_PAD_BUTTON_DOWN         0x0040
#define ORBIS_PAD_BUTTON_LEFT         0x0080

#define ORBIS_PAD_BUTTON_L2           0x0100
#define ORBIS_PAD_BUTTON_R2           0x0200
#define ORBIS_PAD_BUTTON_L1           0x0400
#define ORBIS_PAD_BUTTON_R1           0x0800

#define ORBIS_PAD_BUTTON_TRIANGLE     0x1000
#define ORBIS_PAD_BUTTON_CIRCLE       0x2000
#define ORBIS_PAD_BUTTON_CROSS        0x4000
#define ORBIS_PAD_BUTTON_SQUARE       0x8000

#define ORBIS_PAD_BUTTON_TOUCH_PAD    0x100000
```

It appears the only buttons on the controller not tracked through this state is the share button and the PS button. Presumably these buttons are special and can only be handled directly by internal processes such as Shellcore.

### Known Structures

#### OrbisPadTouch
This data structure contains data about one finger.

- **uint16_t x** - X position of the finger. (relative to the screen, not the touchpad)
- **uint16_t y** - Y position of the finger. (relative to the screen, not the touchpad)
- **uint8_t id** - Finger ID.
- **uint8_t reserved[3]** - N/A.

#### OrbisPadTouchData
This data structure contains data about all fingers currently touching the touchpad.

- **uint8_t length** - Amount of fingers.
- **uint8_t reserved[3]** - N/A
- **uint32_t unknown** - N/A
- **OrbisPadTouch data[ORBIS_PAD_MAX_TOUCH_NUM]** - Array containing finger data.

#### OrbisPadData
The pad data structure is what the Pad library gives you when you poll for controller state. This includes the button state mentioned earlier, analogue positional data for thumbsticks, the touchpad, and gyro, and other data.

- **unsigned int buttons**: Button state
- **stick leftStick**
  - **uint8_t x**: Left joystick X coordinate
  - **uint8_t y**: Left joystick Y coordinate
- **stick rightStick**
  - **uint8_t x**: Right joystick X coordinate
  - **uint8_t y**: Right joystick Y coordinate
- **analog analogButtons**
  - **uint8_t l2**: L2 trigger pressure
  - **uint8_t r2**: R2 trigger pressure
- **uint16_t padding**: N/A
- **vec_float4 orientation**: Gyroscope orientation as a quaternion
- **vec_float3 velocity**: Gyroscope velocity
- **vec_float3 acceleration**: Accelerometer reading
- **OrbisPadTouchData touch**: Touchpad data
- **uint8_t connected**: Whether the controller is on and connected or not
- **uint64_t timestamp**: Timestamp at time of poll
- **uint8_t ext[16]**: Extension unit data
- **uint8_t count**: Connection count
- **uint8_t unknown[15]**: N/A

#### OrbisPadColor
The pad color structure is passed to functions like `scePadSetLightBar()` to pass color information to the Pad library.

- **uint8_t r**: Red (0-255)
- **uint8_t g**: Green (0-255)
- **uint8_t b**: Blue (0-255)
- **uint8_t a**: Brightness (0-255)

#### OrbisPadVibeParam
The vibe param structure is passed to functions like `scePadSetVibration()` to pass vibration info to the Pad library.
- **uint8_t largeMotor**: Large motor value
- **uint8_t smallMotor**: Small motor value

### Known Functions
**scePadInit()**

```c
int scePadInit(void)
```

Initializes the pad library. Must be called before any other Pad library functions. Returns 0 on success, non-zero on failure.

**scePadOpen(userID, type, index, \*param)**

```c
int scePadOpen(int userID, int type, int index, void *param)
```

Opens a handle to the controller currently attached to `index` on the given `userID`. Returns a handle to pass to other library functions for interacting with that controller, negative value on failure.

**scePadClose(handle)**

```c
 int scePadClose(int handle)
```

Closes the handle to the controller passed to it. Returns 0 on success, non-zero on failure.

**scePadRead(handle, OrbisPadData \*outData, count)**

```c
int scePadRead(int handle, OrbisPadData *data, int count)
```

Polls for Pad data for the given `handle` and outputs it to `data`. Returns 0 on success, non-zero on failure.

**scePadReadState(handle, \*outState)**

```c
int scePadReadState(int handle, void *data)
```

Polls for Pad state data for the given `handle` and outputs it to `data`. Unlike `scePadReadState()`, it only reads the button state, not any of the analogue data. Returns 0 on success, non-zero on failure.

**scePadResetLightBar(handle)**

```c
int scePadResetLightBar(int handle)
```

Resets the light bar color for the given `handle`.

**scePadSetLightBar(handle, OrbisPadColor \*inColor)**

```c
int scePadSetLightBar(int handle, OrbisPadColor *inputColor);
```

Sets the light bar color for the given `handle`.

**scePadGetHandle(userID, controllerType, controllerIndex)**

```c
int scePadGetHandle(int userID, uint32_t controller_type, uint32_t controller_index);
```

Gets a handle using the given information. Not clear when this is invoked / should be used compared to opening with `scePadOpen()`.

**scePadResetOrientation(int handle)**

```c
int scePadResetOrientation(int handle);
```

Resets the gyroscope orientation for the given `handle`. Likely used for calibration.

**scePadSetVibration(int handle, OrbisPadVibeParam \*param)**

```c
int scePadSetVibration(int handle, const OrbisPadVibeParam *param);
```

Sets the vibration state on the given `handle`.

### Reversing Credits
- bigboss (psxdev)
- Specter