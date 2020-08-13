#include <orbis/UserService.h>
#include <orbis/Sysmodule.h>
#include <orbis/Sysmodules.h>
#include "mouse.h"
#include "../../_common/log.h"
#include <orbis/Mouse.h>

Mouse::~Mouse()
{
    DEBUGLOG << "[MOUSE] Freeing...";
    sceMouseClose(this->handle);
    sceSysmoduleUnloadModule(ORBIS_SYSMODULE_MOUSE);
}

bool Mouse::Init(int userID, int mouseId, unsigned char param)
{
    // Load sceMouse sysmodule.

    int rc = sceSysmoduleLoadModule(ORBIS_SYSMODULE_MOUSE);

    if (rc < 0)
    {
        DEBUGLOG << "[MOUSE] Could not load sceMouse";
        return false;
    }

    // Initialize sceMouse library.

    if (sceMouseInit() != ORBIS_OK)
    {
        DEBUGLOG << "[MOUSE] Failed to initialize sceMouse";
        return false;
    }

    if (userID < 0)
    {
        OrbisUserServiceInitializeParams param;
        param.priority = ORBIS_KERNEL_PRIO_FIFO_LOWEST;
        sceUserServiceInitialize(&param);
        sceUserServiceGetInitialUser(&this->userID);
    }
    else
    {
        this->userID = userID;
    }

    // Open a mouse handle.
    OrbisMouseOpenParam openparam;
    openparam.behavior = param; // "normal" or "merged"
    this->handle = sceMouseOpen(this->userID, ORBIS_MOUSE_PORT_TYPE_MAIN, mouseId, &openparam);

    if (this->handle < 0)
    {
        DEBUGLOG << "[MOUSE] Failed to open mouse handle.";
        return false;
    }

    return true;
}

int Mouse::Update()
{
    int rc = sceMouseRead(this->handle, this->inputData, sizeof(this->inputData) / sizeof(OrbisMouseData));
    // read 64 input states into a buffer.

    return rc;
}

bool Mouse::IsConnected(int num)
{
    if (num >= ORBIS_MOUSE_MAX_DATA_NUM || num < 0) return false;
    return this->inputData[num].connected;
}

bool Mouse::CheckButton(int button, int num)
{
    if (num >= ORBIS_MOUSE_MAX_DATA_NUM || num < 0) return false;
    return this->inputData[num].buttons & button;
}

int Mouse::GetXAxis(int num)
{
    if (num >= ORBIS_MOUSE_MAX_DATA_NUM || num < 0) return -1;
    return this->inputData[num].xAxis;
}

int Mouse::GetYAxis(int num)
{
    if (num >= ORBIS_MOUSE_MAX_DATA_NUM || num < 0) return -1;
    return this->inputData[num].yAxis;
}

int Mouse::GetMTilt(int num)
{
    if (num >= ORBIS_MOUSE_MAX_DATA_NUM || num < 0) return -1;
    return this->inputData[num].tilt;
}

int Mouse::GetWheel(int num)
{
    if (num >= ORBIS_MOUSE_MAX_DATA_NUM || num < 0) return -1;
    return this->inputData[num].wheel;
}

uint64_t Mouse::GetTimestamp(int num)
{
    if (num >= ORBIS_MOUSE_MAX_DATA_NUM || num < 0) return 0;
    return this->inputData[num].timestamp;
}
