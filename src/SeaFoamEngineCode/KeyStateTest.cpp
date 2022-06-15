#include "KeyStateTest.h"

KeyStateTest::KeyStateTest(AZUL_KEY k)
	:key(k), curState(PressState::CURRENTLY_RELEASED)
{
}

void KeyStateTest::TestKey()
{

	if(Keyboard::GetKeyState(key))
	{
		if (curState == PressState::CURRENTLY_RELEASED)
		{
			DebugMsg::out("Key Pressed\n");
			curState = PressState::CURRENTLY_PRESSED;
		}
	}
	else
	{
		if (curState == PressState::CURRENTLY_PRESSED)
		{
			DebugMsg::out("Key Released\n");
			curState = PressState::CURRENTLY_RELEASED;
		}
	}



}
