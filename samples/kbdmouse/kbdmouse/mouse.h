#ifndef MOUSE_H
#define MOUSE_H

#include <orbis/_types/mouse.h>

class Mouse
{
private:
    int handle;
    int userID;
    OrbisMouseData inputData[ORBIS_MOUSE_MAX_DATA_NUM];

public:
    ~Mouse();

    bool Init(int userID, int mouseId, unsigned char param = ORBIS_MOUSE_OPEN_PARAM_NORMAL);
    int Update(); // get 64 mouse states for mouse `mouseId`.

    // num = input state index.
    bool IsConnected(int num = 0);
    bool CheckButton(int button, int num = 0);

    int GetXAxis(int num = 0);
    int GetYAxis(int num = 0);

    int GetWheel(int num = 0);
    int GetMTilt(int num = 0); // only for weird mouses with a horizontal-scrolling wheel.

    unsigned long GetTimestamp(int num = 0);
};

#endif // !MOUSE_H
