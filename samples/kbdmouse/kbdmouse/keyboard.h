
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <orbis/Keyboard.h>

class Keyboard
{
	int handle;
	int userID;
	OrbisKeyboardMapType mapping;

	OrbisKeyboardData inputData[ORBIS_KEYBOARD_MAX_DATA_NUM];

public:
	~Keyboard();

	bool Init(int kbdUserID, int index, OrbisKeyboardMapType mapping);
	int Update();
	bool CheckKeycode(unsigned short keyCode, int num = 0);
	uint16_t GetKeycode(int index, int num = 0);
	bool CheckLED(int led, int num = 0);
	bool CheckModifierKey(int key, int num = 0);
	bool IsConnected(int num = 0);
	uint64_t GetTimestamp(int num = 0);
	int32_t GetLength(int num = 0);
	uint16_t KeyToChar(uint16_t keyCode, int num = 0);
};

#endif // !KEYBOARD_H
