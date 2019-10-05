#include "Unit.h"
#include "Player.h"

#include <Windows.h>


void Unit::Select(Player* player)
{
	typedef void(__thiscall * SelectUnit)(int32_t player, int32_t unit, int zeroOne);
	static SelectUnit selectUnit = (SelectUnit)((DWORD)GetModuleHandle(NULL) + 0x354A20);
	selectUnit((int32_t)player, (int32_t)this, 1);
}


void Unit::MoveTo(Vector2 pos, bool deselectAfterMove)
{
	typedef void(__thiscall * MoveUnit)(int32_t player, int32_t unit, float x, float y);
	static MoveUnit moveUnit = (MoveUnit)((DWORD)GetModuleHandle(NULL) + 0x33EBA0);

	Select(this->pOwner);
	moveUnit((int32_t)this->pOwner, NULL, pos.x, pos.y);

	if (deselectAfterMove)
	{
		INPUT ip;
		// Set up a generic keyboard event.
		ip.type = INPUT_KEYBOARD;
		ip.ki.wScan = 0; // hardware scan code for key
		ip.ki.time = 0;
		ip.ki.dwExtraInfo = 0;

		// Press ESC
		ip.ki.wVk = VK_ESCAPE; // virtual-key code for the "6" key
		ip.ki.dwFlags = 0; // 0 for key press
		SendInput(1, &ip, sizeof(INPUT));

		// Release ESC
		ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
		SendInput(1, &ip, sizeof(INPUT));
	}
}