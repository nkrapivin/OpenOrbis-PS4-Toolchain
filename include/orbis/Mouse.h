#ifndef _SCE_MOUSE_H_
#define _SCE_MOUSE_H_

#include <stdint.h>
#include <orbis/_types/errors.h>
#include <orbis/_types/mouse.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Close a mouse handle.
int sceMouseClose(int32_t handle);
// Initialize Mouse library.
int sceMouseInit();
// Open a handle to the mouse device.
int sceMouseOpen(int32_t userID, int32_t type, int32_t index, const OrbisMouseOpenParam *param);
// Read history of mouse input.
int sceMouseRead(int32_t handle, OrbisMouseData *data, int32_t num);

#endif

#ifdef __cplusplus
}
#endif
