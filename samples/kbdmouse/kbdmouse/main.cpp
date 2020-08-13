#include <stdio.h>
#include "mouse.h"
#include "keyboard.h"
#include <orbis/KeyboardCodes.h>
#include "../../_common/log.h"
#include "../../_common/graphics.h"

// Dimensions
#define FRAME_WIDTH     1920
#define FRAME_HEIGHT    1080
#define FRAME_DEPTH        4

// Font information
#define FONT_SIZE         32

// Logging
std::stringstream debugLogStream;

const char *boolToString(bool v) { return v ? "True" : "False"; }

void drawMouseState(Mouse *obj, Scene2D *scene, FT_Face font, Color fgColor, Color bgColor)
{
    int rc = obj->Update();

    std::stringstream drawStream;

    if (rc < 0)
    {
        drawStream << "Couldn't update button data! Error: " << rc << std::endl;
    }
    else
    {
        drawStream << "Mouse Test:" << std::endl;
        drawStream << "Data Timestamp: " << obj->GetTimestamp() << std::endl;
        drawStream << "Is Connected? " << boolToString(obj->IsConnected()) << std::endl;
        drawStream << "X Axis: " << obj->GetXAxis() << std::endl;
        drawStream << "Y Axis: " << obj->GetYAxis() << std::endl;
        drawStream << "Wheel: " << obj->GetWheel() << std::endl;
        drawStream << "Horizontal wheel: " << obj->GetMTilt() << std::endl;
        drawStream << "Is input intercepted by Orbis OS? " << boolToString(obj->CheckButton(ORBIS_MOUSE_BUTTON_INTERCEPTED)) << std::endl;
        drawStream << "Buttons:" << std::endl;

        drawStream << "Left: " << boolToString(obj->CheckButton(ORBIS_MOUSE_BUTTON_LEFT)) << std::endl;
        drawStream << "Right: " << boolToString(obj->CheckButton(ORBIS_MOUSE_BUTTON_RIGHT)) << std::endl;
        drawStream << "Wheel click: " << boolToString(obj->CheckButton(ORBIS_MOUSE_BUTTON_WHEEL)) << std::endl;

        // additional "gamer" buttons.
        drawStream << "X1: " << boolToString(obj->CheckButton(ORBIS_MOUSE_BUTTON_X1)) << std::endl;
        drawStream << "X2: " << boolToString(obj->CheckButton(ORBIS_MOUSE_BUTTON_X2)) << std::endl;
    }

    scene->DrawText((char *)drawStream.str().c_str(), font, 920, 128, bgColor, fgColor);
    drawStream.clear();
}

void drawKeyboardState(Keyboard *obj, Scene2D *scene, FT_Face font, Color fgColor, Color bgColor)
{
    obj->Update(); // update keyboard state...

    std::stringstream drawStream;

    drawStream << "Keyboard Test:" << std::endl;
    drawStream << "Data Timestamp: " << obj->GetTimestamp() << std::endl;
    drawStream << "Is Connected?   " << boolToString(obj->IsConnected()) << std::endl;

    drawStream << "Num Lock LED:    " << boolToString(obj->CheckLED(ORBIS_KEYBOARD_LED_NUM_LOCK)) << std::endl;
    drawStream << "Caps Lock LED:   " << boolToString(obj->CheckLED(ORBIS_KEYBOARD_LED_CAPS_LOCK)) << std::endl;
    drawStream << "Scroll Lock LED: " << boolToString(obj->CheckLED(ORBIS_KEYBOARD_LED_SCROLL_LOCK)) << std::endl << std::endl;

    drawStream << "LWin key:     " << boolToString(obj->CheckModifierKey(ORBIS_KEYBOARD_MKEY_L_WIN)) << std::endl;
    drawStream << "LControl key: " << boolToString(obj->CheckModifierKey(ORBIS_KEYBOARD_MKEY_L_CTRL)) << std::endl;
    drawStream << "LAlt key:     " << boolToString(obj->CheckModifierKey(ORBIS_KEYBOARD_MKEY_L_ALT)) << std::endl;

    drawStream << "Held Keys (limited by rollover):" << std::endl << std::endl;

    int len = obj->GetLength();
    for (int i = 0; i < len; i++)
    {
        unsigned short keyCode = obj->GetKeycode(i);
        char keyChar = obj->KeyToChar(keyCode);
        std::string keyStr("cannot represent or null");

        if (keyChar != 0) keyStr = keyChar;

        drawStream << "Keycode[" << i << "]: 0x" << std::hex << static_cast<signed int>(static_cast<signed short>(keyCode)) << " (as char: '" << keyStr << "')";
        drawStream << std::endl;
    }

    scene->DrawText((char *)drawStream.str().c_str(), font, 64, 128, bgColor, fgColor);
    drawStream.clear();
}

int main()
{
    // No buffering
    setvbuf(stdout, NULL, _IONBF, 0);

    // Create a 2D scene
    DEBUGLOG << "Creating a scene";

    auto scene = new Scene2D(FRAME_WIDTH, FRAME_HEIGHT, FRAME_DEPTH);

    if (!scene->Init(0xC000000, 2))
    {
        DEBUGLOG << "Failed to initialize 2D scene";
        for(;;);
    }

    // Set colors
    Color bgColor = { 0, 0, 0 };       // Black
    Color fgColor = { 255, 255, 255 }; // White

    int frameID = 0;

    // Initialize the font faces with arial (must be included in the package root!)

    DEBUGLOG << "Initializing font";

    FT_Face Font;
    if (!scene->InitFont(&Font, "/app0/Gontserrat-Regular.ttf", FONT_SIZE))
    {
        DEBUGLOG << "Failed to initialize font";
        for(;;);
    }

    // Initialize keyboard and mouse libraries.

    DEBUGLOG << "Initializing Keyboard...";
	
	auto keyboard = new Keyboard();
	if (!keyboard->Init(-1, 0, ORBIS_KEYBOARD_MAPPING_101))
	{
		DEBUGLOG << "Failed to initialize keyboard!";
		for(;;);
	}

    DEBUGLOG << "Initializing Mouse...";

    auto mouse = new Mouse();
    if (!mouse->Init(-1, 0, ORBIS_MOUSE_OPEN_PARAM_NORMAL))
    {
        DEBUGLOG << "Failed to initialize mouse!";
        for(;;);
    }

    DEBUGLOG << "Entering draw loop...";

    // Draw loop
    for (;;)
    {
        // Clean the framebuffer.
        scene->FrameBufferFill(bgColor);

        // Draw keyboard state.
        drawKeyboardState(keyboard, scene, Font, fgColor, bgColor);

        // Draw mouse state.
        drawMouseState(mouse, scene, Font, fgColor, bgColor);

        // Submit the frame buffer
        scene->SubmitFlip(frameID);
        scene->FrameWait(frameID);

        // Swap to the next buffer
        scene->FrameBufferSwap();
        frameID++;
    }

    return 0;
}
