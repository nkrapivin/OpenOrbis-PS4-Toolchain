#include <orbis/Sysmodule.h>
#include <orbis/Sysmodules.h>
#include <orbis/UserService.h>
#include <orbis/_types/errors.h>
#include "keyboard.h"
#include "../../_common/log.h"

Keyboard::~Keyboard()
{
    DEBUGLOG << "[KEYBOARD] Freeing...";
    sceKeyboardClose(this->handle);
    sceSysmoduleUnloadModule(ORBIS_SYSMODULE_KEYBOARD);
}

bool Keyboard::Init(int kbdUserID, int index, OrbisKeyboardMapType mapping)
{
    // Load libSceKeyboard sysmodule.
    int rc = sceSysmoduleLoadModule(ORBIS_SYSMODULE_KEYBOARD);

    if (rc < 0)
    {
        DEBUGLOG << "[KEYBOARD] Cannot load sceKeyboard.";
        return false;
    }

    // Initialize keyboard library.
    if (sceKeyboardInit() != ORBIS_OK)
    {
        DEBUGLOG << "[KEYBOARD] Couldn't initialize library!";
        return false;
    }

    if (kbdUserID < 0)
    {
        OrbisUserServiceInitializeParams param;
        param.priority = ORBIS_KERNEL_PRIO_FIFO_LOWEST;
        sceUserServiceInitialize(&param);
        sceUserServiceGetInitialUser(&this->userID);
    }
    else
    {
        this->userID = kbdUserID;
    }

    // Open a handle for the keyboard.
    this->handle = sceKeyboardOpen(this->userID, ORBIS_KEYBOARD_PORT_TYPE_MAIN, index, NULL);
    // last arg is always NULL???

    if (this->handle < 0)
    {
        DEBUGLOG << "[KEYBOARD] Failed to open keyboard device, code: " << this->handle;
        return false;
    }

    this->mapping = mapping;

    return true; // we're done here.
}

int Keyboard::Update()
{
    int rc = sceKeyboardRead(this->handle, this->inputData, sizeof(this->inputData) / sizeof(OrbisKeyboardData));
    return rc;
}

bool Keyboard::CheckLED(int led, int num)
{
    if (num < 0 || num >= ORBIS_KEYBOARD_MAX_DATA_NUM) return false;
    return this->inputData[num].led & led;
}

bool Keyboard::CheckModifierKey(int key, int num)
{
    if (num < 0 || num >= ORBIS_KEYBOARD_MAX_DATA_NUM) return false;
    return this->inputData[num].modifierKeys & key;
}

bool Keyboard::IsConnected(int num)
{
    if (num < 0 || num >= ORBIS_KEYBOARD_MAX_DATA_NUM) return false;
    return this->inputData[num].isConnected;
}

uint64_t Keyboard::GetTimestamp(int num)
{
    if (num < 0 || num >= ORBIS_KEYBOARD_MAX_DATA_NUM) return 0;
    return this->inputData[num].timestamp;
}

int32_t Keyboard::GetLength(int num)
{
    if (num < 0 || num >= ORBIS_KEYBOARD_MAX_DATA_NUM) return -1;
    return this->inputData[num].pressedKeysLen;
}

bool Keyboard::CheckKeycode(unsigned short keyCode, int num)
{
    if (num < 0 || num >= ORBIS_KEYBOARD_MAX_DATA_NUM) return false;

    auto data = this->inputData[num];
    for (int i = 0; i < data.pressedKeysLen; i++)
    {
        uint16_t code = data.keyCode[i];
        if (code == keyCode) return true;
    }

    return false;
}

uint16_t Keyboard::GetKeycode(int index, int num)
{
    if (num < 0 || num >= ORBIS_KEYBOARD_MAX_DATA_NUM) return 0;
    return this->inputData[num].keyCode[index];
}

uint16_t Keyboard::KeyToChar(uint16_t keyCode, int num)
{
    if (num < 0 || num >= ORBIS_KEYBOARD_MAX_DATA_NUM) return 0;

    int rc;
    OrbisKeyboardCharData data;
    rc = sceKeyboardGetKey2Char(this->handle, this->mapping, this->inputData[num].led, this->inputData[num].modifierKeys, keyCode, &data);

    if (rc != ORBIS_OK)
    {
        DEBUGLOG << "[KEYBOARD] Error when converting keycode to char, code: " << rc;
        return 0;
    }

    if (!data.coversionOk)
    {
        return 0;
    }

    return data.unicodeChar;
}
