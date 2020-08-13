#ifndef _SCE_KEYBOARD_H_
#define _SCE_KEYBOARD_H_

#include <stdint.h>
#include <orbis/_types/keyboard.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Close keyboard handle.
int sceKeyboardClose(int32_t handle);
// Initialize library.
int sceKeyboardInit();
// Open a handle to the keyboard.
int sceKeyboardOpen(int32_t userID, int32_t type, int32_t index, void *param);
// Read keyboard input history. (up to ORBIS_KEYBOARD_MAX_DATA_NUM)
int sceKeyboardRead(int32_t handle, OrbisKeyboardData *data, int32_t num);
// Read current keyboard state.
int sceKeyboardReadState(int32_t handle, OrbisKeyboardData *data);
// Convert keycode to raw unicode char.
int sceKeyboardGetKey2Char(int32_t handle, OrbisKeyboardMapType mapping, uint32_t led, uint32_t modifier, uint16_t keyCode, OrbisKeyboardCharData *data);

#endif

#ifdef __cplusplus
}
#endif
